#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 128


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

void itob(int n, char *s, unsigned b)
{
  unsigned i;
  unsigned k = n;

  if (n < 0) {
    
    k = ~(k & (~0));
    printf("%u\n", k);
    k++;
  }
  printf("%u\n", k);

  i = 0;
  while (k) {
    int rem = k % b;
    k /= b;

    if (rem <= 9)
      s[i++] = rem + '0';
    else
      s[i++] = rem + '7'; // for alphabet symbols
      
  }

  s[i] = '\0';
  reverse(s);
  
}

int main(int argc, char *argv[])
{
  if (argc != 3) {
    printf("2 arguments required\n");
    return 0;
  }
  
  char s[128];
  int num = atoi(argv[1]);
  unsigned base = atoi(argv[2]);
  itob(num, s, base);

  printf("%s\n", s);
}
