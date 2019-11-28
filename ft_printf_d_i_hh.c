#include "ft_printf.h"
/*
static int	put_digit(char *dig, int a)
{
	int i;
	i = 3;
	while (a || i == 10)
	{
		--i;
		*(dig + i) = (char)(a % 10) + '0';
		a /= 10;
	}
	return (3 - i);
}
static void	check_sign(t_fstr *fstr, char *sign)
{
	if (fstr->uni.in < 0)
	{
		*sign = '-';
		fstr->uni.in = -fstr->uni.in;
	}
	else
	{
		if (ft_flag(fstr->flag, PLUS))
			*sign = '+';
		else if (ft_flag(fstr->flag, SPACE))
			*sign = ' ';
		else
			*sign = 0;
	}
}
void		ft_printf_d_i_hh(t_fstr *fstr, va_list *arg)
{
	char	d_i[4];
	char	sign;
	int		ord;
	int		w;
	d_i[3] = 0;
	fstr->uni.in = (int)((char)va_arg(*arg, int));
	check_sign(fstr, &sign);
	ord = put_digit(d_i, fstr->uni.in);
	ord = (fstr->uni.in == 0 && fstr->prec == 0) ? 0 : ord;
	w = ft_max(fstr->prec, ord) + (sign != 0);
	if (fstr->wdth > w && !(ft_flag(fstr->flag, MINUS)))
		ft_print_int_width(fstr, &sign, fstr->wdth - w);
	ft_print_int_prec(fstr, &sign, fstr->prec - ord);
	write(1, d_i + 3 - ord, ord);
	fstr->prin += ord;
	if (fstr->wdth > w)
		ft_print_int_width(fstr, &sign, fstr->wdth - w);
}
*/