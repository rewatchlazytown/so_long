/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 23:03:00 by apylypen          #+#    #+#             */
/*   Updated: 2024/02/29 23:03:01 by apylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strchr(char *str, char *cmp)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (cmp[y] == '\0' && str[i] == '\0')
		return (1);
	while (str[i])
	{
		while (str[i + y] == cmp[y] && str[i + y] && cmp[y])
			y++;
		if (cmp[y] == '\0' && str[i + y] == '\0')
			return (1);
		else
			y = 0;
		i++;
	}
	return (0);
}
