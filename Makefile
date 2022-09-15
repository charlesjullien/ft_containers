NAME = TESTER

COMPILER = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 #-g3 -fsanitize=address

SRCS = main_tester.cpp

OBJ = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(COMPILER) $(FLAGS) -I. -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJ)
		$(COMPILER) $(FLAGS) -o $(NAME) $(OBJ)

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:	all clean fclean re make