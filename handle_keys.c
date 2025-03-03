/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:59:38 by hmouis            #+#    #+#             */
/*   Updated: 2025/02/21 14:24:05 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int key, t_game *game)
{
	if (key == XK_a)
	{
		game->map[game->p_y][game->p_x] = '0'; 
		game->map[game->p_y][game->p_x - 1] = 'P'; 
		game->p_x -= 1;
	}
	else if (key == XK_d)
	{
		game->map[game->p_y][game->p_x] = '0'; 
		game->map[game->p_y][game->p_x + 1] = 'P'; 
		game->p_x += 1;
	}
	else if (key == XK_w)
	{
		game->p_y -= 1;
	}
	else if (key == XK_s)
	{
		game->p_y += 1;
	}
	else if (key == XK_Escape)
		exit(0);
	return (1);
}
