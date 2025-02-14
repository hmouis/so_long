/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:43:00 by hmouis            #+#    #+#             */
/*   Updated: 2025/02/14 09:43:19 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **read_file(int fd, int len)
{
	char **arr;
	int i;
	char *line;

	arr = malloc(sizeof(char *) * (len + 1));
	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (free (line), NULL);
	while (line)
	{
		arr[i] = line;
		i++;
		line = get_next_line(fd);
	}
	arr[i] = NULL;
	return (arr);
}

int count_lines(int fd)
{
	int len;
	char *line;

	len = 0;
	line = get_next_line(fd);
	if (!line)
		return (free(line), 0);
	while (line)
	{
		len++;
		line = get_next_line(fd);
	}
	return (len);
}

int check_error(int ac, char **av)
{
	int fd;

	if (ac == 1)
	{
		write (1, "Error\nplease enter an argument\n",31);
		exit(1);
	}
	if (ac != 2)
	{
		write (1, "Error\ntoo much arguments\n",25);
		exit(1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		write (1, "Error\n",6);
		perror (av[1]);
		exit(1);
	}
	return fd;
}

int main(int ac, char**av)
{
	int fd;
	int len;
	char **arr;

	fd = check_error(ac, av);
	len = count_lines(fd);
	close(fd);
	if (len == 0)
	{
		write(1, "Error\nempty map\n", 16);
		return (1);
	}
	fd = check_error(ac, av);
	arr = read_file(fd, len);




	return (0);
}
