#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *program();
char *expression();
char *identifier();

int main(void)
{
  /* a sentence is a syntactically valid program */
  char *sentence;

  /* we want the program output to depend on something that changes between
   * executions, like the system time */
  srand(time(NULL));

  sentence = program();

  printf("%s\n", sentence);

  free(sentence);

  return 0;
}

/*
 * <program> -> <expression>
 */
char *program()
{
  return expression();
}

/*
 * <expression> -> <expression> + <expression>
 *                 | <identifier>
 */
char *expression()
{
  char *sentence;
  char *tmp;

  sentence = malloc(100 * sizeof(char));

  switch (rand() % 2)
  {
  /* <expression> + <expression> */
  case 0:
    tmp = expression();
    strcpy(sentence, tmp);
    free(tmp);
    strcat(sentence, " + ");
    tmp = expression();
    strcat(sentence, tmp);
    free(tmp);
    break;
  /* <identifier> */
  case 1:
    strcpy(sentence, identifier());
    break;
  /* this should never happen */
  default:
    fprintf(stderr, "The programmer screwed up the expression switch statement.\n");
    exit(1);
  }

  return sentence;
}

/*
 * <identifier> -> a
 */
char *identifier()
{
  return "a";
}