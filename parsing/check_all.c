/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:34:49 by hmouis            #+#    #+#             */
/*   Updated: 2025/02/28 10:51:57 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_and_free(char **arr, int len)
{
	if (!check_lines(arr, len))
		return (0);
	if (count_items(arr, len, 'E') != 1 || count_items(arr, len, 'P') != 1
		|| count_items(arr, len, 'C') == 0)
	{
		ft_putstr("Error\ninvalid map\n");
		return (0);
	}
	if (!check_map(arr, len))
		return (0);
	return (1);
}

int	check_and_free_2(t_game *game, char **arr)
{
	player_pos(game);
	check_way(arr, game->p_x, game->p_y);
	if (!check_map_c(arr))
	{
		ft_putstr("Error\ninvalid map\n");
		return (0);
	}
	return (1);
}

int	check_map_c(char **str)
{
	int (i), (j);
	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'C' || str[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	free_all(t_game *game)
{
	free_arr(&game->map);
	mlx_destroy_image(game->mlx, game->p_img);
	mlx_destroy_image(game->mlx, game->e_img);
	mlx_destroy_image(game->mlx, game->c_img);
	mlx_destroy_image(game->mlx, game->w_img);
	mlx_destroy_image(game->mlx, game->b_img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}
