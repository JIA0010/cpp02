NAME		=	a.out
CC			=	c++
SRCS 		=   main.cpp Fixed.cpp
FLAGS		=	-Wall -Wextra -Werror -std=c++98 -pedantic-errors
OBJS 		=  	$(SRCS:.cpp=.o)
RM			=	rm -rf


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:		fclean all

format:
	$(if $(SRCS), clang-format --style=Google -i $(SRCS))

.PHONY:	all clean fclean re format