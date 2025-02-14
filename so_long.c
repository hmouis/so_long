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

	fd = check_error(ac, av);





	return (0);
}
