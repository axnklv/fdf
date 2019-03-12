/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:57:31 by elchrist          #+#    #+#             */
/*   Updated: 2019/03/12 19:30:46 by elchrist         ###   ########.fr       */
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

int		ft_count_words(char *s, char sep)
{
	int	i;
	int	quantity;

	quantity = 0;
	i = 0;
	while (s[i] && s[i] == sep)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != sep)
			i++;
		quantity++;
		while (s[i] && s[i] == sep)
			i++;
	}
	return (quantity);
}
