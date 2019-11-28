#include "ft_printf.h"

static int	put_digit_l(char *dig, unsigned long int a, int size, char *base)
{
	int i;

	i = size;
	while (a || i == size)
	{
		--i;
		*(dig + i) = *(base + (a & 15));
		a = a >> 4;
	}
	return (size - i);
}

void		ft_printf_x_l(t_fstr *fstr, va_list *arg)
{
	char	x_l[HEX_L];
	char	sign[3];
	int		ord;
	int		w;

	fstr->uni.ulin = va_arg(*arg, unsigned long int);
	if (!(fstr->base[10]))
		ft_set_base_x(fstr->base, 'x');
	else if (fstr->base[10] == 'A')
		ft_set_base_lit_x(fstr->base + 10);
	ft_set_sign_x(fstr, sign);
	ord = put_digit_l(x_l, fstr->uni.ulin, HEX_L, fstr->base);
	ord = (fstr->uni.ulin == 0 && fstr->prec == 0) ? 0 : ord;
	w = ft_max(fstr->prec, ord) + 2 * (sign[0] != 0);
	if (fstr->wdth > w && !(ft_flag(fstr->flag, MINUS)))
	{
		ft_check_ox(fstr, sign, 0);
		ft_print_int_width(fstr, sign + 2, fstr->wdth - w);
	}
	ft_check_ox(fstr, sign, 1);
	ft_print_int_prec(fstr, sign + 2, fstr->prec - ord);
	ft_buf_str(x_l + HEX_L - ord, ord, fstr);
	if (fstr->wdth > w)
		ft_print_int_width(fstr, sign + 2, fstr->wdth - w);
}

void		ft_printf_xx_l(t_fstr *fstr, va_list *arg)
{
	char	xx_l[HEX_L];
	char	sign[3];
	int		ord;
	int		w;

	fstr->uni.ulin = va_arg(*arg, unsigned long int);
	if (!(fstr->base[10]))
		ft_set_base_x(fstr->base, 'X');
	else if (fstr->base[10] == 'a')
		ft_set_base_lit_xx(fstr->base + 10);
	ft_set_sign_xx(fstr, sign);
	ord = put_digit_l(xx_l, fstr->uni.ulin, HEX_L, fstr->base);
	ord = (fstr->uni.ulin == 0 && fstr->prec == 0) ? 0 : ord;
	w = ft_max(fstr->prec, ord) + 2 * (sign[0] != 0);
	if (fstr->wdth > w && !(ft_flag(fstr->flag, MINUS)))
	{
		ft_check_ox(fstr, sign, 0);
		ft_print_int_width(fstr, sign + 2, fstr->wdth - w);
	}
	ft_check_ox(fstr, sign, 1);
	ft_print_int_prec(fstr, sign + 2, fstr->prec - ord);
	ft_buf_str(xx_l + HEX_L - ord, ord, fstr);
	if (fstr->wdth > w)
		ft_print_int_width(fstr, sign + 2, fstr->wdth - w);
}