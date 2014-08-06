#include "parser.h"
#include "ast.h"
#include "sys.h"

Select::~Select() {
  delete attrs_;
  delete folder_;
  delete where_;
  delete orders_;
  delete limit_;
}

Table *Select::SelectDir(const string& dir, bool recursive) {
  Table *tb = new Table(*attrs_);

  ListDir(tb, dir, recursive);
  if (orders_) tb->Sort(orders_);

  vector<Row> rows;
  for (uint32_t i = 0; i < tb->rows_.size(); i++) {
    if (where_) {
      Variant *v = where_->Evaluate(&tb->rows_[i]);
      bool valid = v && v->c_bool();
      if (v) delete v;
      if (!valid) continue;
    }
    rows.push_back(Row(tb->rows_[i]));
  }
  tb->rows_ = rows;

  if (!tb->rows_.size()) {
    printf("no files conform to where \"blabla..\" \n");
    return tb;
  }
  rows.clear();

  uint32_t start = limit_->start;
  uint32_t limit = (limit_->limit == -1)? tb->rows_.size() : limit_->limit;
  for (uint32_t i = start; i < start + limit && i < tb->rows_.size(); i++) {
    rows.push_back(Row(tb->rows_[i]));
  }
  tb->rows_ = rows;

  if (!tb->rows_.size()) {
    printf("no files conform to limit \"blabla..\" \n");
  }

  return tb;
}
Table *Select::Execute() {
  if (folder_ == NULL) {
    return SelectDir(".", true);
  }

  return SelectDir(folder_->name, folder_->recursive);
}
