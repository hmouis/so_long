/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:34:51 by hmouis            #+#    #+#             */
/*   Updated: 2025/03/03 18:01:46 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game_info
{
	int		rows;
	int		col;
	int		done;
	int		moves;
	int		colums;
	void	*mlx;
	void	*win;
	void	*p_img;
	void	*c_img;
	void	*e_img;
	void	*w_img;
	void	*b_img;
	char	**map;
	int		p_x;
	int		p_y;
}			t_game;

void free_all(t_game *game);
int		handle_a(t_game *game);
int		handle_d(t_game *game);
int		handle_s(t_game *game);
int		handle_w(t_game *game);
void		display_background(t_game *game, int x, int y);
void		display_move(t_game *game);
void		display_col(t_game *game, int x, int y);
void		display_exit(t_game *game, int x, int y);
void		display_player(t_game *game, int x, int y);
void		generate_items(t_game *game);
void		run_my_game(t_game *game);
void		player_pos(t_game *game);
void		generate_items(t_game *game);
void		put_image(t_game *game, int i, int j);
void		display_map(t_game *game);
char		**copy_map(char **arr);
char		*ft_strdup1(char *str);
int			check_and_free(char **arr, int len);
int			check_and_free_2(t_game *game, char **arr);
int			check_map_c(char **str);
void		free_arr(char ***arr);
void		ft_putstr(char *s);
char		*ft_strdup(char *s1);
void		check_way(char **arr, int x, int y);
int			handle_key(int key, t_game *game);
int			check_char(char c, char *str);
int			check_map(char **arr, int len);
int			count_items(char **arr, int len, char c);
int			check_rectangular(char **arr, int len);
int			check_lines(char **arr, int len);
char		**read_file(int fd, int len);
int			count_lines(int fd);
int			check_error(int ac, char **av);
char		*ft_strcpy(char *str, char *after_newline);
char		*get_line(char *str, char *after_newline);
char		*fill_str(char *str, int fd);
char		*check_after_nl(char **str);
char		*ft_strchr(char *s, char c);
int			ft_strlen(char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*get_next_line(int fd);
char		*ft_strcpy_nl(char *line, char *str);

#endif
