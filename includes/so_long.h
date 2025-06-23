/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 23:42:05 by apylypen          #+#    #+#             */
/*   Updated: 2024/02/29 23:42:07 by apylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

typedef struct img_s
{
	void	*img_texture;
	void	*img_cow;
	void	*img_exit;
	void	*img_wall;
	void	*img_milk;
	int		height;
	int		width;
	char	*cow;
	char	*texture;
	char	*wall;
	char	*milk;
	char	*exit;
}				t_img;

typedef struct cnt_s
{
	char	exit;
	char	milk;
	char	cow;
	char	wall;
	char	space;
	int		count_p;
	int		count_e;
	int		count_c;
}				t_cnt;

typedef struct pos_s
{
	int		x;
	int		y;
}				t_pos;

typedef struct data_s
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		width;
	int		height;
	char	**map;
	t_cnt	content;
	t_img	img;
	t_pos	pos;
	int		count;
}				t_data;

int		ft_strchr(char *str, char *cmp);
void	*ft_error(char *str);
int		ft_same_char(char *str);

int		ft_same_char(char *str);
char	*get_map(int fd);
char	**map_core(char **str, t_data *data);
int		chk_map(char **argv);

int		check_column(char *map_line, char col, t_data *data);
int		check_line(char *map_line, char wall);
int		check_other(char *map_line, t_cnt *content);
void	check_content(t_data *data);
int		check_format(char **map);
int		chk_collect(t_data *data);

void	set_img(t_data *data);
void	set_content(t_cnt *content);

void	core_render(t_data *data);
int		render(t_data *data);
void	render_other(t_data *data);
void	render_background(t_data *data);
void	render_down(t_data *data);
void	render_left(t_data *data);
void	render_right(t_data *data);
void	render_top(t_data *data);
void	print_img(t_data *data, void *img, int x, int y);

int		key_press(int keysym, t_data *data);
int		chk_collect(t_data *data);
int		end(t_data *data);

#endif
