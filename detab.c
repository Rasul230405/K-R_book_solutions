#include <stdio.h>
#include <math.h>
#define TABSTOP 8

void detab(char in[], char out[], int tab_stop)
{
  int pos = 0;
  while (*in != '\n') {
    
    if (*in == '\t') {
      int blank = ((pos + tab_stop - 1) / tab_stop) * tab_stop - pos; 

      while (blank--) {
	*out = '-';
	out++;
	pos++;
      }
      
      in++;
      continue;
    }

    
    *out = *in;
    
    out++;
    in++;
    pos++;
  }

  *out = *in;
}

void detab2(char in[], char out[], int tab_stop)
{
   int pos = 0;
  while (*in != '\n') {
    
    if (*in == '\t') {
      int blanks = tab_stop - pos % tab_stop;

      while (blanks--) {
	*out = '-';
	out++;
      }
      
      pos += blanks;
      in++;
      continue;
    }
    
    
    *out = *in;
    
    out++;
    in++;
    pos++;
  }

  *out = *in;
}

int main()
{
  FILE *fp1, *fp2;
  fp1 = fopen("file1.txt", "r");
  fp2 = fopen("file1_ans.txt", "w");

  char input[256];
  char output[256];

  while (fgets(input, sizeof(input), fp1) != NULL) {
    printf("%s", input);
    detab(input, output, TABSTOP);
    fputs(output, fp2);
  }
  
  fclose(fp1);
  fclose(fp2);
}
