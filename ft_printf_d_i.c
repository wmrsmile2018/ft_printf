#include "ft_printf.h"

static int	put_digit(char *dig, int a)
{
	int i;

	i = 10;
	while (a || i == 10)
	{
		--i;
		*(dig + i) = (char)(a % 10) + '0';
		a /= 10;
	}
	return (10 - i);
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

static int	handle_except(char *d_i, char *sign)
{
//	d_i = "2147483648";
	*d_i = '2';
	*(1 + d_i) = '1';
	*(2 + d_i) = '4';
	*(3 + d_i) = '7';
	*(4 + d_i) = '4';
	*(5 + d_i) = '8';
	*(6 + d_i) = '3';
	*(7 + d_i) = '6';
	*(8 + d_i) = '4';
	*(9 + d_i) = '8';
	*sign = '-';
	return (10);
}

void		ft_printf_d_i(t_fstr *fstr, va_list *arg)
{
	char	d_i[11];
	char	sign;
	int		ord;
	int		w;

	d_i[10] = 0;
	fstr->uni.in = va_arg(*arg, int);
	if (fstr->uni.in == -2147483648)
		ord = handle_except(d_i, &sign);
	else
	{
		check_sign(fstr, &sign);
		ord = put_digit(d_i, fstr->uni.in);
	}
	ord = (fstr->uni.in == 0 && fstr->prec == 0) ? 0 : ord;
	w = ft_max(fstr->prec, ord) + (sign != 0);
	if (fstr->wdth > w && !(ft_flag(fstr->flag, MINUS)))
		ft_print_int_width(fstr, &sign, fstr->wdth - w);
	ft_print_int_prec(fstr, &sign, fstr->prec - ord);
	write(1, d_i + 10 - ord, ord);
	fstr->prin += ord;
	if (fstr->wdth > w)
		ft_print_int_width(fstr, &sign, fstr->wdth - w);
}
