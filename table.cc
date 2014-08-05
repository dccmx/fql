#include <stdio.h>
#include <string.h>
#include <algorithm>

#include "table.h"
#include "ast.h"
#include "parser.h"

using std::sort;
using std::max;

Row::Row(const Row& other) {
  header_ = other.header_;
  for (vector<Variant*>::const_iterator ci = other.row_.begin(); ci != other.row_.end(); ++ci) {
    row_.push_back((*ci)->Clone());
  }
}

Row::~Row() {
  for (vector<Variant*>::iterator ci = row_.begin(); ci != row_.end(); ++ci) {
    delete (*ci);
  }
}

const Row& Row::operator=(const Row& other) {
  header_ = other.header_;

  for (vector<Variant*>::iterator ci = row_.begin(); ci != row_.end(); ++ci) {
    delete (*ci);
  }
  row_.clear();

  for (vector<Variant*>::const_iterator ci = other.row_.begin(); ci != other.row_.end(); ++ci) {
    row_.push_back((*ci)->Clone());
  }
  return *this;
}

void Table::Print(bool head) {
  if (head) {
    for (vector<string>::iterator hi = header_.begin(); hi != header_.end(); ++hi) {
      printf("%s ", hi->c_str());
    }
    printf("\n");
  }

  int *width = new int[header_.size()];

  for (uint32_t i = 0; i < header_.size(); i++) {
    width[i] = 1;
    for (vector<Row>::iterator ri = rows_.begin(); ri != rows_.end(); ++ri) {
      Variant *str = ri->get(header_[i]); 
      if (str) {
        int len = strlen(str->c_str());
        width[i] = max(len, width[i]);
      } else {
        printf("%s is not found\n", header_[i].c_str());
        return;
      }
    }
  }

  width[header_.size() - 1] = -1;

  for (vector<Row>::iterator ri = rows_.begin(); ri != rows_.end(); ++ri) {
    for (uint32_t i = 0; i < header_.size(); i++) {
      char fmt[10];
      sprintf(fmt, "%%%ds ", width[i]);
      printf(fmt, ri->get(header_[i])->c_str());
    }
    printf("\n");
  }

  delete[] width;
}

class RowCompare {
 public:
  RowCompare(OrderList *orders) : orders_(orders) {}

  bool operator()(const Row& lhs, const Row& rhs) {
    for (uint32_t i = 0; i < orders_->attrs.size(); i++) {
      int c = lhs.get(orders_->attrs[i])->Compare(rhs.get(orders_->attrs[i]));
      if (c < 0 ) return orders_->dirs[i] == TK_ASC;
      if (c > 0 ) return orders_->dirs[i] == TK_DESC;
    }
    return false;
  }

 private:
  OrderList *orders_;
};

void Table::Sort(OrderList *orders) {
  sort(rows_.begin(), rows_.end(), RowCompare(orders));
}

static vector<string> full_header_;

const vector<string>& FullHeader() {
  if (full_header_.size() != 0 ) return full_header_;
  full_header_.push_back(string("name"));
  full_header_.push_back(string("path"));
  full_header_.push_back(string("perms"));
  full_header_.push_back(string("tperms"));
  full_header_.push_back(string("nlink"));
  full_header_.push_back(string("size"));
  full_header_.push_back(string("inode"));
  full_header_.push_back(string("uid"));
  full_header_.push_back(string("gid"));
  full_header_.push_back(string("uname"));
  full_header_.push_back(string("gname"));
  full_header_.push_back(string("time"));
  full_header_.push_back(string("atime"));
  full_header_.push_back(string("mtime"));
  full_header_.push_back(string("ctime"));
  return full_header_;
}

