#include <stdio.h>

#define swap(t, a, b) { t temp = (a); (a) = (b); (b) = (temp);}


int main()
{
  int a = 5;
  int b = 7;

  printf("a = %d, b = %d\n", a, b);
  swap(int, a, b);
  printf("after swap:\na = %d, b = %d\n", a, b);
  
}
