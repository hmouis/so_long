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

int handle_key(char **arr, int key, t_player_pos *p)
{
	int row;
	int column;

	row = 0;
	while (arr[row])
		row++;
	column = ft_strlen (arr[0]);
	if (p->x > 1 && key == 97)
		p->x -= 1;
	else if (p->x < (column - 2) && key == 100)
		p->x += 1;
	else if (p->y > 1 && key == 119)
		p->y -= 1;
	else if (p->y < (row - 2) && key == 115)
		p->y += 1;
	else if (key == 53)
		return (0);
	return (1);
}
