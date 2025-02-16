NAME = so_long

SRC = get_next_line.c get_next_line_utils.c so_long.c check_map.c control_nodes.c get_position.c

CC = cc
CFLAGS = -Wall -Wextra -g
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $? -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
