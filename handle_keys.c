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
		if (handle_a(game))
			game->col--;
	if (key == XK_d)
		if (handle_d(game))
			game->col--;
	if (key == XK_w)
		if (handle_w(game))
			game->col--;
	if (key == XK_s)
		if (handle_s(game))
			game->col--;
	if (key == XK_Escape)
		free_all(game);
	return (1);
}

int	handle_a(t_game *game)
{
	int	remainder;

	remainder = 0;
	if (game->p_x > 1 && game->map[game->p_y][game->p_x - 1] != '1'
		&& (game->map[game->p_y][game->p_x - 1] != 'E' || game->col <= 0))
	{
		game->map[game->p_y][game->p_x] = '0';
		if (game->map[game->p_y][game->p_x - 1] == 'C')
			remainder = 1;
		if (game->map[game->p_y][game->p_x - 1] == 'E' && game->col <= 0)
		{
			game->moves++;
			ft_putnbr(game->moves);
			ft_putstr("\n");
			free_all(game);
		}
		game->map[game->p_y][game->p_x - 1] = 'P';
		game->p_x -= 1;
		game->moves++;
		ft_putnbr(game->moves);
		ft_putstr("\n");
		display_move(game);
	}
	return (remainder);
}

int	handle_d(t_game *game)
{
	int	r;

	r = 0;
	if (game->p_x < game->colums - 2 && game->map[game->p_y][game->p_x
		+ 1] != '1' && (game->map[game->p_y][game->p_x + 1] != 'E'
			|| game->col <= 0))
	{
		game->map[game->p_y][game->p_x] = '0';
		if (game->map[game->p_y][game->p_x + 1] == 'C')
			r = 1;
		if (game->map[game->p_y][game->p_x + 1] == 'E' && game->col <= 0)
		{
			game->moves++;
			ft_putnbr(game->moves);
			ft_putstr("\n");
			free_all(game);
		}
		game->map[game->p_y][game->p_x + 1] = 'P';
		game->p_x += 1;
		game->moves++;
		ft_putnbr(game->moves);
		ft_putstr("\n");
		display_move(game);
	}
	return (r);
}

int	handle_w(t_game *game)
{
	int	r;

	r = 0;
	if (game->p_y > 1 && game->map[game->p_y - 1][game->p_x] != '1'
		&& (game->map[game->p_y - 1][game->p_x] != 'E' || game->col <= 0))
	{
		game->map[game->p_y][game->p_x] = '0';
		if (game->map[game->p_y - 1][game->p_x] == 'C')
			r = 1;
		if (game->map[game->p_y - 1][game->p_x] == 'E' && game->col <= 0)
		{
			game->moves++;
			ft_putnbr(game->moves);
			ft_putstr("\n");
			free_all(game);
		}
		game->map[game->p_y - 1][game->p_x] = 'P';
		game->p_y -= 1;
		game->moves++;
		ft_putnbr(game->moves);
		ft_putstr("\n");
		display_move(game);
	}
	return (r);
}

int	handle_s(t_game *game)
{
	int	r;

	r = 0;
	if (game->p_y < game->rows - 2 && game->map[game->p_y + 1][game->p_x] != '1'
		&& (game->map[game->p_y + 1][game->p_x] != 'E' || game->col <= 0))
	{
		game->map[game->p_y][game->p_x] = '0';
		if (game->map[game->p_y + 1][game->p_x] == 'C')
			r = 1;
		if (game->map[game->p_y + 1][game->p_x] == 'E' && game->col <= 0)
		{
			game->moves++;
			ft_putnbr(game->moves);
			ft_putstr("\n");
			free_all(game);
		}
		game->map[game->p_y + 1][game->p_x] = 'P';
		game->p_y += 1;
		game->moves++;
		ft_putnbr(game->moves);
		ft_putstr("\n");
		display_move(game);
	}
	return (r);
}
