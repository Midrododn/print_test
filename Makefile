NAME = libftprintf.a

SRC = ft_dectohex ft_fun_num ft_fun_str ft_itoa ft_printf ft_utoa

C_SRC = $(addsuffix .c , $(SRC))

O_SRC = $(addsuffix .o , $(SRC))

all: $(NAME) 

$(NAME):
	@cc -Wall -Werror -Wextra -c $(C_SRC)
	@ar -cvq libftprintf.a $(O_SRC)

clean: 
	rm -f ft*.o
	rm -f tst1

fclean:
	@rm -f $(O_SRC)
	@rm -f libftprintf.a

re: fclean $(NAME)
