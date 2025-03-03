NAME = so_long

SRC = parsing/get_next_line.c parsing/get_next_line_utils.c so_long.c parsing/check_map.c  parsing/get_position.c parsing/check_valide_map.c parsing/ft_strdup.c ft_putstr.c parsing/check_all.c display_window.c handle_keys.c display_items.c 

CC = cc
CFLAGS = -Wall -Wextra -Werror -g 
#-fsanitize=address 
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
