/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:57:31 by elchrist          #+#    #+#             */
/*   Updated: 2019/03/14 21:39:26 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	it_is_error(void)
{
	write(1, "error\n", 6);
	exit(1);
}

void	invalid_map(void)
{
	write(1, "invalid map!\n", 13);
	exit(1);
}

void	usage(void)
{
	write(1, "usage: ./fdf <FILE>\n", 20);
	exit(0);
}

void	map_error(int error)
{
	if (error == 0 || error == -1)
		invalid_map();
}

void	ft_init_env(t_point *elem);

// int		ft_atoi_base(const char *s, int base)
// {
// 	long	n;
// 	int		np;
//
// 	n = 0;
// 	np = 1;
// 	while (*s == '\n' && *s == '\t' && *s == '\v' &&
// 			*s == ' ' && *s == '\f' && *s == '\r')
// 		++s;
// 	*s == '-' ? np = -1 : 0;
// 	*s == '-' || *s == '+' ? ++s : 0;
// 	while ((*s >= '0' && *s <= '9') ||
// 			(*s >= 'A' && *s <= 'F') ||
// 			(*s >= 'a' && *s <= 'f'))
// 	{
// 		n *= base;
// 		*s >= '0' && *s <= '9' ? n += *s - 48 : 0;
// 		*s >= 'A' && *s <= 'F' ? n += *s - 55 : 0;
// 		*s >= 'a' && *s <= 'f' ? n += *s - 87 : 0;
// 		++s;
// 	}
// 	return ((int)n * np);
// }
// int		ft_count_words(char *s, char sep)
// {
// 	int	i;
// 	int	quantity;
//
// 	quantity = 0;
// 	i = 0;
// 	while (s[i] && s[i] == sep)
// 		i++;
// 	while (s[i])
// 	{
// 		while (s[i] && s[i] != sep)
// 			i++;
// 		quantity++;
// 		while (s[i] && s[i] == sep)
// 			i++;
// 	}
// 	return (quantity);
// }
