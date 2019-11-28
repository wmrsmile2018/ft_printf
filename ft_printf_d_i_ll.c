#include "ft_printf.h"

static int	put_digit(char *dig, long long int a)
{
	int i;

	i = 19;
	while (a || i == 19)
	{
		--i;
		*(dig + i) = (char)(a % 10) + '0';
		a /= 10;
	}
	return (19 - i);
}

static void	check_sign(t_fstr *fstr, char *sign)
{
	if (fstr->uni.llin < 0)
	{
		*sign = '-';
		fstr->uni.llin = -fstr->uni.llin;
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

static int	handle_except(char *d_i_ll, char *sign)
{
//	d_i_ll = "9223372036854775808";
	*d_i_ll = '9';
	*(1 + d_i_ll) = '2';
	*(2 + d_i_ll) = '2';
	*(3 + d_i_ll) = '3';
	*(4 + d_i_ll) = '3';
	*(5 + d_i_ll) = '7';
	*(6 + d_i_ll) = '2';
	*(7 + d_i_ll) = '0';
	*(8 + d_i_ll) = '3';
	*(9 + d_i_ll) = '6';
	*(10 + d_i_ll) = '8';
	*(11 + d_i_ll) = '5';
	*(12 + d_i_ll) = '4';
	*(13 + d_i_ll) = '7';
	*(14 + d_i_ll) = '7';
	*(15 + d_i_ll) = '5';
	*(16 + d_i_ll) = '8';
	*(17 + d_i_ll) = '0';
	*(18 + d_i_ll) = '8';
	*sign = '-';
	return (19);
}

void		ft_printf_d_i_ll(t_fstr *fstr, va_list *arg)
{
	char	d_i_ll[20];
	char	sign;
	int		ord;
	int		w;

	d_i_ll[19] = 0;
	fstr->uni.llin = va_arg(*arg, long long int);
	if ((unsigned long long)fstr->uni.llin == 0x8000000000000000)
		ord = handle_except(d_i_ll, &sign);
	else
	{
		check_sign(fstr, &sign);
		ord = put_digit(d_i_ll, fstr->uni.llin);
	}
	ord = (fstr->uni.llin == 0 && fstr->prec == 0) ? 0 : ord;
	w = ft_max(fstr->prec, ord) + (sign != 0);
	if (fstr->wdth > w && !(ft_flag(fstr->flag, MINUS)))
		ft_print_int_width(fstr, &sign, fstr->wdth - w);
	ft_print_int_prec(fstr, &sign, fstr->prec - ord);
	write(1, d_i_ll + 19 - ord, ord);
	fstr->prin += ord;
	if (fstr->wdth > w)
		ft_print_int_width(fstr, &sign, fstr->wdth - w);
}
