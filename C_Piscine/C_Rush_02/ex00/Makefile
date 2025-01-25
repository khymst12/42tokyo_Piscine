CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = readfile.c
OBJS = $(SRCS:.c=.o)
NAME = rush-02

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re
