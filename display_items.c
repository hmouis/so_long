/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_items.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:57:47 by hmouis            #+#    #+#             */
/*   Updated: 2025/03/03 17:17:31 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_exit(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->e_img, x * 64, y * 64);
}

void	display_col(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->c_img, x * 64, y * 64);
}

void	display_player(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->p_img, x * 64, y * 64);
}

void	display_background(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->b_img, x * 64, y * 64);
}

void	display_move(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				display_player(game, j, i);
			else if (game->map[i][j] == '0')
				display_background(game, j, i);
			j++;
		}
		i++;
	}
}
