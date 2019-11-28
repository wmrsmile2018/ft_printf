#include "ft_printf.h"

void	ft_printf_percent(t_fstr *fstr, va_list *arg)
{
	if(arg) {
		write(1, "%", 1);
		fstr->prin = fstr->prin + 1;
	}
}
 