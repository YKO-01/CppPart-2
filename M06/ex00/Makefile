# ***************** COMPILATION ******************
NAME	=	main
CPP	=	c++
CPPFLAGS=	-Wall -Wextra -Werror -std=c++98

SRC	:=	main ScalarConverter
OBJ	:=	$(addsuffix .o, $(SRC))
SRC	:=	$(addsuffix .cpp, $(SRC))

# *****************	RULES	*****************
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
