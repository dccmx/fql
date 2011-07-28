#include <stdio.h>
#include <string.h>

#include "table.h"

Table::~Table() {
  for (vector<Row>::const_iterator ri = rows_.begin(); ri != rows_.end(); ++ri) {
    for (vector<Variant*>::const_iterator ci = ri->begin(); ci != ri->end(); ++ci) {
      delete (*ci);
    }
  }
}

void Table::Print() {
  for (vector<string>::const_iterator hi = header_.begin(); hi != header_.end(); ++hi) {
    printf("%-15s", hi->c_str());
  }

  printf("\n");

  for (vector<Row>::const_iterator ri = rows_.begin(); ri != rows_.end(); ++ri) {
    for (vector<Variant*>::const_iterator ci = ri->begin(); ci != ri->end(); ++ci) {
      printf("%-15s", (*ci)->c_str());
    }
    printf("\n");
  }
}
