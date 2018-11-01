#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skarev <skarev@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/15 15:36:11 by skarev            #+#    #+#              #
#    Updated: 2018/10/15 15:36:12 by skarev           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = skarev.filler

CFLAG = -Wall -Wextra -Werror

SRCS = main.c algorithm.c free.c dop_1.c dop_2.c

LIBS = ./libft/libft.a

all: $(NAME)

$(NAME): $(SRCS)
	@make -C libft
	@gcc $(CFLAG) -o $(NAME) $(SRCS) $(LIBS)
	@gcc $(CFLAG) -o visual visual.c $(LIBS) -lcurses

clean:
		@make -C libft clean

fclean: clean
		@make -C libft fclean
		@/bin/rm -f $(NAME)
		@/bin/rm -f visual

re:		fclean all

.PHONY: all clean fclean re
