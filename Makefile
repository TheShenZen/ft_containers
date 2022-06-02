# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 17:07:59 by seciurte          #+#    #+#              #
#    Updated: 2022/06/01 15:47:29 by seciurte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.cpp

INC		=	./

NAME	=	span

OBJS	=	$(SRCS:.cpp=.o)

CPPFLAGS	+=	-Wall -Werror -Wextra -std=c++98

CC		=	c++

all:	$(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:		fclean
	@make

%.o : %.cpp
	@$(CC) $(CPPFLAGS) -I $(INC) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CC) $(CPPFLAGS) -I $(INC) $(OBJS) -o $(NAME)

.PHONY: all clean fclean re remove
