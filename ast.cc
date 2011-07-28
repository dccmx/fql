#include "ast.h"
#include "sys.h"

Select::~Select() {
  delete attrs_;
  delete folders_;
}

Table *Select::Execute() {
  Table *tb = new Table(*attrs_);
  if (folders_ == NULL) {
    ListDir(tb, ".");
    return tb;
  }

  for (vector<string>::const_iterator fi = folders_->begin(); fi != folders_->end(); ++fi) {
    ListDir(tb, *fi);
    return tb;
  }
  return NULL;
}

