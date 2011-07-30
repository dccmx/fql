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
  virtual Variant *Clone() = 0;
  virtual int Compare(Variant *other) = 0;
  virtual Variant *Plus(Variant *other) = 0;
  virtual Variant *Minus(Variant *other) = 0;
  virtual Variant *Multiply(Variant *other) = 0;
  virtual Variant *Divide(Variant *other) = 0;
  virtual Variant *Mod(Variant *other) = 0;
  virtual Variant *Not() = 0;
  virtual Variant *And(Variant *other) = 0;
  virtual Variant *Or(Variant *other) = 0;
  virtual bool c_bool() = 0;
};

class String : public Variant {
 public:
  String(const char *str) : value_(str) {}
  const char *c_str() { return value_.c_str(); }
  Variant *Clone() { return new String(value_.c_str()); };

  int Compare(Variant *other) {
    String *o = dynamic_cast<String*>(other);
    if (o) {
      return strcasecmp(value_.c_str(), o->value_.c_str());
    } else {
      return strcasecmp(c_str(), o->c_str());
    }
  }

  Variant *Plus(Variant *other) = 0;
  Variant *Minus(Variant *other) = 0;
  Variant *Multiply(Variant *other) = 0;
  Variant *Divide(Variant *other) = 0;
  Variant *Mod(Variant *other) = 0;
  Variant *Not() = 0;
  Variant *And(Variant *other) = 0;
  Variant *Or(Variant *other) = 0;
  bool c_bool() = 0;

 private:
  string value_;
};

class UInt32 : public Variant {
 public:
  UInt32(off_t value) : value_(value) { sprintf(value_str_, "%u", value_); }
  const char *c_str() { return value_str_; }
  Variant *Clone() { return new UInt32(value_); };

  int Compare(Variant *other) {
    UInt32 *o = dynamic_cast<UInt32*>(other);
    if (o) {
      return value_ - o->value_;
    } else {
      return strcasecmp(c_str(), o->c_str());
    }
  }

  Variant *Plus(Variant *other) = 0;
  Variant *Minus(Variant *other) = 0;
  Variant *Multiply(Variant *other) = 0;
  Variant *Divide(Variant *other) = 0;
  Variant *Mod(Variant *other) = 0;
  Variant *Not() = 0;
  Variant *And(Variant *other) = 0;
  Variant *Or(Variant *other) = 0;
  bool c_bool() = 0;

 private:
  uint32_t value_;
  char value_str_[15];
};

class Time : public Variant {
 public:
  Time(time_t value);
  const char *c_str() { return value_str_; }
  Variant *Clone() { return new Time(value_); };

  int Compare(Variant *other) {
    Time *o = dynamic_cast<Time*>(other);
    if (o) {
      return value_ - o->value_;
    } else {
      return strcasecmp(c_str(), o->c_str());
    }
    return 0;
  }

  Variant *Plus(Variant *other) = 0;
  Variant *Minus(Variant *other) = 0;
  Variant *Multiply(Variant *other) = 0;
  Variant *Divide(Variant *other) = 0;
  Variant *Mod(Variant *other) = 0;
  Variant *Not() = 0;
  Variant *And(Variant *other) = 0;
  Variant *Or(Variant *other) = 0;
  bool c_bool() = 0;

 private:
  time_t value_;
  char value_str_[25];
};

class Permission : public Variant {
 public:
  Permission(uint32_t value);
  const char *c_str() { return value_str_; }
  Variant *Clone() { return new Permission(value_); };

  int Compare(Variant *other) {
    Permission *o = dynamic_cast<Permission*>(other);
    if (o) {
      return value_ - o->value_;
    } else {
      return strcasecmp(c_str(), o->c_str());
    }
  }

  Variant *Plus(Variant *other) = 0;
  Variant *Minus(Variant *other) = 0;
  Variant *Multiply(Variant *other) = 0;
  Variant *Divide(Variant *other) = 0;
  Variant *Mod(Variant *other) = 0;
  Variant *Not() = 0;
  Variant *And(Variant *other) = 0;
  Variant *Or(Variant *other) = 0;
  bool c_bool() = 0;

 private:
  uint32_t value_;
  char value_str_[10];
};

class Bool : public Variant {
 public:
  Bool(bool value) : value_(value) { sprintf(value_str_, value? "True" : "False");}
  const char *c_str() { return value_str_; }
  Variant *Clone() { return new Bool(value_); };

  int Compare(Variant *other) {
    Bool *o = dynamic_cast<Bool*>(other);
    if (o) {
      return (value_? 1 : 0) - (o->value_? 1 : 0);
    } else {
      return strcasecmp(c_str(), o->c_str());
    }
  }

  Variant *Plus(Variant *other) = 0;
  Variant *Minus(Variant *other) = 0;
  Variant *Multiply(Variant *other) = 0;
  Variant *Divide(Variant *other) = 0;
  Variant *Mod(Variant *other) = 0;
  Variant *Not() = 0;
  Variant *And(Variant *other) = 0;
  Variant *Or(Variant *other) = 0;
  bool c_bool() { return value_; }

 private:
  bool value_;
  char value_str_[6];
};
#endif // VARIANT_H_
