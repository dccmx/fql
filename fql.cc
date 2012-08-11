#include <unistd.h>

#include "lexer.h"
#include "ast.h"
#include "sys.h"
#include "variant.h"

#include <config.h>

#if defined(HAVE_LIBREADLINE) && HAVE_LIBREADLINE==1
# include <readline/readline.h>
# include <readline/history.h>
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

int main(int argc, char **argv) {
  char *str = ParseArgs(argc, argv);

  if (str) {
    ExecuteSQL(str);
    free(str);
  } else {
    while (true) {
      if (str) {
          free(str);
          str = (char *)NULL;
      }
#if defined(HAVE_LIBREADLINE) && HAVE_LIBREADLINE==1
      if (isatty(STDIN_FILENO)) {
          str = readline("> ");
          if( str && *str ) 
              add_history(str);
          else
              continue;
      } else {
          str = readline("");
          if (! str) break;
      }
#else
      if (isatty(STDIN_FILENO)) printf("> ");
      char str[1024];
      fgets(str, 1024, stdin);
      if (feof(stdin)) break;
      if (!str || !strcmp("\n", str) || !strcmp("\r\n", str)) continue;
#endif
      if (!strcmp("exit",str) || !strcmp("exit\n", str)) {
#if defined(HAVE_LIBREADLINE) && HAVE_LIBREADLINE==1
          free(str);
          clear_history();
#endif
          printf("bye\n");
          break;
      }
      ExecuteSQL(str);
    }
  }
}
