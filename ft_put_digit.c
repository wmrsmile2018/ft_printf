int	ft_put_digit_dec(char *dig, unsigned int a, int size)
{
	int i;

	i = size;
	while (a || i == size)
	{
		--i;
		*(dig + i) = (char)(a % 10) + '0';
		a /= 10;
	}
	return (size - i);
}

int	ft_put_digit_oct(char *dig, unsigned int a, int size)
{
	int i;

	i = size;
	while (a || i == size)
	{
		--i;
		*(dig + i) = (char)((a & 7) + '0');
		a = a >> 3;
	}
	return (size - i);
}

int ft_put_digit_hex(char *dig, unsigned int a, int size, char *base)
{
	int i;

	i = size;
	while (a || i == size)
	{
		--i;
		*(dig + i) = *(base + (a & 15));
		a = a >> 4;
	}
	return (size - i);
}