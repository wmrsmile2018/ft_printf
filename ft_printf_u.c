#include "ft_printf.h"

static int	put_digit(char *dig, unsigned int a)
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
/*
static void	check_sign(t_fstr *fstr, char *sign)
{
	if (ft_flag(fstr->flag, PLUS))
		*sign = '+';
	else if (ft_flag(fstr->flag, SPACE))
		*sign = ' ';
	else
		*sign = 0;
}
*/
void		ft_printf_u(t_fstr *fstr, va_list *arg)
{
	char	u[11];
	char	sign;
	int		ord;
	int		w;

	u[10] = 0;
	fstr->uni.uin = va_arg(*arg, unsigned int);
//	check_sign(fstr, &sign);
	sign = 0;
	ord = put_digit(u, fstr->uni.uin);
	ord = (fstr->uni.uin == 0 && fstr->prec == 0) ? 0 : ord;
	w = ft_max(fstr->prec, ord);//+ (sign != 0);
	if (fstr->wdth > w && !(ft_flag(fstr->flag, MINUS)))
		ft_print_int_width(fstr, &sign, fstr->wdth - w);
	ft_print_int_prec(fstr, &sign, fstr->prec - ord);
	write(1, u + 10 - ord, ord);
	fstr->prin += ord;
	if (fstr->wdth > w)
		ft_print_int_width(fstr, &sign, fstr->wdth - w);
}
