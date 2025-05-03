#include <stdio.h>
#include <string.h>

int strindex(char *s, char *t)
{
  int i, j, k;
  size_t len_t = strlen(t);

  for (i = strlen(s) - 1; i >= 0; --i) {
    for (j = i, k = len_t - 1; j >= 0 && k >=0 && t[k] == s[j]; --j, --k)
      ;

    if (k < 0)
      return (j + 1);
  }

  return -1;
}

int main(int argc, char *argv[])
{
  if (argc != 3) {
    printf("2 arguments expected\n");
    return 0;
  }
  int index;
  
  if((index = strindex(argv[1], argv[2])) >= 0)
    printf("index: %d\n", index);
  else
    printf("not found\n");

  return 0; 
}
