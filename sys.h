#ifndef SYS_H_
#define SYS_H_

#include <string>
#include <time.h>

#include "table.h"


void ListDir(Table *tb, const string& dir, bool recursive);

#endif // SYS_H_
