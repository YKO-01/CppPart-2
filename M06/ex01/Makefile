# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 11:34:45 by ayakoubi          #+#    #+#              #
#    Updated: 2023/12/25 09:12:06 by ayakoubi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# __ VAR & COMPLATION __________________________________________________________
# ==============================================================================
NAME	=	main
CPP	=	c++
CPPFLAGS=	-Wall -Wextra -Werror -std=c++98

SRC	:=	main Serializer
OBJ	:=	$(addsuffix .o, $(SRC))
SRC	:=	$(addsuffix .cpp, $(SRC))

# __ COLOR _____________________________________________________________________
# ==============================================================================
RED = \033[1;31m
GREEN = \033[1;32m
SPLASH = \033[5m
BLUE = \033[1;34m
YELLOW = \033[1;33m
RESET = \033[0m

# __ RULES _____________________________________________________________________
# ==============================================================================
%.o: %.cpp
	@$(CPP) $(CPPFLAGS) -c $< -o $@
	@echo "$(GREEN) [OK] $(RESET) $(YELLOW) compile >>>> $< $(RESET)"

all:	$(NAME)

$(NAME) :	$(OBJ)
	@$(CPP) $(CPPFLAGS) $^ -o $(NAME)
	@@echo "$(GREEN) ------ Done ------ $(RESET)"

clean:
	@echo "$(RED) REMOVED OBJ $(RESET)"
	@rm -rf *.o

fclean:	clean
	@echo "$(RED) REMOVED $(NAME) $(RESET)"
	@rm -rf $(NAME)

re:	fclean	all

.PHONY: all clean fclean
