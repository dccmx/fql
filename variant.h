#ifndef VARIANT_H_
#define VARIANT_H_

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <time.h>

using std::string;

class Variant {
 public:
  virtual ~Variant() = 0;
  virtual const char *c_str() = 0;
  virtual int Compare(Variant *other) = 0;
};

class String : public Variant {
 public:
  String(const char *str) : value_(str) {}
  const char *c_str() { return value_.c_str(); }

  int Compare(Variant *other) {
    String *o = dynamic_cast<String*>(other);
    if (o) {
      return strcasecmp(value_.c_str(), o->value_.c_str());
    } else {
      return strcasecmp(c_str(), o->c_str());
    }
  }
 private:
  string value_;
};

class UInt32 : public Variant {
 public:
  UInt32(off_t value) : value_(value) { sprintf(value_str_, "%u", value_); }
  const char *c_str() { return value_str_; }

  int Compare(Variant *other) {
    UInt32 *o = dynamic_cast<UInt32*>(other);
    if (o) {
      return value_ - o->value_;
    } else {
      return strcasecmp(c_str(), o->c_str());
    }
  }
 private:
  uint32_t value_;
  char value_str_[15];
};

class Time : public Variant {
 public:
  Time(time_t value);
  const char *c_str() { return value_str_; }

  int Compare(Variant *other) {
    Time *o = dynamic_cast<Time*>(other);
    if (o) {
      return value_ - o->value_;
    } else {
      return strcasecmp(c_str(), o->c_str());
    }
    return 0;
  }
 private:
  time_t value_;
  char value_str_[25];
};

class Permission : public Variant {
 public:
  Permission(uint32_t value);
  const char *c_str() { return value_str_; }

  int Compare(Variant *other) {
    Permission *o = dynamic_cast<Permission*>(other);
    if (o) {
      return value_ - o->value_;
    } else {
      return strcasecmp(c_str(), o->c_str());
    }
  }
 private:
  uint32_t value_;
  char value_str_[10];
};

#endif // VARIANT_H_
