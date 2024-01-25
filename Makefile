name = libftprintf.a
cc = cc
flags = -Wall -Wextra -Werror
src = ft_printf.c ft_printf_funcs_1.c ft_printf_funcs_2.c
obj = $(src:.c=.o)

all : $(name)

$(name) : $(obj)
	ar rcs $(name) $(obj)

%.o : %.c
	$(cc) $(flags) -c $< -o $@

clean :
	rm -f $(obj)

fclean : clean
	rm -f $(name)

re : fclean all

.PHONY: all clean fclean re
