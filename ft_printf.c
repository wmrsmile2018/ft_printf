#include "ft_printf.h"

static void	match_fstr(t_fstr *fstr, char *current)
{
	char *tmp;

	tmp = NULL;
	while (tmp != current)
	{
		tmp = current;
		current = current + ft_match_flags(fstr, current);
		current = current + ft_match_width(fstr, current);
		current = current + ft_match_prec(fstr, current);
		current = current + ft_match_length(fstr, current);
	}
	ft_match_type(fstr, current);
}

static int print_not_format(char *format, t_fstr *fstr)
{
	int i;

	i = 0;
	while (format[i] && format[i] != '%')
		i++;
	ft_buf_str(format, i, fstr);
	return (i);
}

static void	print_format(t_fstr *fstr, char *start,
						va_list *arg, void (**f)(t_fstr *, va_list *))
{
	int type_num;

	ft_set_fstr(fstr);
	match_fstr(fstr, start);
	type_num = (fstr->flag >> TYPE);
	if (type_num > 0)
		f[type_num](fstr, arg);
}

int			ft_printf(const char *format, ...)
{
	va_list arg;
	t_fstr	fstr;
	void 	(*func[32])(t_fstr *, va_list *arg);

	ft_init_n_set(func, &fstr);
	va_start(arg, format);
	while (format && *format)
	{
		if (*format == '%')
		{
			print_format(&fstr, (char *)format + 1, &arg, func);
			format = format + fstr.strl;
		}
		else
			format = format + print_not_format((char *) format, &fstr);
	}
	ft_buf_print(&fstr);
	va_end(arg);
	return (format != NULL ? fstr.prin : -1);
}