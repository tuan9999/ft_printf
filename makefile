# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tuperera <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/19 18:16:53 by tuperera       #+#    #+#                 #
#    Updated: 2019/11/12 11:01:29 by tuperera      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c src/gen_fncts.c src/print_fncts.c src/util_fncts.c

OBJ = ft_printf.o gen_fncts.o print_fncts.o util_fncts.o

.PHONY: clean fclean re all

all: library ${NAME}

${NAME}:
	gcc -Wall -Wextra -Werror ${SRC} -c
	ar rc $(NAME) $(OBJ) libft/*.o

library:
	cd libft && $(MAKE) all && $(MAKE) bonus

clean:
	/bin/rm -f $(OBJ)
	cd libft && $(MAKE) clean

fclean: clean
	/bin/rm -f $(NAME)
	cd libft && $(MAKE) fclean

re: fclean all
