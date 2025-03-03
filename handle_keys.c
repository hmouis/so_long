/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:59:38 by hmouis            #+#    #+#             */
/*   Updated: 2025/03/03 18:08:20 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int key, t_game *game)
{
	if (key == XK_a)
		handle_a(game);
	else if (key == XK_d)
			handle_d(game);
	else if (key == XK_w)
			handle_w(game);
	else if (key == XK_s)
			handle_s(game);
	else if (key == XK_Escape)
		exit(0);
	return (1);
}

void handle_a(t_game *game)
{
	if (game->p_x > 1 && game->map[game->p_y][game->p_x - 1] != '1' && game->map[game->p_y][game->p_x - 1] != 'E')
	{
		game->map[game->p_y][game->p_x] = '0'; 
		game->map[game->p_y][game->p_x - 1] = 'P'; 
		game->p_x -= 1;
		display_move(game);
	}
}

void handle_d(t_game *game)
{
	if (game->p_x < game->colums - 2 && game->map[game->p_y][game->p_x + 1] != '1' && game->map[game->p_y][game->p_x + 1] != 'E')
	{
		game->map[game->p_y][game->p_x] = '0'; 
		game->map[game->p_y][game->p_x + 1] = 'P'; 
		game->p_x += 1;
		display_move(game);
	}
}

void handle_w(t_game *game)
{
	if (game->p_y > 1 && game->map[game->p_y - 1][game->p_x] != '1' && game->map[game->p_y - 1][game->p_x] != 'E')
	{
		game->map[game->p_y][game->p_x] = '0';
		game->map[game->p_y  - 1][game->p_x] = 'P'; 
		game->p_y -= 1;
		display_move(game);
	}

}

void handle_s(t_game *game)
{
	if (game->p_y < game->rows - 2 && game->map[game->p_y + 1][game->p_x] != '1' && game->map[game->p_y + 1][game->p_x] != 'E')
	{
		game->map[game->p_y][game->p_x] = '0'; 
		game->map[game->p_y  + 1][game->p_x] = 'P'; 
		game->p_y += 1;
		display_move(game);
	}

}





























