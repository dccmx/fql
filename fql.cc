#include <unistd.h>

#include "lexer.h"
#include "ast.h"
#include "sys.h"
#include "variant.h"

void ExecuteSQL(char *sql) {
  ParserContext parse = Parse(sql);
  if (!parse.error) {
    Table *res = parse.stmt->Execute();
    res->Print();
    delete res;
    delete parse.stmt;
  }
}

void usage() {
  printf("usage:\n"
      "  fql [options] \"sql statement\"\n"
      "options:\n"
      "  -v           show version and exit\n"
      "  -h, --help   show help and exit\n"
      "examples:\n"
      "  fql \"select * from . where size > 1000\"\n"
      "  echo \"select * order by name\" | fql\n"
      "  fql\n"
      "  > select name, size from ../x\n"
      );
  exit(EXIT_SUCCESS);
}

char *ParseArgs(int argc, char **argv) {
  char *sql = NULL;

  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help")) {
        usage();
      } else if (!strcmp(argv[i], "-v")) {
        printf("fql "VERSION"\n\n");
        exit(EXIT_SUCCESS);
      } else {
        fprintf(stderr, "unknow option %s\n", argv[i]);
      }
    } else {
      sql = argv[i];
    }
  }

  return sql;
}

int main(int argc, char **argv) {
  char *sql = ParseArgs(argc, argv);

  if (sql) {
    ExecuteSQL(sql);
  } else {
    char sql[1024];
    while (true) {
      if (isatty(STDIN_FILENO)) printf("> ");
      fgets(sql, 1024, stdin);
      if (feof(stdin)) break;
      ExecuteSQL(sql);
    }
  }
}
