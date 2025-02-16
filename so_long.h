/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:34:51 by hmouis            #+#    #+#             */
/*   Updated: 2025/02/16 14:58:01 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_collect_position
{
	int column;
	int row;
	struct s_collect_position *next;
}	t_collect_pos;

typedef struct s_player_position
{
	int column;
	int row;
	struct s_player_position *next;
}	t_player_pos;

typedef struct s_exit_position
{
	int column;
	int row;
	struct s_exit_position *next;
}	t_exit_pos;




t_collect_pos *get_collectible_pos(char **arr, char c, int len);
t_exit_pos *get_exit_position(char **arr, char c, int len);
t_player_pos *get_player_pos(char **arr, char c, int len);
t_exit_pos *creat_e_node(int column, int row);
t_player_pos *creat_p_node(int column, int row);
void free_lst(t_collect_pos **lst);
t_collect_pos *creat_c_node(int column, int row);
void add_node(t_collect_pos **lst, t_collect_pos *node);
t_collect_pos *last_node(t_collect_pos *lst);
int check_char(char c, char *str);
int check_map(char **arr, int len);
int		check_valide_c(char **arr, int len, char c);
int		check_rectangular(char **arr, int len);
int		check_lines(char **arr, int len);
char	**read_file(int fd, int len);
int		count_lines(int fd);
int		check_error(int ac, char **av);
char	*ft_strcpy(char *str, char *after_newline);
char	*get_line(char *str, char *after_newline);
char	*fill_str(char *str, int fd);
char	*check_after_nl(char **str);
char	*ft_strchr(char *s, char c);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_strcpy_nl(char *line, char *str);

#endif
