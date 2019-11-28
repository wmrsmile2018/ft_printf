# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bannabel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/06 18:56:21 by bannabel          #+#    #+#              #
#    Updated: 2019/10/08 22:05:55 by bannabel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT_A = libft.a
H_DIR = ./
LIB_DIR = ./libft/
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_sets.c\
        ft_matching_format.c\
        ft_matching_length.c\
	    ft_printf_pointer.c\
	    ft_printf_string.c\
	  ft_printf_char.c\
	  ft_printf_d_i_n_h_hh.c\
	  ft_printf_d_i_u_ll.c\
	  ft_printf_d_i_u_l.c\
	  ft_printf_u_n_h_hh.c\
	  ft_printf_o_n_h_hh.c\
	  ft_printf_o_ll.c\
	  ft_printf_o_l.c\
	  ft_printf_xx_n_h_hh.c\
	  ft_printf_x_n_h_hh.c\
	  ft_printf_x_xx_ll.c\
	  ft_printf_x_xx_l.c\
	  ft_printf_percent.c\
	  ft_printf.c\
	  ft_int_addit_func.c\
	  ft_set_hex_alpha.c\
	  ft_buffering.c\
	  ft_put_digit.c\
	  ft_long_arithm.c\

OBJS = $(SRCS:%.c=%.o)

LIB = @make -C libft/

all: $(NAME)

$(NAME):$(OBJS)
	@echo "\033[92m___________________OBJ FILES CREATED___________________\033[0m"
	$(LIB)
	@echo "\033[92m____________________LIBFT.A CREATED____________________\033[0m"
	@echo Copying $(LIBFT_A) to root
	@cp $(LIB_DIR)$(LIBFT_A) .
	@echo Changing name $(LIBFT_A) to $(NAME)
	@mv $(LIBFT_A) $(NAME)
	@echo Merging: $(NAME) with $(LIBFT_A)
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[92m_________________________DONE!_________________________\033[0m"

clean:
	make clean -C $(LIB_DIR)
	rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(OBJS)
	make fclean -C $(LIB_DIR)

re: fclean all