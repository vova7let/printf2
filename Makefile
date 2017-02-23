NAME = libftprintf.a

G = gcc

FLAG = -Wall -Wextra -Werror

SRC = 	ft_printf.c \
ft_conv_wch.c \
ft_itoa_base_bu.c \
ft_print_b.c \
ft_print_d.c \
ft_print_x.c \
ft_printf_help2.c \
ft_conv_wstr.c \
ft_itoa_base_m.c \
ft_print_big_x.c \
ft_print_o.c \
ft_print_x2.c \
ft_write_wchar.c \
ft_itoa_base.c \
ft_itoa_base_u.c \
ft_print_big_x2.c \
ft_print_s.c \
ft_printf.c \
help.c \
ft_itoa_base_b.c \
ft_nullstr.c \
ft_print_c.c \
ft_print_u.c \
ft_printf_help1.c
									
HDR = ft_printf.h

OBJ = $(SRC:.c=.o)

DEL = rm -f

all: $(NAME)

$(NAME) : $(OBJ)
		make -C libft
		ar -cru $(NAME) $(OBJ) libft/*.o
		ranlib $(NAME)
		@echo libftprintf.a has been made.

%.o: %.c
		$(G) $(CFLAGS) -c -o $@ $<

clean:
		make clean -C ./libft
		$(DEL) $(OBJ)
		@echo OBJ_libftprintf have been cleaned.

fclean: clean
		make fclean -C ./libft
		$(DEL) $(NAME)
		@echo libftprintf.a and *.o have been cleaned.

re: all
		make all -C ./libft
		@echo everything have been cleaned.
