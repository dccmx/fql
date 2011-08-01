#include "parser.h"
#include "ast.h"
#include "sys.h"

Select::~Select() {
  delete attrs_;
  delete folders_;
}

Table *Select::SelectDir(const string& dir) {
  Table *tb = new Table(*attrs_);

  ListDir(tb, ".");
  if (orders_) tb->Sort(orders_);

  vector<Row> rows;
  for (uint32_t i = 0; i < tb->rows_.size(); i++) {
    if (where_) {
      Variant *v = where_->Evaluate(&tb->rows_[i]);
      if (!v || !v->c_bool()) continue;
    }
    rows.push_back(Row(tb->rows_[i]));
  }
  tb->rows_ = rows;

  rows.clear();
  uint32_t start = limit_->start;
  uint32_t limit = (limit_->limit == -1)? tb->rows_.size() : limit_->limit;
  for (uint32_t i = start; i < start + limit && i < tb->rows_.size(); i++) {
    rows.push_back(Row(tb->rows_[i]));
  }
  tb->rows_ = rows;

  return tb;
}
Table *Select::Execute() {
  if (folders_ == NULL) {
    return SelectDir(".");
  }

  return SelectDir(*folders_->begin());
}

