#include <stdio.h>
#include <ctype.h>
#include "getch.h"

#define SIZE 1024

int main(void)
{
  char input[SIZE];
  char c;
  int i = 0;
  
  while (isdigit((c = getch()))) 
    input[i++] = c;

  input[i++] = '\0';
  ungets(input);

  while (isdigit((c = getch())))
    fprintf(stdout, "%c", c);
}
