#include <stdio.h>
#include <string.h>
#include <limits.h>

/*
  Using unsigned type will solve the issue.
*/

void swap(char *a, char *b)
{
  char temp = *a;
  *a = *b;
  *b = temp;
}

void reverse(char *s)
{
  int i, j;
  unsigned len =  strlen(s);
 
  for (i = 0, j = len - 1; i <= j; i++, j--) 
    swap(&s[i], &s[j]);
  
  s[len] = '\0';
}

void itoa(int n, char *s)
{
  int i, sign;
  unsigned k;

  if ((sign = n) < 0)
    k = -n;

  i = 0;
  while (k > 0) {
    s[i++] = k % 10 + '0';
    k /= 10;
  }

  if (sign < 0) s[i++] = '-';
  
  s[i] = '\0';
  
  reverse(s);
}

int main()
{
  int a = -2147483648;
  char s[128];
  printf("INTMAX: %d\n", INT_MAX);

  itoa(a, s);
  
  printf("%s\n", s);
}
