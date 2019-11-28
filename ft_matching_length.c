#include "ft_printf.h"

static void	match_hh(t_fstr *fstr, char *current, int *i)
{
	if (*current == 'h')
	{
		fstr->flag |= (1 << SHORT_SHORT);
		*i = *i + 1;
	}
	else
		fstr->flag |= (1 << SHORT);
}

static void	match_ll(t_fstr *fstr, char *current, int *i)
{
	if (*current == 'l')
	{
		fstr->flag |= (1 << LONG_LONG);
		*i = *i + 1;
	}
	else
		fstr->flag |= (1 << LONG);
}

int			ft_match_length(t_fstr *fstr, char *current)
{
	//length bits start form 8th bit of flag 11111000: L, ll, l, h, hh; 0 == flag off, 1 == flag on
	int i;

	i = 0;
	while (current[i] == 'h' || current[i] == 'l' || current[i] == 'L')
	{
		if (current[i] == 'h')
			match_hh(fstr, current + 1, &i);
		else if (current[i] == 'l')
			match_ll(fstr, current + 1, &i);
		else if (current[i] == 'L')
			fstr->flag |= (1 << LONG_DOUBLE);
		i++;
	}
	fstr->strl = fstr->strl + i;
	return (i);
}