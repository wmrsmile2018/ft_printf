#include "ft_printf.h"

void	ft_mantis_array(char *buf, unsigned long long mnt)
{
	unsigned long long carry;
	unsigned long long digit;
	int i;

	carry = 10;
	i = 0;
	while (i < F_LIMIT)
	{
		while (carry < mnt && i < F_LIMIT)
		{
			carry *= 10;
			buf[i] = '0';
			i++;
		}
		digit = carry / mnt;
		carry = carry - mnt * digit;
		buf[i] = (char)digit + '0';
		i++;
		carry *= 10;
	}
	buf[i] = 0;
}

void	reverse_array(char *arr1, char *arr2)
{
	int i;

	i = ft_strlen(arr1);
	while (--i >= 0)
	{
		*arr2 = arr1[i];
		arr2++;
	}
}

void	ft_mult_array_num(char *buf, char *arr, int num)
{
	int i;
	int carry;
	char tmp[F_LIMIT];

	ft_bzero(tmp, F_LIMIT);
	ft_bzero(buf, F_LIMIT);
	reverse_array(arr, tmp);
	i = 0;
	carry = 0;
	while (tmp[i])
	{
		carry = (int)(tmp[i] - '0') * num + carry;
		tmp[i] = (char)(carry % 10) + '0';
		carry /= 10;
		i++;
	}
	while (carry > 0)
	{
		tmp[i] = (char)(carry % 10) + '0';
		carry /= 10;
		i++;
	}
	reverse_array(tmp, buf);
}

void	ft_exp_array(char *buf, int e)
{
	int i = 0;
}