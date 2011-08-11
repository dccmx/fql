#include <ctype.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <regex.h>

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

int Time::Compare(Variant *other) {
  Time *o = dynamic_cast<Time*>(other);
  if (o) {
    return value_ - o->value_;
  } else {
    /*
    1. DATE : YYYY-MM-DD
    2. DATETIME : YYYY-MM-DD HH:MM:SS
    3. TIMESTAMP : YYYY-MM-DD HH:MM:SS
    4. YEAR : YYYY or YY
    */
    static const char *fmts[] = {"%Y-%m-%d", "%Y-%m-%d %H:%M:%S", "%Y", "%y"};
    struct tm tv;
    for (uint32_t i = 0; i < sizeof(fmts)/sizeof(fmts[0]); i++) {
      memset(&tv, 0, sizeof(tv));
      char *p = strptime(other->c_str(), fmts[i], &tv);
      if ( p != NULL && *p == '\0') {
        return value_ - mktime(&tv);
      }
    }

    // failed to convert it to time. Compare them as string.
    return strcasecmp(c_str(), other->c_str());
  }
  return 0;
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
  static const char m[] = "\0KMG";

  value_ = value;

  double v = value_;
  int i = 0;
  while (v >= 1024 && i < 3) {
    v /= 1024.0;
    i++;
  }

  if (i != 0 ) sprintf(value_str_, "%.1lf%c", v, m[i]);
  else sprintf(value_str_, "%d", value_);
}

static int GetSize(const char *str) {
  static const char m[] = "\0KMG";
  static const int s[] = {-1, 1024, 1024*1024, 1024*1024*1024};
  const char *p = str;
  int ndot = 0;
  while ((*p >= '0' && *p <= '9') || (*p == '.')) {
    if (*p == '.') ndot++;
    if (ndot > 1) return -1;
    p++;
  }

  if (*p == '\0') return -1;

  int v = -1;
  for (int i = 1; i < 4; i++) {
    if (toupper(*p) == m[i]) {
      v = s[i];
      p++;
      break;
    }
  }

  if (*p != '\0') return -1;

  return v;
}

int FileSize::Compare(Variant *other) {
  Int32 *o = dynamic_cast<Int32*>(other);
  Float *f = dynamic_cast<Float*>(other);
  if (o) {
    return value_ - o->value();
  } else if (f) {
    return value_ - f->value();
  } else {
    double v1 = 0;
    int m1 = GetSize(other->c_str());
    if (m1 != -1 && sscanf(other->c_str(), "%lf", &v1) == 1) {
      double v = 0;
      int m = GetSize(c_str());
      sscanf(c_str(), "%lf", &v);
      return v * m - v1 * m1;
    } else {
      return strcasecmp(c_str(), other->c_str());
    }
  }
}

bool Variant::Like(Variant *other) {
  regex_t reg;
  if (regcomp(&reg, other->c_str(), REG_EXTENDED) != 0) {
    return false;
  }

  regmatch_t stRegMatch;
  int nRet = regexec(&reg, c_str(), 1, &stRegMatch, 0);
  if (nRet == REG_NOMATCH) {
    return false;
  } else if (nRet != 0) {
    return false;
  }

  if(stRegMatch.rm_so == 0 && c_str()[stRegMatch.rm_eo] == '\0') {
    return true;
  }

  regfree(&reg);
  return false;
}

