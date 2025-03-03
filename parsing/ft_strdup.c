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

#include "../so_long.h"

char	*ft_strdup(char *s1)
{
	size_t	i;
	char	*arr;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	i = 0;
	arr = (char *)malloc(sizeof(char) * s1_len + 1);
	if (arr == NULL)
		return (NULL);
	while (s1[i] != '\n')
	{
		arr[i] = s1[i];
		i++;
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


















