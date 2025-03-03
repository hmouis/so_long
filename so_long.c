/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:43:00 by hmouis            #+#    #+#             */
/*   Updated: 2025/03/02 04:45:43 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_file(int fd, int len)
{
	char	**arr;
	int		i;
	char	*line;

	arr = malloc(sizeof(char *) * (len + 1));
	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (free(line), NULL);
	while (line)
	{
		arr[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	arr[i] = NULL;
	return (arr);
}

int	count_lines(int fd)
{
	char	*line_1;
	char	*lines;

	int (j), (len);
	len = 1;
	line_1 = get_next_line(fd);
	lines = get_next_line(fd);
	if (!line_1 || !lines || ft_strlen(line_1) < 3 || line_1[0] == '\n')
	{
		ft_putstr("Error\ninvalide map\n");
		return (free(line_1), free(lines), 0);
	}
	j = ft_strlen(line_1);
	while (lines)
	{
		if ((j != ft_strlen(lines)) || ft_strlen(lines) < 3 || lines[0] == '\n')
		{
			ft_putstr("Error\ninvalide map\n");
			return (free(lines), free(line_1), 0);
		}
		len++;
		free(lines);
		lines = get_next_line(fd);
	}
	return (free(line_1), len);
}

int	check_error(int ac, char **av)
{
	int	fd;

	if (ac == 1)
	{
		ft_putstr("Error\nplease enter an argument\n");
		exit(1);
	}
	if (ac != 2)
	{
		ft_putstr("Error\ntoo much arguments\n");
		exit(1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error\n");
		perror(av[1]);
		exit(1);
	}
	return (fd);
}

void	free_arr(char ***arr)
{
	int	i;

	i = 0;
	while ((*arr)[i])
	{
		free((*arr)[i]);
		i++;
	}
	free(*arr);
}
void run_my_game(t_game *game)
{
	int i;

	int (img_width), (img_hight);
	i = 0;
	while (game->map[i])
		i++;
	game->rows = i;
	game->colums = ft_strlen(game->map[0]);
	game->mlx = mlx_init();
	if (ft_strlen(game->map[0]) > 30)
		ft_putstr("Error\nmap is too big\n");
	game->win = mlx_new_window(game->mlx, game->colums * 64, game->rows * 64, "so_long");
	game->e_img = mlx_xpm_file_to_image(game->mlx,"./texture/exit.xpm", &img_width, &img_hight);
	game->c_img = mlx_xpm_file_to_image(game->mlx,"./texture/collectables.xpm", &img_width, &img_hight);
	game->p_img = mlx_xpm_file_to_image(game->mlx,"./texture/player.xpm", &img_width, &img_hight);
	game->w_img = mlx_xpm_file_to_image(game->mlx,"./texture/wall.xpm", &img_width, &img_hight);
	game->b_img = mlx_xpm_file_to_image(game->mlx,"./texture/background.xpm", &img_width, &img_hight);
	display_map(game);
	mlx_hook(game->win,2, 1L << 0, handle_key, game);
	mlx_loop(game->mlx);
}
int	main(int ac, char **av)
{
	int		(fd), (len);
	char	**arr;
	t_game game;


	fd = check_error(ac, av);
	len = count_lines(fd);
	close(fd);
	if (len == 0 || len > 16)
		return (1);
	fd = check_error(ac, av);
	arr = read_file(fd, len);
	game.map = copy_map(arr);
	if (!check_and_free(arr, len) || !check_and_free_2(&game, arr))
		return (free_arr(&arr), 1);
	run_my_game(&game);	
	/*while (game.map[i])*/
	/*	i++;*/
	/*game.rows = i;*/
	/*game.colums = ft_strlen(game.map[0]);*/
	/*game.mlx = mlx_init();*/
	/*game.win = mlx_new_window(game.mlx, game.colums * 64, game.rows * 64, "so_long");*/
	/*display_map(&game);*/
	/*free_arr(&arr);*/
	/*mlx_hook(game.win,2, 1L << 0, handle_key, &game);*/
	/*display_map(&game);*/
	/*free_arr(&arr);*/
	/*mlx_loop(game.mlx);*/
	return (0);
}
