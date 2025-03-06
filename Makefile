NAME = so_long

SRC = get_next_line.c get_next_line_utils.c so_long.c check_map.c get_position.c check_valide_map.c ft_strdup.c ft_putstr.c check_all.c display_window.c handle_keys.c display_items.c 

CC = cc
CFLAGS = -Wall -Wextra -g 
#-Werror
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@

%.o: %.c
	$(CC) $(CFLAGS) -Imlx_linux -O3 -c $? -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
