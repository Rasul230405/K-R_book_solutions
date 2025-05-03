#include <stdio.h>
#include <ctype.h>
#define SIZE 1024
#define DUMMY '\0'

void expand(char *s1, char *s2)
{
  int i, j;
  
  for (i = j = 0; s1[i] != '\0'; ++i) {
    if (((s1[i] >= 'A' && s1[i] <= 'Z' && s1[i + 1] == '-' && s1[i + 2] >= 'A' && s1[i + 2] <= 'Z') ||
	(s1[i] >= 'a' && s1[i] <= 'z' && s1[i + 1] == '-' && s1[i + 2] >= 'a' && s1[i + 2] <= 'z') ||
	(s1[i] >= '0' && s1[i] <= '9' && s1[i + 1] == '-' && s1[i + 2] >= '0' && s1[i + 2] <= '9')) &&
	s1[i] < s1[i + 2]) {

      for (char c = s1[i]; c <= s1[i + 2]; ++c) {
	s2[j] = c;
	++j;
      }

    s1[i + 2] = DUMMY;
    i += 2;
    }

    else {
      s2[j] = s1[i];
      ++j;
    }
  }

  s2[j] = '\0';
}

int main(int argc, char *argv[])
{
  if (argc != 2)
    printf("1 argument expected\n");

  char res[SIZE];
  expand(argv[1], res);

  printf("%s\n", res);
}
