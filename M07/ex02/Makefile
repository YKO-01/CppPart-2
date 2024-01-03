# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 12:16:11 by ayakoubi          #+#    #+#              #
#    Updated: 2024/01/02 02:55:31 by ayakoubi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# __ VAR & COMPILATION _________________________________________________________
# ==============================================================================
NAME	=	main
CPP	=	c++
CPPFLAGS=	-Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

SRC	:=	main
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
	@@echo "$(GREEN) ------ DONE ------ $(RESET)"

clean:
	@echo "$(RED) REMOVED OBJ $(RESET)"
	@rm -rf *.o

fclean:	clean
	@echo "$(RED) REMOVED $(NAME) $(RESET)"
	@rm -rf $(NAME)

re:	fclean	all

.PHONY: all clean fclean

