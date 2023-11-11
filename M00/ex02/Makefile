# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 08:29:44 by ayakoubi          #+#    #+#              #
#    Updated: 2023/10/21 11:56:27 by ayakoubi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main 


###############	COMPILATION	#################

CPP	=	c++
CPPFLAGS =	#-Wall -Wextra -Werror -std=c++98

###########	SRC & OBJ	#################

SRC	:=	main Bureaucrat AForm ShrubberyCreationForm

OBJ	:=	$(addsuffix .o, $(SRC))
SRC	:=	$(addsuffix .c, $(SRC))


###########	RULES 		##############3


%.o: %.c
	$(CPP) $(CPPFLAGS) $< -c $@

all:	$(NAME)

$(NAME) :	$(OBJ)
	$(CPP) $(CPPFLAGS) -C $^ -o $(NAME)

clean:
	rm -rf *.o

fclean:	clean
	rm -rf $(NAME)

re:	fclean	all

.PHONY: all clean fclean
