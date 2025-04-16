#include <stdio.h>

int exist(char *s, char c)
{
  while (*s != '\0') {
    if (*s == c) return 1;
    ++s;
  }

  return 0;
}

void squeeze(char *s1, char *s2)
{
  int i, j;
  for (i = j = 0; s1[i] != '\0'; i++) {
    if (!exist(s2, s1[i])) 
      s1[j++] = s1[i];
  }
  s1[j] = '\0';
  
}

char* strpbrk(char *s1, char *s2)
{

  for (; *s1 != '\0'; s1++) {
    if (exist(s2, *s1))
      return s1;
  }

  return s1;
}


int main(int argc, char **argv)
{
 
  char *ps = strpbrk(argv[1], argv[2]);
  printf("%c\n", *ps);
 
}
