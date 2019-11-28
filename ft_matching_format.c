#include "ft_printf.h"

int	ft_match_flags(t_fstr *fstr, char *current)
{
	//flag bits in (flag) start from first bit: 11111000: -, +, 'space', 0, #
	int i;

	i = 0;
	while (current[i] == '-' || current[i] == '+'
		|| current[i] == ' ' || current[i] == '0' || current[i] == '#')
	{
		if (current[i] == '-')
			fstr->flag |= (1 << MINUS);
		else if (current[i] == '+')
			fstr->flag |= (1 << PLUS);
		else if (current[i] == ' ')
			fstr->flag |= (1 << SPACE);
		else if (current[i] == '0')
			fstr->flag |= (1 << NOLL);
		else
			fstr->flag |= (1 << HASH);
		i++;
	}
	fstr->strl = fstr->strl + i;
	return (i);
}


int	ft_match_width(t_fstr *fstr, char *current)
{
	int i;

	i = 0;
	if ((ft_isdigit(*current)) == 1)
	{
		fstr->wdth = ft_atoi((const char *)current);
		while ((ft_isdigit(*current)) == 1)
		{
			current++;
			i++;
		}
	}
	fstr->strl = fstr->strl + i;
	return (i);
}

int	ft_match_prec(t_fstr *fstr, char *current)
{
	//default prec = -1 (cause 0 has another effect)
	int i;

	i = 1;
	if (*current != '.')
		return (0);
	current++;
	fstr->prec = ((ft_isdigit(*current)) == 1) ? ft_atoi((const char *)current) : 0;
	while ((ft_isdigit(*current)) == 1)
	{
		current++;
		i++;
	}
	fstr->strl = fstr->strl + i;
	return (i);
}

static	int wflag(int f) //returns addition to the type value depending on the width flag. ll has more priority than l, h...
{
	int i;

	i = 1;
	while (i < INT_WFLAGS_NUMBER)
	{
		if (f & 1)
			break;
		f = f >> 1;
		i++;
	}
	return (i < INT_WFLAGS_NUMBER ? i : 0); // 0 == no width, 1 == ll, 2 == l, 3 == h, 4 == hh
}

int		ft_match_type(t_fstr *fstr, char *current)
{
	//order of type numbers = 1-10: csp diouXx f %, 0 == no matches. Type number starts from 16th bit of (flag)
	if (*current == 'd' || *current == 'i')
		fstr->flag |= ((4 + wflag(fstr->flag >> LONG_LONG)) << TYPE);
	else if (*current == 's')
		fstr->flag |= (2 << TYPE);
	else if (*current == 'f')
		fstr->flag |= (29 << TYPE);
	else if (*current == 'p')
		fstr->flag |= (3 << TYPE);
	else if (*current == 'u')
		fstr->flag |= ((4 + INT_WFLAGS_NUMBER * 2 + wflag(fstr->flag >> LONG_LONG)) << TYPE);
	else if (*current == 'c')
		fstr->flag |= (1 << TYPE);
	else if (*current == 'X')
		fstr->flag |= ((4 + INT_WFLAGS_NUMBER * 3 + wflag(fstr->flag >> LONG_LONG)) << TYPE);
	else if (*current == 'x')
		fstr->flag |= ((4 + INT_WFLAGS_NUMBER * 4 + wflag(fstr->flag >> LONG_LONG)) << TYPE);
	else if (*current == 'o')
		fstr->flag |= ((4 + INT_WFLAGS_NUMBER + wflag(fstr->flag >> LONG_LONG)) << TYPE);
	else if (*current == '%')
		fstr->flag |= (31 << TYPE);
	fstr->strl = ((fstr->flag >> TYPE) > 0) ? fstr->strl + 1 : fstr->strl;
	return (0);
}