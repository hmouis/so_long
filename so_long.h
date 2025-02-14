/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:34:51 by hmouis            #+#    #+#             */
/*   Updated: 2025/02/14 14:01:12 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
#define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

int check_valide_c(char **arr, int len, char c);
int check_rectangular(char **arr, int len);
int check_lines(char **arr, int len);
char **read_file(int fd, int len);
int count_lines(int fd);
int check_error(int ac, char **av);
char	*ft_strcpy(char *str, char *after_newline);
char	*get_line(char *str, char *after_newline);
char	*fill_str(char *str, int fd);
char	*check_after_nl(char **str);
char	*ft_strchr(char *s, char c);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_strcpy_nl(char *line, char *str);


# endif
