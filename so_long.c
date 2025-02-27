/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:43:00 by hmouis            #+#    #+#             */
/*   Updated: 2025/02/16 15:00:46 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_file(int fd, int len)
{
	char	**arr;
	int		i;
	char	*line;

	arr = malloc(sizeof(char *) * (len + 1));
	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (free(line), NULL);
	while (line)
	{
		arr[i] = ft_strdup(line);
		i++;
		free (line);
		line = get_next_line(fd);
	}
	arr[i] = NULL;
	return (arr);
}

int	count_lines(int fd)
{
	char (*line_1), (*lines);
	int (j), (len);

	len = 1;
	line_1 = get_next_line(fd);
	lines = get_next_line(fd);
	if (!line_1 || !lines || ft_strlen(line_1) < 3 || line_1[0] == '\n')
	{
		write(1, "Error\nThe file is empty,or the lines have different lengths.\n", 62);
		return (free(line_1), free(lines), 0);
	}
	j = ft_strlen(line_1);
	while (lines)
	{
		if ((j != ft_strlen(lines)) || ft_strlen(lines) < 3 || lines[0] == '\n')
		{
			write(1, "Error\nThe file is empty,or the lines have different lengths.\n", 62);
			return (free(lines), free(line_1), 0);
		}
		len++;
		free(lines);
		lines = get_next_line(fd);
	}
	free(line_1);
	return (len);
}

int	check_error(int ac, char **av)
{
	int	fd;

	if (ac == 1)
	{
		write(1, "Error\nplease enter an argument\n", 31);
		exit(1);
	}
	if (ac != 2)
	{
		write(1, "Error\ntoo much arguments\n", 25);
		exit(1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\n", 6);
		perror(av[1]);
		exit(1);
	}
	return (fd);
}

void free_arr(char ***arr)
{
	int i;

	i = 0;
	while ((*arr)[i])
	{
		free((*arr)[i]);
		i++;
	}
	free(*arr);
}

int check_map_c(char **str)
{
	int (i), (j);

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'C' || str[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		fd;
	int		len;
	char	**arr;
	int n_c;
	t_player_pos *p;
	t_exit_pos *e;
	t_collect_pos *c;

	p = NULL;
	c = NULL;
	e = NULL;
	fd = check_error(ac, av);
	len = count_lines(fd);
	close(fd);
	if (len == 0)
		return (1);
	fd = check_error(ac, av);
	arr = read_file(fd, len);
	if (!check_lines(arr, len) || !check_rectangular(arr, len))
		return (free_arr(&arr), 1);
	if (check_valide_c(arr, len, 'E') != 1 || check_valide_c(arr, len, 'P') != 1 
		|| check_valide_c(arr, len, 'C') <= 0)
	{
		write(1, "Error\nu need to follow do ruls\n", 31);
		return (free_arr(&arr), 1);
	}
	if (!check_map(arr, len))	
		return (free_arr(&arr), 1);
	n_c = check_valide_c(arr, len, 'C');
	e = get_exit_position(arr, 'E', len);
	c = get_collectible_pos(arr, 'E', len);
	p = get_player_pos(arr, 'E', len);

	check_way(arr, p->x, p->y);
	if (!check_map_c(arr))
	{

		write(1,"Error\ninvalide map\n", 19);
		free(e);
		free(p);
		free_lst(&c);
		return (free_arr(&arr), 1);
	}

	free(e);
	free(p);
	free_lst(&c);
	free_arr(&arr);
	return (0);
}

