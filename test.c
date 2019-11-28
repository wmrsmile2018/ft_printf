#include "ft_printf.h"
#include <stdio.h>
#include <math.h>

void ft_print_base(unsigned long n, int base) {
  if (n >= base)
    ft_print_base(n / base, base);
  n = n % base;
  n += n < 10 ? '0' : 'a' - 10;
  write(1, &n, 1);
}


double fract_part(int in)
{
  double out;
  int denominator;
  int i;
  
  i = 23;
  out = 0;
  while( --i > 0)
  {
    if (!(in & 1 << i))
      continue;
    denominator = 1 << (22 - i);
    out += 1 / (double)denominator;
  }
  return out;
}


double my_ceil(double in)
{
  return(in < 0 ? (int) in : (int) in + 1);
}


int exponent_part_to_byte(int in)
{
  int out;
  int tmp;
  int i;
  
  i = 0;
  out = 0;
  while(in > 0)
  {
    tmp = in;
    in /= 2;
    if(tmp - in * 2)
      out |= 1 << i;
    i++;
  }
  return out << (24 - i);
}


unsigned char exponent_part(int in)
{
  unsigned char out;
  unsigned char exp_bias;
  unsigned char power;
  int i;
  
  i = 31;
  exp_bias = 0;
  out = 0;
  while(--i > 22)
  {
    if(!(in & 1 << i))
      continue;
    power = 1 << (i - 23);
    out += power;
  }
  return out - exp_bias;
}


int main () {
  long double hello = 2/3 ;
	int a, b;
  long double pi, d, l;

  d = 3;
  l = 4;
  pi = l / d;

  // int test = 0;
  // double res;
  // test  |= 1 << 7;
  // printf("%d\n", test);
  // res = 1 / (double)test;
  // printf("%.100f\n", res);
// 10, 13
  // double test = fract_part(9216);
  // unsigned char test1 = exponent_part(9216);
  // long double test2 = 123.1234567898765400000;
  // long double test3 = 0.00000000000001;
  // printf("%.100Lf\n", test2 * test3);
  // printf("%d\n", 5/2);
  
  
  int test4 = exponent_part_to_byte(263);
  printf("%d\n", test4);
	return (0);
}
