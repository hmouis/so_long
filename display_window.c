/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 00:30:48 by hmouis            #+#    #+#             */
/*   Updated: 2025/03/02 05:00:33 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void put_image(t_game *game, int *i, int *j)
{
	if (game->map[(*i)][(*j)] == 'P')
				mlx_put_image_to_window(game->mlx, game->win,game->p_img, (*j) * 64, (*i) * 64);
	else if (game->map[(*i)][(*j)] == '1')
		mlx_put_image_to_window(game->mlx, game->win,game->w_img, (*j) * 64, (*i) * 64);
	else if (game->map[(*i)][(*j)] == '0')
				mlx_put_image_to_window(game->mlx, game->win,game->b_img, (*j) * 64, (*i) * 64);
	else if (game->map[(*i)][(*j)] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,game->c_img, (*j) * 64, (*i) * 64);
	else if (game->map[(*i)][(*j)] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,game->e_img, (*j) * 64, (*i) * 64);
}

void display_map(t_game *game)
{
	int (i), (j);

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			put_image(game, &i, &j);
			j++;
		}
		i++;
	}
}
