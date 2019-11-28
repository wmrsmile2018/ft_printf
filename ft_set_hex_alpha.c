#include "ft_printf.h"

void ft_set_base_lit_x(char *base)
{
	char s;

	s = 'a';
	while (s <= 'f')
	{
		*base = s;
		s++;
		base++;
	}
}

void ft_set_base_lit_xx(char *base)
{
	char s;

	s = 'A';
	while (s <= 'F')
	{
		*base = s;
		s++;
		base++;
	}
}

void ft_set_base_x(char *base, char c)
{
	char s;

	s = '0';
	while (s <= '9')
	{
		*base = s;
		s++;
		base++;
	}
	if (c == 'x')
		ft_set_base_lit_x(base);
	else
		ft_set_base_lit_xx(base);
}

void	ft_set_sign_x(t_fstr *fstr, char *sign)
{
	if (ft_flag(fstr->flag, HASH) && fstr->uni.uin != 0)
	{
		*sign = '0';
		*(sign + 1) = 'x';
	}
	else
	{
		*sign = 0;
		*(sign + 1) = 0;
	}
	*(sign + 2) = 0;
}

void	ft_set_sign_xx(t_fstr *fstr, char *sign)
{
	if (ft_flag(fstr->flag, HASH) && fstr->uni.uin != 0)
	{
		*sign = '0';
		*(sign + 1) = 'X';
	}
	else
	{
		*sign = 0;
		*(sign + 1) = 0;
	}
	*(sign + 2) = 0;
}
