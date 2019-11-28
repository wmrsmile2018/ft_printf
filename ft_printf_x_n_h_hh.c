#include "ft_printf.h"

void		ft_printf_x(t_fstr *fstr, va_list *arg)
{
	char	x[HEX];
	char	sign[3];
	int		ord;
	int		w;

	fstr->uni.uin = va_arg(*arg, unsigned int);
	if (!(fstr->base[10]))
		ft_set_base_x(fstr->base, 'x');
	else if (fstr->base[10] == 'A')
		ft_set_base_lit_x(fstr->base + 10);
	ft_set_sign_x(fstr, sign);
	ord = ft_put_digit_hex(x, fstr->uni.uin, HEX, fstr->base);
	ord = (fstr->uni.uin == 0 && fstr->prec == 0) ? 0 : ord;
	w = ft_max(fstr->prec, ord) + 2 * (sign[0] != 0);
	if (fstr->wdth > w && !(ft_flag(fstr->flag, MINUS)))
	{
		ft_check_ox(fstr, sign, 0);
		ft_print_int_width(fstr, sign + 2, fstr->wdth - w);
	}
	ft_check_ox(fstr, sign, 1);
	ft_print_int_prec(fstr, sign + 2, fstr->prec - ord);
	ft_buf_str(x + HEX - ord, ord, fstr);
	if (fstr->wdth > w)
		ft_print_int_width(fstr, sign + 2, fstr->wdth - w);
}

void		ft_printf_x_h(t_fstr *fstr, va_list *arg)
{
	char	x_h[HEX_H];
	char	sign[3];
	int		ord;
	int		w;

	fstr->uni.uin = (unsigned int)((unsigned short int)va_arg(*arg, unsigned int));
	if (!(fstr->base[10]))
		ft_set_base_x(fstr->base, 'x');
	else if (fstr->base[10] == 'A')
		ft_set_base_lit_x(fstr->base + 10);
	ft_set_sign_x(fstr, sign);
	ord = ft_put_digit_hex(x_h, fstr->uni.uin, HEX_H, fstr->base);
	ord = (fstr->uni.uin == 0 && fstr->prec == 0) ? 0 : ord;
	w = ft_max(fstr->prec, ord) + 2 * (sign[0] != 0);
	if (fstr->wdth > w && !(ft_flag(fstr->flag, MINUS)))
	{
		ft_check_ox(fstr, sign, 0);
		ft_print_int_width(fstr, sign + 2, fstr->wdth - w);
	}
	ft_check_ox(fstr, sign, 1);
	ft_print_int_prec(fstr, sign + 2, fstr->prec - ord);
	ft_buf_str(x_h + HEX_H - ord, ord, fstr);
	if (fstr->wdth > w)
		ft_print_int_width(fstr, sign + 2, fstr->wdth - w);
}

void		ft_printf_x_hh(t_fstr *fstr, va_list *arg)
{
	char	x_hh[HEX_HH];
	char	sign[3];
	int		ord;
	int		w;

	fstr->uni.uin = (unsigned int)((unsigned char)va_arg(*arg, unsigned int));
	if (!(fstr->base[10]))
		ft_set_base_x(fstr->base, 'x');
	else if (fstr->base[10] == 'A')
		ft_set_base_lit_x(fstr->base + 10);
	ft_set_sign_x(fstr, sign);
	ord = ft_put_digit_hex(x_hh, fstr->uni.uin, HEX_HH, fstr->base);
	ord = (fstr->uni.uin == 0 && fstr->prec == 0) ? 0 : ord;
	w = ft_max(fstr->prec, ord) + 2 * (sign[0] != 0);
	if (fstr->wdth > w && !(ft_flag(fstr->flag, MINUS)))
	{
		ft_check_ox(fstr, sign, 0);
		ft_print_int_width(fstr, sign + 2, fstr->wdth - w);
	}
	ft_check_ox(fstr, sign, 1);
	ft_print_int_prec(fstr, sign + 2, fstr->prec - ord);
	ft_buf_str(x_hh + HEX_HH - ord, ord, fstr);
	if (fstr->wdth > w)
		ft_print_int_width(fstr, sign + 2, fstr->wdth - w);
}