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

int	handle_key(t_game *game, int key)
{
	if (game->p_x > 1 && key == 97)
		game->p_x -= 1;
	else if (game->p_x < (game->colums - 2) && key == 100)
		game->p_x += 1;
	else if (game->p_y > 1 && key == 119)
		game->p_y -= 1;
	else if (game->p_y < (game->rows - 2) && key == 115)
		game->p_y += 1;
	else if (key == 53)
		return (0);
	return (1);
}
