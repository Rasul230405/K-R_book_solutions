#include <stdio.h>

unsigned rightrot(unsigned x, int n) {
    int wordlength = sizeof(x) * 8;       // Total bits in an unsigned integer
    n = n % wordlength;                   // In case n is larger than wordlength
    // right shift x by n bits
    unsigned right_shifted = x >> n;
    // left shift the bits that 'fell off' to the left side
    unsigned wrapped_bits = x << (wordlength - n);
    // combine the two parts
    return right_shifted | wrapped_bits;
}

int main()
{

  unsigned a = 93;

  unsigned b = rightrot(a, 2);

  printf("%d\n", b);
}
