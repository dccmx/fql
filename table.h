#ifndef TABLE_H_
#define TABLE_H_

#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>

#include "variant.h"

using std::vector;
using std::string;

class Table;
class Select;
struct OrderList;

const vector<string>& FullHeader();

class Row {
  friend class Table;
 public:
  Row() {};
  Row(const Row& other);
  ~Row();

  const Row& operator=(const Row& other);

  Variant *operator[](int index) { return row_[index]; }
  void push_back(Variant *v) { row_.push_back(v); }
  vector<Variant*>::iterator begin() { return row_.begin(); }
  vector<Variant*>::iterator end() { return row_.end(); }

  void set_header(vector<string> *header) { header_ = header; }

  Variant *get(const string& name) const {
    for (size_t i = 0; i < FullHeader().size(); i ++) {
      if (FullHeader()[i] == name) return row_[i];
    }
    return NULL;
  }

 private:
  vector<Variant*> row_;
  vector<string> *header_;
};

class Table {
  friend class Select;
 public:
  Table(const vector<string>& header) : header_(header) {}

  static vector<string> *FullHeader();

 public:
  const vector<string>& Header() { return header_; }
  void Append(Row row) { row.header_ = &header_; rows_.push_back(row); }

  void Sort(OrderList *orders);
  void Print(bool head = false);

 private:
  vector<string> header_;
  vector<Row> rows_;
};

#endif // TABLE_H_
