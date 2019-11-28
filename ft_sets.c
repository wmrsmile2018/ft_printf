#include "ft_printf.h"

int		ft_flag(int flag, int position)
{
	return (flag & (1 << position));
}

void	ft_set_fstr(t_fstr *fstr)
{
	fstr->wdth = 0;
	fstr->prec = -1;
	fstr->strl = 1;
	fstr->flag = 0;
	fstr->uni.ullin = 0;
}

static void	set_int_type_func(void (**f)(t_fstr *, va_list *))
{
	f[4] = &ft_printf_d_i; //d or i with no width flags
	f[5] = &ft_printf_d_i_ll;
	f[6] = &ft_printf_d_i_l;
	f[7] = &ft_printf_d_i_h;
	f[8] = &ft_printf_d_i_hh;
	f[9] = &ft_printf_o;
	f[10] = &ft_printf_o_ll;
	f[11] = &ft_printf_o_l;
	f[12] = &ft_printf_o_h;
	f[13] = &ft_printf_o_hh;
	f[14] = &ft_printf_u;
	f[15] = &ft_printf_u_ll;
	f[16] = &ft_printf_u_l;
	f[17] = &ft_printf_u_h;
	f[18] = &ft_printf_u_hh;
	f[19] = &ft_printf_xx;
	f[20] = &ft_printf_xx_ll;
	f[21] = &ft_printf_xx_l;
	f[22] = &ft_printf_xx_h;
	f[23] = &ft_printf_xx_hh;
	f[24] = &ft_printf_x;
	f[25] = &ft_printf_x_ll;
	f[26] = &ft_printf_x_l;
	f[27] = &ft_printf_x_h;
	f[28] = &ft_printf_x_hh;
}

void ft_init_n_set(void (**f)(t_fstr *, va_list *), t_fstr *fstr)
{
	fstr->base[10] = 0;
	fstr->prin = 0;
	fstr->idx = 0;
	f[0] = NULL;
	f[1] = &ft_printf_char;
	f[2] = &ft_printf_string;
//	f[3] = &ft_printf_pointer;
	set_int_type_func(f);
//	f[29] = &ft_printf_f;
//	f[30] = &ft_printf_f_L;
	f[31] = &ft_printf_percent;
}