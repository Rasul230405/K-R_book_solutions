#include <stdio.h>

unsigned invert(unsigned x, unsigned p, unsigned n)
{
  return (x) ^ ((~(~0 << p)) & (~0 << (p - n)));
}

void print_binary(unsigned int n) {
   
    if (n > 1)
        print_binary(n >> 1);  // Recursive call with right-shifted value.
    printf("%d", n & 1);
}


int main()
{
  unsigned a = 343;
  print_binary(a);
  printf("\n");

  unsigned b = invert(a, 6, 3);
  printf("decimal: %d\n", b);
  print_binary(b);
  printf("\n");
}
