# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 11:34:45 by ayakoubi          #+#    #+#              #
#    Updated: 2023/11/18 11:40:42 by ayakoubi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==============================================================================
NAME	=	main
CPP	=	c++
CPPFLAGS=	-Wall -Wextra -Werror -std=c++98

SRC	:=	main ScalarConverter
OBJ	:=	$(addsuffix .o, $(SRC))
SRC	:=	$(addsuffix .cpp, $(SRC))

# __ RULES _____________________________________________________________________
# ==============================================================================
%.o : %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(CPPFLAGS) $^ -o $@

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
