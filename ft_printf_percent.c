#include "ft_printf.h"

void	ft_printf_percent(t_fstr *fstr, va_list *arg)
{
    arg = NULL;//something to use arg
    if (fstr->wdth > 1 && !(ft_flag(fstr->flag, MINUS)))
        ft_print_str_width(fstr, 1);
	ft_buf_str("%", 1, fstr);
    if (fstr->wdth > 1)
        ft_print_str_width(fstr, 1);
}