#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"
#include "getch.h"

#define SIZE 1000
#define NUMBER '0'

int getop(char s[]);

int main(void)
{
  char s[SIZE];
  char type;
  double op2;

  while ((type = getop(s)) != EOF) {
    switch(type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
    case '*':
      push(pop() * pop());
    case '/':
      op2 = pop();
      if (op2 == 0)
	printf("error: divide by zero\n");
      else
	push(pop() / op2);
      break;
    case '%':
      op2 = pop();
      if (op2 == 0)
	printf("error: divide by zero\n");
      else
	push((int)pop() % (int)op2);
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
    
  }
  return 0;
}

// get the next operator or operand
int getop(char s[])
{
  int i, c;

  while((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  if (!isdigit(c) && c != '.')
    return c;

  i = 0;
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()));

  if (c =='.')
    while (isdigit(s[++i] = c = getch()));
  
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);

  return NUMBER;
}
