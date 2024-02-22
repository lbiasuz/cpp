NAME = iter

SRC = main.cpp

CC = c++
CFLAGS = -Wall -Wextra -Werror -Wconversion -std=c++98 -g

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re