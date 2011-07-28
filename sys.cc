#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
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
      row.push_back(new UInt32(st.st_size));
    } else if (*ite == "inode") {
      row.push_back(new UInt32(st.st_ino));
    } else if (*ite == "uid") {
      row.push_back(new UInt32(st.st_uid));
    } else if (*ite == "gid") {
      row.push_back(new UInt32(st.st_gid));
    } else if (*ite == "uname") {
      struct passwd *passwd = getpwuid(st.st_uid);
      row.push_back(new String(passwd->pw_name));
    } else if (*ite == "gname") {
      struct group *grp = getgrgid(st.st_gid);
      row.push_back(new String(grp->gr_name));
    } else if (*ite == "atime") {
      row.push_back(new Time(st.st_atime));
    } else if (*ite == "mtime" || *ite == "time") {
      row.push_back(new Time(st.st_mtime));
    } else if (*ite == "ctime") {
      row.push_back(new Time(st.st_ctime));
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

