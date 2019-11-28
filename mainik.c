#include "ft_printf.h"

int main()
{
/*	char *f = "__%20.0s__%.-3+.-1s__";
	char *s = "aaaaa";
	char *s1 = "bbbbb";
	int a = printf(f, s, s1);
	printf("\n\n");
	int b = ft_printf(f, s, s1);
	printf("\n____%d_%d___\n", a, b);*/
//	ft_printf("___%-010.5s___\n", NULL);
//	printf("___%-010.5s___\n", NULL);
//	int x = 1234567;
//	printf("___%#p___\n", &x);
//	ft_printf("\n__%  00+-3%__", 'w');
//	printf("\n__%09.12d__", -123);
/*	int i = 3000000;
	char *s = "__%#-25.15x__\n";
	unsigned long int u = 1234323456;
	while (i > 0)
	{
		printf(s, u);
		i--;
	}*/
//	printf("%d__%d\n", i, j);
//	float i = 3.1323;
//	printf("\n__%.-2f__\n", i);
//	ft_printf("%u", i);
	char *num = "123";
	char result[F_LIMIT];
	ft_mult_array_num(result, num, 245);
	printf("___%s___\n", result);
	return (0);
}
