/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:20:47 by apylypen          #+#    #+#             */
/*   Updated: 2024/02/29 21:20:50 by apylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_content(t_cnt *content)
{
	content->exit = 'E';
	content->cow = 'P';
	content->wall = '1';
	content->space = '0';
	content->milk = 'C';
	content->count_p = 0;
	content->count_e = 0;
	content->count_c = 0;
}

void	set_img(t_data *data)
{
	data->img.height = 80;
	data->img.width = 80;
	data->img.texture = "./rsrc/texture.xpm";
	data->img.wall = "./rsrc/wall.xpm";
	data->img.milk = "./rsrc/milk.xpm";
	data->img.cow = "./rsrc/cow.xpm";
	data->img.exit = "./rsrc/exit.xpm";
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr, data->img.wall,
			&(data->img.width), &(data->img.height));
	data->img.img_texture = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.texture, &(data->img.width), &(data->img.height));
	data->img.img_exit = mlx_xpm_file_to_image(data->mlx_ptr, data->img.exit,
			&(data->img.width), &(data->img.height));
	data->img.img_milk = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.milk, &(data->img.width), &(data->img.height));
	data->img.img_cow = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.cow, &(data->img.width), &(data->img.height));
}
