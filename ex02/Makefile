NAME = PmergeMe

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 

SRCS = main.cpp PmergeMe.cpp
OBJS = $(SRCS:.cpp=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re