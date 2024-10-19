NAME = rush-02
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c utils.c dict_parser.c number_to_word.c get_next_line.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

