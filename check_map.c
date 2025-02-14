/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:49:15 by hmouis            #+#    #+#             */
/*   Updated: 2025/02/14 13:58:43 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_length(char **arr)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(arr[i]);
	while (arr[i])
	{
		if (len != ft_strlen(arr[i]))
		{
			i = 0;
			while (arr[i++])
				free(arr[i]);
			free(arr);
			write (1, "Error\nthe lines have a different length",38);
			return (0);
		}
		i++;
	}
	return (1);
}
