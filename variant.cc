#include "variant.h"
Variant::~Variant() {};

Time::Time(time_t value) {
  value_ = value;
  struct tm tm;
  localtime_r(&value_, &tm);
  sprintf(value_str_, "%04d-%02d-%02d %02d:%02d:%02d", 
          1900 + tm.tm_year, tm.tm_mon + 1, tm.tm_mday, 
          tm.tm_hour, tm.tm_min, tm.tm_sec);
}

