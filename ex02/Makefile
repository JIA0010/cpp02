NAME = a.out
SRCS = main.cpp Fixed.cpp
FLAGS =   -Wall -Wextra -Werror -std=c++98 -pedantic-errors
OBJS = $(SRCS:.cpp=.o)


all : $(NAME)


$(NAME) : $(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re:		fclean all

format:
	$(if $(SRCS), clang-format --style=Google -i $(SRCS))

.PHONY:	all clean fclean re format