#include <stdio.h>
#include <string.h>
#include "getch.h"

#define SIZE 1000

int buffer[SIZE];
int buffp = 0;

int ungetch(char c)
{
  if (buffp >= SIZE) {
    fprintf(stderr, "getch.c, ungetch(): buffer full\n");
    return EOF;
  }
  else {
    buffer[buffp++] = c;
    return c;
  }
}

char getch()
{
  return (buffp > 0) ? buffer[--buffp] : getchar();
}

int ungets(const char *s)
{
  int len = strlen(s);

  for (int i = len - 1; i >= 0; --i) {
    if (s[i] == EOF)
      return EOF;
    ungetch(s[i]);
  }

  return len;
}
