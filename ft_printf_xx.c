#include "ft_printf.h"

static void set_base(char *base)
{
	char s;

	s = '0';
	while (s <= '9')
	{
		*base = s;
		s++;
		base++;
	}
	s = 'A';
	while (s <= 'F')
	{
		*base = s;
		s++;
		base++;
	}
	base = 0;
}

static int	put_digit(char *dig, unsigned int a)
{
	int i;
	char base[17];

	i = 8;
	set_base(base);
	while (a || i == 8)
	{
		--i;
		*(dig + i) = *(base + (a & 15));
		a = a >> 4;
	}
	return (8 - i);
}

void	ft_check_ox(t_fstr *fstr, char *sign, char flag)
{
	if (flag == 0 && *sign && fstr->prec == -1 && !(ft_flag(fstr->flag, MINUS))
		&& ft_flag(fstr->flag, NOLL))
	{
		write(1, sign, 2);
		*sign = 0;
		fstr->prin += 2;
		return ;
	}
	if (flag == 1 && *sign)
	{
		write(1, sign, 2);
		*sign = 0;
		fstr->prin += 2;
	}
}

static void	set_sign(t_fstr *fstr, char *sign)
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

void		ft_printf_xx(t_fstr *fstr, va_list *arg)
{
	char	X[9];
	char	sign[3];
	int		ord;
	int		w;

	X[8] = 0;
	fstr->uni.uin = va_arg(*arg, unsigned int);
	set_sign(fstr, sign);
	ord = put_digit(X, fstr->uni.uin);
	ord = (fstr->uni.uin == 0 && fstr->prec == 0) ? 0 : ord;
	w = ft_max(fstr->prec, ord) + 2 * (sign[0] != 0);
	if (fstr->wdth > w && !(ft_flag(fstr->flag, MINUS)))
	{
		ft_check_ox(fstr, sign, 0);
		ft_print_int_width(fstr, sign + 2, fstr->wdth - w);
	}
	ft_check_ox(fstr, sign, 1);
	ft_print_int_prec(fstr, sign + 2, fstr->prec - ord);
	write(1, X + 8 - ord, ord);
	fstr->prin += ord;
	if (fstr->wdth > w)
		ft_print_int_width(fstr, sign + 2, fstr->wdth - w);
}
