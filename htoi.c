#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int htoi(char *s)
{
  int result = 0;
  int i = strlen(s) - 1;

  // check 0X or 0x
  char *first = s;
  
  if (tolower(*(++s)) == 'x' && *first != '0')
    return -1;

  if (*s == 'x') {
    s++;
    i = i - 2;
  } else {
    s = first;
  }


  // calculate decimal
  while (*s != '\0') {
    if ((*s >= 'A' && *s <= 'F') || (*s >= '0' && *s <= '9')) {
      int val = isdigit(*s) ? *s - '0' : *s - 55;
      result += val * pow(16, i);
      s++;
      i--;
    }
    else
      return -1;
  }

  return result;
}


int main(int argc, char **argv)
{
  printf("%d\n", htoi(argv[1]));
}
