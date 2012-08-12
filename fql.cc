#include <unistd.h>
#include <string.h>

#include "config.h"
#include "lexer.h"
#include "ast.h"
#include "sys.h"
#include "variant.h"

#if defined(HAVE_LIBREADLINE) && HAVE_LIBREADLINE==1
# include <readline/readline.h>
# include <readline/history.h>
# define GetSQLFromInput GetSQLFromReadline
#else
# define GetSQLFromInput GetSQLFromStdin
#endif


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
        printf("fql %s\n\n", VERSION);
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

char *GetSQLFromReadline() {
  char * str = NULL;

  if (isatty(STDIN_FILENO)) {
    str = readline("> ");
  } else {
    str = readline("");
  }
  if (str != NULL) {
    add_history(str);
  }

  return str;
}

char *GetSQLFromStdin() {
  while (true) {
    char buf[1024];
    if (isatty(STDIN_FILENO)) printf("> ");
    fgets(buf, 1024, stdin);
    if (feof(stdin)) {
      return NULL;
    }
    if (strcmp("\n", buf) != 0 && !strcmp("\r\n", buf) != 0) {
      return strdup(buf);
    }
  }
  return NULL;
}

int main(int argc, char **argv) {
  char *str = ParseArgs(argc, argv);

  if (str) {
    ExecuteSQL(str);
    return 0;
  }

  while (true) {
    str = GetSQLFromInput();

    if (str == NULL) break;

    if (strcmp("", str) == 0) {
      // do nothing
    } else if (!strcmp("exit", str) || !strcmp("exit\n", str)) {
      printf("bye\n");
    } else {
      ExecuteSQL(str);
    }

    free(str);
  }

  return 0;
}
