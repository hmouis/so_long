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

int check_lines(char **arr, int len)
{
	int i;
	char c;
	int length;

	i = 0;
	c = arr[0][0];
	length = ft_strlen(arr[0]);
	while (arr[0][i])
	{
		if (c != arr[0][i] || c != arr[len][i])
		{
			write (1, "Error\ndefine the wall whit a different characters\n",50);
			return (0);
		}
		i++;
	}
	i = 0;
	while (i <= len)
	{
		if (c != arr[i][0] || c != arr[i][length - 1])
		{
			write (1, "Error\ndefine the wall whit a different characters\n",50);
			return (0);
		}
		i++;
	}
	return (1);
}

int check_rectangular(char **arr, int len)
{
	if (len + 1 >= ft_strlen(arr[0]))
	{
		write (1, "Error\nthe map is not rectangular\n", 33);
		return (0);
	}
	return (1);
}

int check_valide_c(char **arr, int len, char c)
{
	int (length), (i), (j), (count);

	i = 1;
	count = 0;
	length = ft_strlen(arr[0]);
	while (i < len)
	{
		j = 1;
		while (j < length - 1)
		{
			if (c == arr[i][j])
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

