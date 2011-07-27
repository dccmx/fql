#include "ast.h"
#include "sys.h"

Table *Stmt::Execute() {
  if (select_) return select_->Execute();
  return NULL;
}

Table *Select::Execute() {
  Table *tb = new Table(*attrs_);
  for (vector<string>::const_iterator fi = folders_->begin(); fi != folders_->end(); ++fi) {
    ListDir(tb, *fi);
    return tb;
  }
  return NULL;
}

