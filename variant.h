#ifndef VARIANT_H_
#define VARIANT_H_

#include <stdio.h>
#include <stdint.h>
#include <string>

using std::string;

class Variant {
 public:
  virtual ~Variant() = 0;
  virtual const char *c_str() = 0;
};

class String : public Variant {
 public:
  String(const char *str) : value_(str) {}
  const char *c_str() { return value_.c_str(); }
 private:
  string value_;
};

class Size : public Variant {
 public:
  Size(off_t size) : value_(size) { sprintf(value_str_, "%u", value_); }
  const char *c_str() { return value_str_; }
 private:
  uint32_t value_;
  char value_str_[15];
};

#endif // VARIANT_H_
