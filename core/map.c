/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:19:36 by apylypen          #+#    #+#             */
/*   Updated: 2024/02/29 21:19:41 by apylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*get_map(int fd)
{
	char	*line_map;
	char	*buff;
	int		char_count;
	char	*tmp_buff;

	line_map = ft_strdup("");
	buff = ft_strdup("");
	char_count = gnl(fd, &line_map);
	if (char_count > 0)
	{
		tmp_buff = buff;
		while (char_count > 0)
		{
			buff = ft_strjoin(buff, line_map);
			free(tmp_buff);
			free(line_map);
			line_map = ft_strdup("");
			char_count = gnl(fd, &line_map);
			tmp_buff = buff;
		}
		return (buff);
	}
	ft_error("Error\nWrong lecture map\n");
	return (NULL);
}

void	*free_map(t_data *data)
{
	int		i;

	i = 0;
	while (data->map[i] != NULL)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
	return (0);
}

char	**parse_map(int fd, t_data *data)
{
	int		i;

	i = 1;
	data->map = ft_split(get_map(fd), '\n');
	check_content(data);
	if (!(check_format(data->map)))
		return (free_map(data));
	if (!(check_line(data->map[0], data->content.wall)))
		return (free_map(data));
	while (data->map[i] != NULL)
	{
		if (!(check_column(data->map[i], data->content.wall, data)))
			return (free_map(data));
		else if (!(check_other(data->map[i], &(data->content))))
			return (free_map(data));
		i++;
	}
	data->height = i;
	if (!(check_line(data->map[i - 1], data->content.wall)))
		return (free_map(data));
	return (data->map);
}

char	**map_core(char **str, t_data *data)
{
	int		fd;

	fd = 0;
	data->map = NULL;
	if (ft_strchr(str[1], ".ber") == 0)
		return (ft_error("Error\nCorrect format map is not founded\n"));
	else
	{
		fd = open(str[1], O_RDONLY);
		if (fd > 0)
			data->map = parse_map(fd, data);
		else
			return (ft_error("Error\nFailed to open file\n"));
		if ((data->content.count_c == 0 || data->content.count_e != 1
				|| data->content.count_p != 1) && data->map != NULL)
		{
			free_map(data);
			return (ft_error(
					"Error\nNeed 1 Player/Exit and at least 1 Object\n"));
		}
	}
	return (data->map);
}
