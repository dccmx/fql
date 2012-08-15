fql
===
  fql is a tool that use SQL like query to manipulate files.

Example
-------
    fql "select time, size, name from ../"
    fql "select time, size, name from abc -r"  # scan abc recursivly
    fql "select * where name = fql.cc"
    fql "select * where not name = fql.cc"
    fql "select time, size, name from . where size > 2.5k and size < 3k order by size desc"
    echo "select * from . " | fql
    or run fql to query intractivly

Available columns to select
---------------------------
    name
    path
    perms
    size
    inode
    uid
    gid
    uname
    gname
    atime
    time : same as atime
    mtime
    ctime

Supported syntax
----------------
    select [attrs]
    from [folder] [-r]
    where [expression]
    order by [attrs]
    limit [[start,] limit]

Build (libreadline is optional)
-----
    ./configure && make

Install
-------
  copy ./fql to where you like, such as /usr/local/bin/.

  or make install
