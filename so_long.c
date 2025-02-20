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
	int		j;

	arr = malloc(sizeof(char *) * (len + 1));
	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (free(line), NULL);
	while (line)
	{
		arr[i] = line;
		j = 0;
		while (arr[i][j] != '\n')
			j++;
		arr[i][j] = '\0';
		i++;
		line = get_next_line(fd);
	}
	arr[i] = NULL;
	return (arr);
}

int	count_lines(int fd)
{
	char(*line_1), (*lines);
	int(j), (len);
	len = 0;
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
			return (0);
		}
		len++;
		lines = get_next_line(fd);
	}
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

int	main(int ac, char **av)
{
	int		fd;
	int		len;
	char	**arr;
	t_player_pos *p_pos;
	t_exit_pos *e_pos;
	t_collect_pos *c_pos;

	fd = check_error(ac, av);
	len = count_lines(fd);
	close(fd);
	if (len == 0)
	{
		return (1);
	}
	fd = check_error(ac, av);
	arr = read_file(fd, len);
	if (!check_lines(arr, len) || !check_rectangular(arr, len))
		return (1);
	if (check_valide_c(arr, len, 'E') != 1 || check_valide_c(arr, len, 'P') != 1 || check_valide_c(arr, len, 'C') <= 0)
	{
		write(1, "Error\nu need to follow do ruls\n", 31);
		return (1);
	}
	if (!check_map(arr, len))	
		return (1);
	p_pos = get_player_pos(arr, 'P', len);
	printf("player position :\ncolumn = %d\nrew = %d\n", p_pos->column, p_pos->row);
	e_pos = get_exit_position(arr, 'E', len); 
	printf("exit position :\ncolumn = %d\nrew = %d\n", e_pos->column, e_pos->row);
	c_pos = get_collectible_pos(arr, 'C', len);
	printf("collectible position :\n");
	while (c_pos)
	{
		printf("column = %d\nrew = %d", c_pos->column, c_pos->row);
		c_pos = c_pos->next;
	}


	return (0);
}





















