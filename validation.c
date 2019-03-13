/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:39:51 by elchrist          #+#    #+#             */
/*   Updated: 2019/03/13 19:26:47 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_width(char **split_line)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		reading(int fd)
{
	char	*line;
	int		height;
	int		width;
	char	**split_line;
	t_pixel	*grid;

	height = 0;
	grid = 0;
	get_next_line(fd, &line);
	split_line = ft_strsplit(line, ' ');
	grid_function(&grid, height, split_line);
	//grid_function - some func that applies our projections on display
	width = check_width(split_line);
	height = 1;
	while (get_next_line(fd, &line))
	{
		split_line = ft_strsplit(line ' ');
		if (width != check_width(split_line))
			invalid_map();
		else
			grid_function(&grid, height, split_line);
		height++;
	}
	//function(&grid, height, width);
	//function - some func that works with color and applies it on map
	return (0);
}

int		letter_to_int(char hex)
{
	if (hex == 'A' || hex == 'a')
		return (10);
	if (hex == 'B' || hex == 'b')
		return (11);
	if (hex == 'C' || hex == 'c')
		return (12);
	if (hex == 'D' || hex == 'd')
		return (13);
	if (hex == 'E' || hex == 'e')
		return (14);
	if (hex == 'F' || hex == 'f')
		return (15);
	return (0);
}
//
// int		hex_to_int(char hex)
// {
// 	int	i;
// 	int	l;
// 	int	s;
//
// 	s = 0;
// 	i = 0;
// 	l = ft_strlen(str) - 1;
// 	while (str[i] != 0)
// 		if (str[i++] == ',')
// 		{
// 			i = 0;
// 			while (str[l] != 'x')
// 			{
// 				if (str[l] >= 48 & str[l] <= 57)
// 					s = s + (str[l] - 48) * pow(16, i);
// 				else if ((str[l] >= 65 & str[l] <= 70) ||
// 				(str[l] >= 97 & str[l] <= 102))
// 					s = s + letter_to_int(str[l]) * pow(16, i);
// 				l--;
// 				i++;
// 			}
// 			break ;
// 		}
// 	return (s);
// }

// в main'е сделать вызов
// if (!reading(fd)) => is_is_error();
