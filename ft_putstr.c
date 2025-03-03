/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:33:22 by hmouis            #+#    #+#             */
/*   Updated: 2025/03/02 05:09:30 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (write(1, &s[i], 1) == -1)
			perror("write failed\n");
		i++;
	}
}

char **copy_map(char **arr)
{
	int (i);
	char **str;

	i = 0;
	while (arr[i])
		i++;
	str = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (arr[i])
	{
		str[i] = ft_strdup1(arr[i]);
		i++;
	}
	str[i] = NULL;
	return (str);
}
