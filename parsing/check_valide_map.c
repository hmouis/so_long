/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valide_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:42:07 by hmouis            #+#    #+#             */
/*   Updated: 2025/02/17 18:42:12 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_way(char **arr, int x, int y)
{
	int (row), (column);
	row = 0;
	while (arr[row])
		row++;
	column = ft_strlen(arr[0]);
	if (x < 0 || y < 0 || x >= column || y >= row || arr[y][x] == 'D'
		|| arr[y][x] == '1')
		return ;
	arr[y][x] = 'D';
	check_way(arr, x - 1, y);
	check_way(arr, x + 1, y);
	check_way(arr, x, y - 1);
	check_way(arr, x, y + 1);
}
