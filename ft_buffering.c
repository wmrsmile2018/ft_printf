#include "ft_printf.h"

void	ft_buf_print(t_fstr *fstr)
{
	write(1, fstr->buf, fstr->idx);
	fstr->prin += fstr->idx;
	fstr->idx = 0;
}

void	ft_buf_str(char *str, int size, t_fstr *fstr)
{
	while (size > 0)
	{
		while (fstr->idx < BUF_SIZE && size > 0)
		{
			fstr->buf[fstr->idx] = *str;
			fstr->idx++;
			str++;
			size--;
		}
		if (size > 0)
			ft_buf_print(fstr);
	}
}

void	ft_buf_smb(char smb, int size, t_fstr *fstr)
{
	while (size > 0)
	{
		while (fstr->idx < BUF_SIZE && size > 0)
		{
			fstr->buf[fstr->idx] = smb;
			fstr->idx++;
			size--;
		}
		if (size > 0)
			ft_buf_print(fstr);
	}
}