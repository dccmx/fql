#include <stdio.h>
#include <string.h>
#include <algorithm>

#include "table.h"
#include "ast.h"
#include "parser.h"

using std::sort;

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
  row_.clear();
  for (vector<Variant*>::const_iterator ci = other.row_.begin(); ci != other.row_.end(); ++ci) {
    row_.push_back((*ci)->Clone());
  }
  return *this;
}

void Table::Print(bool head) {
  if (head) {
    for (vector<string>::iterator hi = header_.begin(); hi != header_.end(); ++hi) {
      printf("%-15s ", hi->c_str());
    }
    printf("\n");
  }

  for (vector<Row>::iterator ri = rows_.begin(); ri != rows_.end(); ++ri) {
    for (vector<Variant*>::iterator ci = ri->begin(); ci != ri->end(); ++ci) {
      printf("%-15s ", (*ci)->c_str());
    }
    printf("\n");
  }
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
