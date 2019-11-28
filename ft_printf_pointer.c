#include "ft_printf.h"

void get_adr(unsigned long n, t_fstr *fstr, char *str) {
  if (n >= 16)
    get_adr(n / 16, fstr, str);
  n = n % 16;
  n += n < 10 ? '0' : 'a' - 10;
  str[fstr->prin] = n;
  fstr->prin++;
}

void print_adr(t_fstr *fstr, char *adr, int size) {
  write(1, "0x", 2);
  fstr->prin += 2;
  while(fstr->prec-- > size && ++fstr->prin)
    write(1, "0", 1);
  write(1, adr, size);
}

void		ft_printf_pointer(t_fstr *fstr, va_list *arg)
{
	unsigned long data;
  char *adr;
  int size;

  data = (unsigned long)(va_arg(*arg, void*));
  while((adr = (char*)malloc(sizeof(char) * 10)))
    break ;
  ft_bzero(adr, 10);
  if(fstr->prec)
    get_adr(data, fstr, adr);
  size = ft_strlen(adr);
  data = size > fstr->prec ? size : fstr->prec;
  if(ft_flag(fstr->flag, MINUS)) {
    print_adr(fstr, adr, size);
    while((fstr->wdth-- > (int)data + 2) && ++fstr->prin)
      write(1, " ", 1);
  }
  else {
    while((fstr->wdth-- > (int)data + 2) && ++fstr->prin)
      write(1, " ", 1);
    print_adr(fstr, adr, size);
  }
  free(adr);
}
