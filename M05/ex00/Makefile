# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 08:31:44 by ayakoubi          #+#    #+#              #
#    Updated: 2023/11/15 10:37:24 by ayakoubi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat 


###############	COMPILATION	#################

CPP	=	c++
CPPFLAGS =	-Wall -Wextra -Werror -std=c++98

###########	SRC & OBJ	#################

SRC	:=	main Bureaucrat

OBJ	:=	$(addsuffix .o, $(SRC))
SRC	:=	$(addsuffix .cpp, $(SRC))


###########	RULES 		##############3


%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME) :	$(OBJ)
	$(CPP) $(CPPFLAGS) $^ -o $(NAME)

clean:
	rm -rf *.o

fclean:	clean
	rm -rf $(NAME)

re:	fclean	all

.PHONY: all clean fclean
