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

int	ft_strlen1(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	if (s[i - 1] != '\n')
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (write(1, &s[i], 1) == -1)
			perror("Error\nwrite failed\n");
		i++;
	}
}

char	**copy_map(char **arr)
{
	char	**str;
	int		i;

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

void	ft_putchar(char c)
{
	if (write (1, &c, 1) == -1)
		perror("Error\nwrite faled\n");
}

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}
