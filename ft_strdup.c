/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 09:58:45 by hmouis            #+#    #+#             */
/*   Updated: 2025/02/23 09:59:14 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *s1)
{
	size_t	i;
	char	*arr;
	size_t	s1_len;
	int		j;

	s1_len = ft_strlen(s1);
	i = 0;
	j = 0;
	arr = (char *)malloc(sizeof(char) * s1_len + 1);
	if (arr == NULL)
		return (NULL);
	while (s1[j])
	{
		if (s1[j] == '\n')
			break ;
		else
			arr[i] = s1[j];
		i++;
		j++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_strdup1(char *s1)
{
	size_t	i;
	char	*arr;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	i = 0;
	arr = (char *)malloc(sizeof(char) * s1_len + 1);
	if (arr == NULL)
		return (NULL);
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

void	ft_error(char *s)
{
	ft_putstr(s);
	exit(0);
}
