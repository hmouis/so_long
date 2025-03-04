/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:49:15 by hmouis            #+#    #+#             */
/*   Updated: 2025/02/16 13:56:03 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_lines(char **arr, int len)
{
	int (i), (length);
	i = 0;
	length = ft_strlen(arr[0]);
	while (arr[0][i])
	{
		if ('1' != arr[0][i] || '1' != arr[len - 1][i])
		{
			ft_putstr("Error\ndefine the wall whit a different characters\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < len)
	{
		if ('1' != arr[i][0] || '1' != arr[i][length - 1])
		{
			ft_putstr("Error\ndefine the wall whit a different characters\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	count_items(char **arr, int len, char c)
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
			{
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

int	check_char(char c, char *str)
{
	int	i;
	int	remainder;

	i = 0;
	remainder = 0;
	while (str[i])
	{
		if (str[i] == c)
			remainder = 1;
		i++;
	}
	if (remainder == 0)
		return (0);
	return (1);
}

int	check_map(char **arr, int len)
{
	int (i), (j);
	i = 1;
	while (i < len)
	{
		j = 1;
		while (arr[i][j])
		{
			if (!check_char(arr[i][j], "0PCE1"))
			{
				ft_putstr("Error\ninvalide character\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
