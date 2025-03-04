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

void	generate_items(t_game *game)
{
	int (img_width), (i), (img_hight);
	i = 0;
	while (game->map[i])
		i++;
	game->rows = i;
	game->colums = ft_strlen(game->map[0]);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->colums * 64, game->rows * 64,
			"so_long");
	if (!game->mlx || !game->win)
		free_all(game);
	game->e_img = mlx_xpm_file_to_image(game->mlx, "./textures/e.xpm",
			&img_width, &img_hight);
	game->c_img = mlx_xpm_file_to_image(game->mlx, "./textures/c.xpm",
			&img_width, &img_hight);
	game->p_img = mlx_xpm_file_to_image(game->mlx, "./textures/p.xpm",
			&img_width, &img_hight);
	game->w_img = mlx_xpm_file_to_image(game->mlx, "./textures/w.xpm",
			&img_width, &img_hight);
	game->b_img = mlx_xpm_file_to_image(game->mlx, "./textures/b.xpm",
			&img_width, &img_hight);
	if (!game->e_img || !game->p_img || !game->c_img
		|| !game->w_img || !game->e_img)
		free_all(game);
}

void	put_image(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->p_img, j * 64, i
			* 64);
	else if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->w_img, j * 64, i
			* 64);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->b_img, j * 64, i
			* 64);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->c_img, j * 64, i
			* 64);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->e_img, j * 64, i
			* 64);
}

void	display_map(t_game *game)
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
