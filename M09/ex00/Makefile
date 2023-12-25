# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 12:57:06 by ayakoubi          #+#    #+#              #
#    Updated: 2023/12/25 12:27:51 by ayakoubi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# __ VAR & COMPILATION _________________________________________________________
# ==============================================================================
NAME		=	btc
CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98
OBJDIR		=	objs
SRC			:=	main ParsingFile MyException BitcoinExchange
OBJ			:=	$(addprefix $(OBJDIR)/, $(addsuffix .o, $(SRC)))
SRC			:=	$(addsuffix .cpp, $(SRC))

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
$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	@$(CPP) $(CPPFLAGS) -c $< -o $@
	@echo "$(YELLOW) compile >>>> $< $(RESET)"

all:	$(NAME)

$(NAME) :	$(OBJ)
	@$(CPP) $(CPPFLAGS) $^ -o $(NAME)
	@@echo "$(GREEN) ------ Built success ------ $(RESET)"

clean:
	@echo "$(RED) REMOVED OBJ $(RESET)"
	@rm -rf *.o

fclean:	clean
	@echo "$(RED) REMOVED $(NAME) $(RESET)"
	@rm -rf $(NAME)

re:	fclean	all

.PHONY: all clean fclean
