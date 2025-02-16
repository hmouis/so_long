/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:35:15 by hmouis            #+#    #+#             */
/*   Updated: 2025/02/16 15:53:19 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_exit_pos *creat_e_node(int column, int row)
{
	t_exit_pos *node;

	node = malloc(sizeof(t_exit_pos));
	if (!node)
		return (NULL);
	node->column = column;
	node->row = row;
	node->next = NULL;
	return (node);
}
t_player_pos *creat_p_node(int column, int row)
{
	t_player_pos *node;

	node = malloc(sizeof(t_player_pos));
	if (!node)
		return (NULL);
	node->column = column;
	node->row = row;
	node->next = NULL;
	return (node);
}
t_collect_pos *creat_c_node(int column, int row)
{
	t_collect_pos *node;

	node = malloc(sizeof(t_collect_pos));
	if (!node)
		return (NULL);
	node->column = column;
	node->row = row;
	node->next = NULL;
	return (node);
}

void add_node(t_collect_pos **lst, t_collect_pos *node)
{
	t_collect_pos *last;

	if (!lst ||  !node)
		return ;
	if ((*lst)->next)
	{
		last = last_node(*lst);
		last->next = node;
	}
	else
		*lst = node;
}

t_collect_pos *last_node(t_collect_pos *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void free_lst(t_collect_pos **lst)
{
	t_collect_pos *save;

	save = NULL;
	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		*lst = (*lst)->next;
		free(save);
		*lst = save;
	}
}
