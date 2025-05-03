#include <stdio.h>
#include <ctype.h>
#include <math.h>

int atoi(char s[])
{
  int i, n, sign;
  
  for (i = 0; isspace(s[i]); i++)
    ;
  
  sign = (s[i] == '-') ? -1 : 1;
  
  if (s[i] == '+' || s[i] == '-')
    i++;

  for (n = 0; isdigit(s[i]); i++)
    n = 10 * n + (s[i] - '0');
  
  return sign * n;
}

double atof(char *s)
{
  double value, t;
  int i, sign = 1, power;
  
  for (i = 0;isspace(s[i]); ++i) ;

  if (s[i] == '-') {
    sign = -1;
    ++i;
  }

  // integer part
  value = 0;
  for(; isdigit(s[i]); ++i) {
    value = (value * 10.0 + (s[i] - '0'));
  }
  
  if (s[i] != '.')
    return sign * value;

  // fraction
  t = 0.1;
  i++;
  for (; isdigit(s[i]); ++i) {
    value += ((s[i] - '0') * t);
    t *= 0.1;
  }

  printf("%f\n", value);
  // scientific notation
  if (s[i] != 'e' && s[i] != 'E')
    return sign * value;
  
  ++i;
  
  if (s[i] != '-')
    return sign * value;

  ++i
  power = atoi(&s[i]);

  return sign * value * pow(10, power);
}

int main(void)
{
  char *s = "123.45e-6";

  double n = atof(s);

  printf("%lf\n", n);
}
