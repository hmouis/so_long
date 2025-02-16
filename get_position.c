/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:56:27 by hmouis            #+#    #+#             */
/*   Updated: 2025/02/16 15:11:39 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_exit_pos *get_exit_position(char **arr, char c, int len)
{
	int i;
	int j;
	t_exit_pos *e_pos;

	i = 1;
	e_pos = NULL;
	while (i < len)
	{
		j = 1;
		while (arr[i][j])
		{
			if (arr[i][j] == c)
			{
				e_pos = creat_e_node(j, i);
				return (e_pos);
			}
			j++;
		}
		i++;
	}
	return (e_pos);
}

t_collect_pos *get_collectible_pos(char **arr, char c, int len)
{
	int (i), (j), (r);
	t_collect_pos *c_pos;
	t_collect_pos *lst;

	lst = NULL;
	i = 1;
	r = 1;
	c_pos = NULL;
	while (i < len)
	{
		j = 1;
		while (arr[i][j])
		{
			if (arr[i][j] == c)
			{
				c_pos = creat_c_node(j, i);
				if (r == 1)
				{
					r = 0;
					lst = c_pos;
				}
				add_node(&lst, c_pos);
			}
			j++;
		}
		i++;
	}
	return (lst);
}

t_player_pos *get_player_pos(char **arr, char c, int len)
{
	int i;
	int j;
	t_player_pos *p_pos;

	i = 1;
	p_pos = NULL;
	while (i < len)
	{
		j = 1;
		while (arr[i][j])
		{
			if (arr[i][j] == c)
			{
				p_pos = creat_p_node(j, i);
				return (p_pos);
			}
			j++;
		}
		i++;
	}
	return (p_pos);
}
