/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 23:00:33 by apylypen          #+#    #+#             */
/*   Updated: 2024/02/29 23:00:35 by apylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

long long int	ft_atoi(const char *str);
int				ft_isdigit(int c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char *str);
char			**ft_split(char *str, char sep);
int				ft_strchr(char *str, char *cmp);
char			*ft_strdup(char *str);
size_t			ft_strlen(const char *str);
char			*ft_strncpy(char *str, int nb);
int				gnl(int fd, char **str);
char			*ft_strjoin(char *s1, char *s2);

#endif
