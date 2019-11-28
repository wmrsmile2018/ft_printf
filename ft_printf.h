#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
//

# define BUF_SIZE 512
# define MINUS 0
# define PLUS 1
# define SPACE 2
# define NOLL 3
# define HASH 4

# define LONG_DOUBLE 8
# define LONG_LONG 9
# define LONG 10
# define SHORT 11
# define SHORT_SHORT 12

# define TYPE 16
# define INT_WFLAGS_NUMBER 5//no flag, ll, l, h, hh - number of flags is 5, flags may be added as bonuses, max value is 8

# define DEC 10
# define DEC_LL 19
# define DEC_ULL 20
# define DEC_L 19
# define DEC_UL 20
# define DEC_H 5
# define DEC_HH 3

# define OCT 11
# define OCT_LL 22
# define OCT_L 22
# define OCT_H 6
# define OCT_HH 3

# define HEX 8
# define HEX_LL 16
# define HEX_L 16
# define HEX_H 4
# define HEX_HH 2

# define F_LIMIT 20

typedef union	s_union
{
	int 		in;
	long int	lin;
	long long int	llin;
	unsigned int 		uin;
	unsigned long int	ulin;
	unsigned long long	ullin;
}				t_union;

typedef struct	s_fstr
{
	int 		idx; //buffer index
	int			prin; //counting printed symbols, starting value is 0
	int			flag; //00000000 flag bits (-, +, space, 0, #, ...), 11111000 length bits (L, ll, l, h, hh), next == type number
// type number order = (1-3: csp); (4-8: (di), 9-13: o, 14-18: u, 19-28: (Xx)); 29-30: f; 31: %; (0 == no matches, default)
	int			wdth; //minimum width, default value is 0
	int			prec; //maximum width, default value is -1
	int			strl; //length of valid format string, default is 1 (starting %)
	t_union		uni;
	char 		buf[BUF_SIZE];
	char		base[16];
}				t_fstr;

int				ft_printf(const char *format, ...);
int				ft_match_type(t_fstr *fstr, char *current);
int				ft_match_flags(t_fstr *fstr, char *current);
int				ft_match_width(t_fstr *fstr, char *current);
int				ft_match_prec(t_fstr *fstr, char *current);
int				ft_match_length(t_fstr *fstr, char *current);

int 			ft_put_digit_dec(char *dig, unsigned int a, int size);
int 			ft_put_digit_oct(char *dig, unsigned int a, int size);
int 			ft_put_digit_hex(char *dig, unsigned int a, int size, char *base);

void			ft_print_str_width(t_fstr *fstr, int l);
void			ft_printf_char(t_fstr *fstr, va_list *arg);
void			ft_printf_string(t_fstr *fstr, va_list *arg);
void			ft_printf_d_i(t_fstr *fstr, va_list *arg);
void			ft_printf_d_i_ll(t_fstr *fstr, va_list *arg);
void			ft_printf_d_i_l(t_fstr *fstr, va_list *arg);
void			ft_printf_d_i_h(t_fstr *fstr, va_list *arg);
void			ft_printf_d_i_hh(t_fstr *fstr, va_list *arg);
void			ft_printf_u(t_fstr *fstr, va_list *arg);
void			ft_printf_u_ll(t_fstr *fstr, va_list *arg);
void			ft_printf_u_l(t_fstr *fstr, va_list *arg);
void			ft_printf_u_h(t_fstr *fstr, va_list *arg);
void			ft_printf_u_hh(t_fstr *fstr, va_list *arg);
void			ft_printf_o(t_fstr *fstr, va_list *arg);
void			ft_printf_o_ll(t_fstr *fstr, va_list *arg);
void			ft_printf_o_l(t_fstr *fstr, va_list *arg);
void			ft_printf_o_h(t_fstr *fstr, va_list *arg);
void			ft_printf_o_hh(t_fstr *fstr, va_list *arg);
void			ft_printf_xx(t_fstr *fstr, va_list *arg);
void			ft_printf_xx_ll(t_fstr *fstr, va_list *arg);
void			ft_printf_xx_l(t_fstr *fstr, va_list *arg);
void			ft_printf_xx_h(t_fstr *fstr, va_list *arg);
void			ft_printf_xx_hh(t_fstr *fstr, va_list *arg);
void			ft_printf_x(t_fstr *fstr, va_list *arg);
void			ft_printf_x_ll(t_fstr *fstr, va_list *arg);
void			ft_printf_x_l(t_fstr *fstr, va_list *arg);
void			ft_printf_x_h(t_fstr *fstr, va_list *arg);
void			ft_printf_x_hh(t_fstr *fstr, va_list *arg);
void			ft_printf_percent(t_fstr *fstr, va_list *arg);
void		    ft_printf_pointer(t_fstr *fstr, va_list *arg);
void			ft_printf_f(t_fstr *fstr, va_list *arg);

int				ft_flag(int flag, int position);
void			ft_set_fstr(t_fstr *fstr);
void			ft_init_n_set(void (**f)(t_fstr *, va_list *), t_fstr *fstr);
void 			ft_print_int_width(t_fstr *fstr, char *sign, int w);
void			ft_print_int_prec(t_fstr *fstr, char *sign, int len);
void			ft_check_ox(t_fstr *fstr, char *sign, char flag);
void			ft_set_sign_x(t_fstr *fstr, char *sign);
void			ft_set_sign_xx(t_fstr *fstr, char *sign);
void 			ft_set_base_x(char *base, char c);
void 			ft_set_base_lit_x(char *base);
void 			ft_set_base_lit_xx(char *base);

void			ft_buf_smb(char smb, int size, t_fstr *fstr);
void			ft_buf_str(char *str, int size, t_fstr *fstr);
void			ft_buf_print(t_fstr *fstr);

void			ft_mantis_array(char *buf, unsigned long long mnt);
void			ft_mult_array_num(char *buf, char *arr, int num);

#endif