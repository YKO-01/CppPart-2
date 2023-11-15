# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 08:29:44 by ayakoubi          #+#    #+#              #
#    Updated: 2023/11/15 13:19:21 by ayakoubi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main 


###############	COMPILATION	#################

CPP	=	c++
CPPFLAGS =	-Wall -Wextra -Werror -std=c++98

###########	SRC & OBJ	#################

SRC	:=	main Bureaucrat AForm ShrubberyCreationForm RobotomyRequestForm PresidentialPardonForm Intern

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
