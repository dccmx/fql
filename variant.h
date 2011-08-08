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
  virtual bool c_bool() = 0;
  virtual Variant *Clone() = 0;
  virtual int Compare(Variant *other) = 0;

  virtual Variant *Plus(Variant *other) { return NULL; }
  virtual Variant *Minus(Variant *other) { return NULL; }
  virtual Variant *Mult(Variant *other)  { return NULL; }
  virtual Variant *Div(Variant *other)  { return NULL; }
  virtual Variant *Mod(Variant *other)  { return NULL; }
  virtual bool Not()  { return !c_bool(); }
  virtual bool And(Variant *other)  { return c_bool() && other->c_bool(); }
  virtual bool Or(Variant *other)  { return c_bool() || other->c_bool(); }
};

class String : public Variant {
 public:
  String(const char *str) : value_(str) {}
  String(const string& value) : value_(value) {}
  const char *c_str() { return value_.c_str(); }
  Variant *Clone() { return new String(value_.c_str()); };

  int Compare(Variant *other) {
    return strcasecmp(c_str(), other->c_str());
  }

  Variant *Plus(Variant *other) {
    String *o = dynamic_cast<String*>(other);
    if (o) {
      return new String(value_ + o->value_);
    } else {
      string v = value_;
      v += o->c_str();
      return new String(v);
    }
  }

  bool c_bool() {
    return value_ != "";
  }

 protected:
  string value_;
};

class Int32 : public Variant {
 public:
  Int32(off_t value = 0) : value_(value) { sprintf(value_str_, "%d", value_); }
  int32_t value() { return value_; }
  const char *c_str() { return value_str_; }
  bool c_bool() { return value_; }
  Variant *Clone() { return new Int32(value_); };

  int Compare(Variant *other) {
    Int32 *o = dynamic_cast<Int32*>(other);
    if (o) {
      return value_ - o->value_;
    } else {
      return strcasecmp(c_str(), other->c_str());
    }
  }

  Variant *Plus(Variant *other) {
    Int32 *o = dynamic_cast<Int32*>(other);
    if (o) {
      return new Int32(value_ + o->value_);
    } else {
      return NULL;
    }
  }
  Variant *Minus(Variant *other) {
    Int32 *o = dynamic_cast<Int32*>(other);
    if (o) {
      return new Int32(value_ - o->value_);
    } else {
      return NULL;
    }
  }
  Variant *Mult(Variant *other) {
    Int32 *o = dynamic_cast<Int32*>(other);
    if (o) {
      return new Int32(value_ * o->value_);
    } else {
      return NULL;
    }
  }
  Variant *Div(Variant *other) {
    Int32 *o = dynamic_cast<Int32*>(other);
    if (o) {
      return new Int32(value_ / o->value_);
    } else {
      return NULL;
    }
  }
  Variant *Mod(Variant *other) {
    Int32 *o = dynamic_cast<Int32*>(other);
    if (o) {
      return new Int32(value_ % o->value_);
    } else {
      return NULL;
    }
  }

 protected:
  int32_t value_;
  char value_str_[15];
};

class FileSize : public Int32 {
 public:
  FileSize(off_t value);
  Variant *Clone() { return new FileSize(value_); };
  int Compare(Variant *other);
};

class Float : public Variant {
 public:
  Float(off_t value) : value_(value) { sprintf(value_str_, "%lf", value_); }
  double value() { return value_; }
  const char *c_str() { return value_str_; }
  bool c_bool() { return value_; }
  Variant *Clone() { return new Float(value_); };

  int Compare(Variant *other) {
    Float *o = dynamic_cast<Float*>(other);
    if (o) {
      return value_ - o->value_;
    } else {
      return strcasecmp(c_str(), other->c_str());
    }
  }

  Variant *Plus(Variant *other) {
    Float *o = dynamic_cast<Float*>(other);
    if (o) {
      return new Float(value_ + o->value_);
    } else {
      return NULL;
    }
  }
  Variant *Minus(Variant *other) {
    Float *o = dynamic_cast<Float*>(other);
    if (o) {
      return new Float(value_ - o->value_);
    } else {
      return NULL;
    }
  }
  Variant *Mult(Variant *other) {
    Float *o = dynamic_cast<Float*>(other);
    if (o) {
      return new Float(value_ * o->value_);
    } else {
      return NULL;
    }
  }
  Variant *Div(Variant *other) {
    Float *o = dynamic_cast<Float*>(other);
    if (o) {
      return new Float(value_ / o->value_);
    } else {
      return NULL;
    }
  }

 protected:
  double value_;
  char value_str_[15];
};


class Time : public Variant {
 public:
  Time(time_t value);
  const char *c_str() { return value_str_; }
  bool c_bool() { return true; }
  Variant *Clone() { return new Time(value_); };

  int Compare(Variant *other);

 protected:
  time_t value_;
  char value_str_[25];
};

class Permission : public Variant {
 public:
  Permission(uint32_t value);
  const char *c_str() { return value_str_; }
  bool c_bool() { return value_; }
  Variant *Clone() { return new Permission(value_); };

  int Compare(Variant *other) {
    Permission *o = dynamic_cast<Permission*>(other);
    if (o) {
      return value_ - o->value_;
    } else {
      return strcasecmp(c_str(), other->c_str());
    }
  }

 protected:
  uint32_t value_;
  char value_str_[10];
};

class Bool : public Variant {
 public:
  Bool(bool value) : value_(value) { sprintf(value_str_, value? "true" : "false");}
  const char *c_str() { return value_str_; }
  bool c_bool() { return value_; }
  Variant *Clone() { return new Bool(value_); };

  int Compare(Variant *other) {
    Bool *o = dynamic_cast<Bool*>(other);
    if (o) {
      return (value_? 1 : 0) - (o->value_? 1 : 0);
    } else {
      return strcasecmp(c_str(), other->c_str());
    }
  }

 protected:
  bool value_;
  char value_str_[6];
};
#endif // VARIANT_H_
