#include "ft_printf.h"
// 
// void print_base(unsigned long n, int base) {
//   if (n >= base)
//     ft_print_base(n / base, base);
//   n = n % base;
//   n += n < 10 ? '0' : 'a' - 10;
//   write(1, &n, 1);
// }
// 
// int test_func1(int a, int *exp){
//   int b = 1;
//   *exp = 0;
//   while(a / b > 1 && ++(*exp))
//       b *= 2;
//   return b;
// }
// 
// void print_byte(long int n, long int max)
// {
//   printf("%ld\n", max);
//   long int a = max;
//   while(a > 0){
//     if(a & n)
//       write(1, "1", 1);
//     else
//       write(1, "0", 1);
//     a >>= 1;
//   }
// }
// 
// char floor(double val)
// {
//   return((int)val);
// }


int mantis_part_one_to_byte(int in, int *out)
{
  int tmp;
  int i;
  
  i = 0;
  while(in > 0)
  {
    tmp = in;
    in /= 2;
    if(tmp - in * 2)
      *out |= 1 << i;
    i++;
  }
  *out = *out << (24 - i)
  return i;
}

int mantis_part_two_to_byte(double in, int *out)
{
  int tmp;
  int i;
  
  i = 23;
  while(--i > 0)
  {
    
  }
}

int float_to_ieee(double in)
{
  int value;
  
  value = 0;
  return value;
}


unsigned char exponent_part_to_dec(int in)
{
  unsigned char out;
  unsigned char exp_bias;
  unsigned char power;
  int i;
  
  i = 31;
  exp_bias = 127;
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

double fract_part_to_dec(int in)
{
  double out;
  int denominator;
  int i;
  
  i = 23;
  out = 0;
  while(in & 1 << --i && i > 0)
  {
    denominator = 1 << (22 - i);
    out += 1 / (double)denominator;
  }
  return out;
}

// double result(double in)

void		ft_printf_f(t_fstr *fstr, va_list *arg)
 {
    double data;
    long int fract_part;
    int exp;

    data = va_arg(*arg, double);
    
    
    
    // exp = get_bytes_of_frac_part(data, &fract_part);
    // print_base(fract_part, 2);
    // printf("\n   %lu\n", fract_part);
    // printf("\n   %lu\n", exp);

    // printf("%.18Lf\n", 4/3);
    // 0.66666666666666662965923251249478198587894439697265625 // 54 + 2 (.0) %f %lf
    // 6666666666666666 // 17
    // 0.6666666666666666666847367028747584072334575466811656951904296875 // 66 + 2 (.0) %Lf
    // 6666666666666666666 // 20


    
    
    // 4611686018427387904
    // long int a |= (long int)(1 << 62);
    // print_byte(a, 1 << 63);
    // printf("\n%lli\n", a);

    // int exp;
    // printf("%d\n", test_func1(15625, &exp));
    // printf("%d\n", exp);
 }
