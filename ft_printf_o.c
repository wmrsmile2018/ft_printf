#include "ft_printf.h"

static int	put_digit(char *dig, unsigned int a)
{
	int i;

	i = 11;
	while (a || i == 11)
	{
		--i;
		*(dig + i) = (char)((a & 7) + '0');
		a = a >> 3;
	}
	return (11 - i);
}

static void	check_sign(t_fstr *fstr, char *sign, int ord)
{
	if (ft_flag(fstr->flag, HASH))
	{
		if (fstr->uni.uin == 0)
		{
			if (fstr->prec != 0)
				*sign = 0;
			else
				*sign = '0';
		}
		else
		{
			*sign = '0';
			if (fstr->prec > ord)
				fstr->prec--;
		}
	}
	else
		*sign = 0;
}

void		ft_printf_o(t_fstr *fstr, va_list *arg)
{
	char	o[12];
	char	sign;
	int		ord;
	int		w;

	o[11] = 0;
	fstr->uni.uin = va_arg(*arg, unsigned int);
	ord = put_digit(o, fstr->uni.uin);
	ord = (fstr->uni.uin == 0 && fstr->prec == 0) ? 0 : ord;
	check_sign(fstr, &sign, ord);
	w = ft_max(fstr->prec, ord) + (sign != 0);
	if (fstr->wdth > w && !(ft_flag(fstr->flag, MINUS)))
		ft_print_int_width(fstr, &sign, fstr->wdth - w);
	ft_print_int_prec(fstr, &sign, fstr->prec - ord);
	write(1, o + 11 - ord, ord);
	fstr->prin += ord;
	if (fstr->wdth > w)
		ft_print_int_width(fstr, &sign, fstr->wdth - w);
}
