#include <stdio.h>

char *program();
char *identifier();

int main(void)
{
  printf("%s\n", program());

  return 0;
}

/*
 * <program> -> <identifier>
 */
char *program()
{
  return identifier();
}

/*
 * <identifier> -> a
 */
char *identifier()
{
  return "a";
}