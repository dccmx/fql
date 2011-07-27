#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

#include "sys.h"

static void AddFile(Table *tb, const char *path, const char *name) {
  struct stat st;

  static char filename[2048];

  sprintf(filename, "%s/%s", path, name);

  if(stat(filename, &st) == -1) return;

  Row row;

  for (vector<string>::const_iterator ite = tb->Header().begin(); ite != tb->Header().end(); ++ite) {
    if (*ite == "name") {
      row.push_back(new String(name));
    } else if (*ite == "size") {
      row.push_back(new Size(st.st_size));
    }
  }

  tb->Append(row);
}

void ListDir(Table *tb, const string& dir) {
  DIR *dp;
  struct dirent *ent;

  if (!(dp = opendir(dir.c_str()))) return;

  while((ent = readdir(dp)) != NULL) {
    AddFile(tb, dir.c_str(), ent->d_name);
  }

  closedir(dp);
}

