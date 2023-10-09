NAME = main 


###############	COMPILATION	#################

CPP	=	c++
CPPFLAGS =	-Wall -Wextra -Werror -std=c++98

###########	SRC & OBJ	#################

SRC	:=	main

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
