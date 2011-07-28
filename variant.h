#ifndef VARIANT_H_
#define VARIANT_H_

#include <stdio.h>
#include <stdint.h>
#include <string>
#include <time.h>

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

class UInt32 : public Variant {
 public:
  UInt32(off_t value) : value_(value) { sprintf(value_str_, "%u", value_); }
  const char *c_str() { return value_str_; }
 private:
  uint32_t value_;
  char value_str_[15];
};

class Time : public Variant {
 public:
  Time(time_t value);
  const char *c_str() { return value_str_; }
 private:
  time_t value_;
  char value_str_[25];
};

#endif // VARIANT_H_
