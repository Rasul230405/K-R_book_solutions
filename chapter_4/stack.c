#include "stack.h"
#include <stdio.h>

#define SIZE 1000
double stack[SIZE];

int stackp = -1;

void push(double val)
{
  if (stackp >= SIZE)
    printf("stack, push(): stack is full\n");

  stack[++stackp] = val;
}

double pop()
{
  if (stackp < 0) 
    printf("stack, pop(): stack is empty\n");

  return stack[stackp--];
}

double top()
{
  if (stackp < 0) 
    printf("stack, top(): stack is empty\n");

  return stack[stackp];
}

void clear()
{
  stackp = -1;
}
