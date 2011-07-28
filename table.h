#ifndef TABLE_H_
#define TABLE_H_

#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>

#include "variant.h"

using std::vector;
using std::string;

typedef vector<Variant*> Row;

class Table {
 public:
  Table(const vector<string>& header) : header_(header) {}
  ~Table();

 public:
  const vector<string>& Header() { return header_; }
  void Append(Row row) { rows_.push_back(row); }

  void Print(bool head = false);

 private:
  vector<string> header_;
  vector<Row> rows_;
};

#endif // TABLE_H_
