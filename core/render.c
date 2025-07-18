/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:19:52 by apylypen          #+#    #+#             */
/*   Updated: 2024/02/29 21:19:55 by apylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_background(t_data *data)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		while (data->map[y][i] != '\0')
		{
			if (data->map[y][i] == data->content.wall)
				print_img(data, data->img.img_wall, i, y);
			if (data->map[y][i] == data->content.space)
				print_img(data, data->img.img_texture, i, y);
			i++;
		}
		i = 0;
		y++;
	}
}

void	render_other(t_data *data)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		while (data->map[y][i])
		{
			if (data->map[y][i] == data->content.milk)
				print_img(data, data->img.img_milk, i, y);
			if (data->map[y][i] == data->content.cow)
			{
				data->pos.x = i * data->img.width;
				data->pos.y = y * data->img.height;
				print_img(data, data->img.img_cow, i, y);
			}
			if (data->map[y][i] == data->content.exit)
				print_img(data, data->img.img_exit, i, y);
			i++;
		}
		i = 0;
		y++;
	}
}

int	render(t_data *data)
{
	render_background(data);
	render_other(data);
	return (0);
}

void	core_render(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx_ptr,
			(data->width * data->img.width), (data->height * data->img.height),
			"so_long");
	if (data->mlx_win == NULL)
	{
		free(data->mlx_ptr);
		return ;
	}
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, &key_press, data);
	mlx_hook(data->mlx_win, 17, 0, &end, data);
	mlx_loop(data->mlx_ptr);
	end(data);
}

void	print_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img,
		data->img.width * x, data->img.height * y);
}
