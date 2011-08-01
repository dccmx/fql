#include <string.h>

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

Permission::Permission(uint32_t value) {
   // use octarray for determining if permission bits set
   //it means rwx rwx rwx
  static short octarray[9]={0400,0200,0100,
    0040,0020,0010,
    0004,0002,0001};

  value_ = value;

  /*record the file permission format as rwxrwxrwx,use
   * 10 chars long becausr the last one is null
   */
  strcpy(value_str_, "rwxrwxrwx");

  for(int i=0; i<9; i++) {
    if (!(value_ & octarray[i])) {
      value_str_[i]='-';
    }
  }
}

FileSize::FileSize(off_t value) {
  static const char m[] = "\0KMGTP";

  value_ = value;

  double v = value_;
  int i = 0;
  while (v >= 1024 && i < 5) {
    v /= 1024.0;
    i++;
  }

  if (i != 0 ) sprintf(value_str_, "%.1lf%c", v, m[i]);
  else sprintf(value_str_, "%d", value_);
}

