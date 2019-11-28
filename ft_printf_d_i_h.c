#include "ft_printf.h"
/*
static int	put_digit(char *dig, int a)
{
	int i;
	i = 5;
	while (a || i == 5)
	{
		--i;
		*(dig + i) = (char)(a % 10) + '0';
		a /= 10;
	}
	return (5 - i);
}
static void	check_sign(t_fstr *fstr, char *sign)
{
	if (fstr->uni.in < 0)
	{
		*sign = '-';
		fstr->uni.in = -(fstr->uni.in);
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
void		ft_printf_d_i_h(t_fstr *fstr, va_list *arg)
{
	char	d_i_s[6];
	char	sign;
	int		ord;
	int		w;
	d_i_s[5] = 0;
	fstr->uni.in = (int)((short int)va_arg(*arg, int));
	check_sign(fstr, &sign);
	ord = put_digit(d_i_s, fstr->uni.in);
	ord = (fstr->uni.in == 0 && fstr->prec == 0) ? 0 : ord;
	w = ft_max(fstr->prec, ord) + (sign != 0);
	if (fstr->wdth > w && !(ft_flag(fstr->flag, MINUS)))
		ft_print_int_width(fstr, &sign, fstr->wdth - w);
	ft_print_int_prec(fstr, &sign, fstr->prec - ord);
	write(1, d_i_s + 5 - ord, ord);
	fstr->prin += ord;
	if (fstr->wdth > w)
		ft_print_int_width(fstr, &sign, fstr->wdth - w);
}
*/