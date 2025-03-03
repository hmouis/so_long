/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 00:30:48 by hmouis            #+#    #+#             */
/*   Updated: 2025/03/03 17:08:10 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void run_my_game(t_game *game)*/
/*{*/
/*	int i;*/
/**/
/*	int (img_width), (img_hight);*/
/*	i = 0;*/
/*	while (game->map[i])*/
/*		i++;*/
/*	game->rows = i;*/
/*	game->colums = ft_strlen(game->map[0]);*/
/*	game->mlx = mlx_init();*/
/*	if (ft_strlen(game->map[0]) > 30)*/
/*		ft_putstr("Error\nmap is too big\n");*/
/*	game->win = mlx_new_window(game->mlx, game->colums * 64, game->rows * 64, "so_long");*/
/*	game->e_img = mlx_xpm_file_to_image(game->mlx,"./texture/exit.xpm", &img_width, &img_hight);*/
/*	game->c_img = mlx_xpm_file_to_image(game->mlx,"./texture/collectables.xpm", &img_width, &img_hight);*/
/*	game->p_img = mlx_xpm_file_to_image(game->mlx,"./texture/player.xpm", &img_width, &img_hight);*/
/*	game->w_img = mlx_xpm_file_to_image(game->mlx,"./texture/wall.xpm", &img_width, &img_hight);*/
/*	game->b_img = mlx_xpm_file_to_image(game->mlx,"./texture/background.xpm", &img_width, &img_hight);*/
/*	display_map(game);*/
/*	mlx_hook(game->win,2, 1L << 0, handle_key, game);*/
/*	mlx_loop(game->mlx);*/
/*}*/

void generate_items(t_game *game)
{
	int (img_width),(i), (img_hight);

		i = 0;
	while (game->map[i])
		i++;
	game->rows = i;
	game->colums = ft_strlen(game->map[0]);
	game->mlx = mlx_init();
	if (ft_strlen(game->map[0]) > 30)
		ft_putstr("Error\nmap is too big\n");
	game->win = mlx_new_window(game->mlx, game->colums * 64, game->rows * 64, "Hello world!");
	game->e_img = mlx_xpm_file_to_image(game->mlx,"./texture/exit.xpm", &img_width, &img_hight);
	game->c_img = mlx_xpm_file_to_image(game->mlx,"./texture/collectables.xpm", &img_width, &img_hight);
	game->p_img = mlx_xpm_file_to_image(game->mlx,"./texture/player.xpm", &img_width, &img_hight);
	game->w_img = mlx_xpm_file_to_image(game->mlx,"./texture/wall.xpm", &img_width, &img_hight);
	game->b_img = mlx_xpm_file_to_image(game->mlx,"./texture/background.xpm", &img_width, &img_hight);
}

void put_image(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win,game->p_img, j * 64, i * 64);
	else if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win,game->w_img, j * 64, i * 64);
	else if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win,game->b_img, j * 64, i * 64);
	else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,game->c_img, j * 64, i * 64);
	else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,game->e_img, j * 64, i * 64);
}

void display_map(t_game *game)
{
	int (i), (j);

	i = 0;
	generate_items(game);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			put_image(game, i, j);
			j++;
		}
		i++;
	}
}


















