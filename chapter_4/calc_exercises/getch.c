#include <stdio.h>
#include "getch.h"

#define SIZE 1000

int buffer[SIZE];
int buffp = 0;

void ungetch(char c)
{
  if (buffp >= SIZE)
    printf("getch.c, ungetch(): buffer full\n");

  buffer[buffp++] = c;
}

char getch()
{
  return (buffp > 0) ? buffer[--buffp] : getchar();
}
