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
  uint32_t start = limit_->start;
  uint32_t limit = (limit_->limit == -1)? tb->rows_.size() : limit_->limit;
  for (uint32_t i = start; i < start + limit && i < tb->rows_.size(); i++) {
    if (where_) {
      Variant *v = where_->Evaluate(&tb->rows_[i]);
      if (!v || !v->c_bool()) continue;
    }
    rows.push_back(Row(tb->rows_[i]));
  }
  tb->rows_ = rows;

  return tb;
}
Table *Select::Execute() {
  if (where_ != NULL) {
    where_->Print();
  }

  if (folders_ == NULL) {
    return SelectDir(".");
  }

  return SelectDir(*folders_->begin());
}

#define PREPARE_PARAM  \
  if (left_) left = left_->Evaluate(row); \
  if (right_) right = right_->Evaluate(row);
#define BINARY_OP(OP) do { \
  PREPARE_PARAM \
  if (left && right) { \
    ret = left->OP(right); \
  }\
} while (0)

#define LOGIC_OP(OP) do { \
  PREPARE_PARAM \
  if (left && right) { \
    ret = new Bool(left->OP(right)); \
  }\
} while (0)

#define COMPARE_OP(OP) do {\
  PREPARE_PARAM \
  if (left && right) { \
    ret = new Bool(left->Compare(right) OP 0); \
  }\
} while (0)

Variant *Expr::Evaluate(Row *row) {
  if (is_attr_) value_ = row->get(value_->c_str())->Clone();
  if (value_) return value_;

  Variant *ret = NULL;
  Variant *left = NULL;
  Variant *right = NULL;

  switch (op_) {
    case TK_PLUS:
      BINARY_OP(Plus);
      break;
    case TK_MINUS:
      BINARY_OP(Minus);
      break;
    case TK_DIV:
      BINARY_OP(Div);
      break;
    case TK_MOD:
      BINARY_OP(Mod);
      break;
    case TK_STAR:
      BINARY_OP(Mult);
      break;
    case TK_OR:
      LOGIC_OP(Or);
      break;
    case TK_AND:
      LOGIC_OP(And);
      break;
    case TK_GT:
      COMPARE_OP(>);
      break;
    case TK_LT:
      COMPARE_OP(<);
      break;
    case TK_EQ:
      COMPARE_OP(==);
      break;
    case TK_GE:
      COMPARE_OP(>=);
      break;
    case TK_LE:
      COMPARE_OP(<=);
      break;
    case TK_NE:
      COMPARE_OP(<=);
      break;
    case TK_NOT:
      PREPARE_PARAM;
      if (right) {
        ret = new Bool(!right->c_bool());
      }
      break;
    case TK_LIKE:
      PREPARE_PARAM;
      if (right) {
        ret = new Bool(!right->c_bool());
      }
      break;
    default:
      break;
  }
  return ret;
}

void Expr::Print() {
  if (is_attr_) printf("%s\n", value_->c_str());
  printf("(%d, ", op_);
  if (left_) left_->Print();
  printf(", ");
  if (right_) right_->Print();
  printf(")\n");
}
