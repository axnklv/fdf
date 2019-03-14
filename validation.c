/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:39:51 by elchrist          #+#    #+#             */
/*   Updated: 2019/03/14 21:40:40 by elchrist         ###   ########.fr       */
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

void	validation(t_point *elem)
{
	char	*line;
	int		fd;
	int		width;

	width = 0;
	get_next_line(fd, &line);
	split_line = ft_strsplit(line, ' ');
	width = check_width(split_line);
	elem->width = 0;
	elem->height = 0;
	fd = open(elem->file, O_RDONLY);
	if (fd < 0)
		it_is_error();
	while (get_next_line(fd, &line) == 1)
	{
		split_line = ft_strsplit(line, ' ');
		width = check_width(split_line);
		if (width != elem->width)
			invalid_map();
		elem->width = width;
		elem->height++;
		free(line);
	}
}

void	tab(t_point *point, char *s)
{
	int		i;
	int		color;

	i = -1;
	color = 0;
	while (s[++i])
		if (s[i] == ',')
			color++;
	if (color == 0)
	{
		point->z = ft_atoi(s);
		point->color = 16777215;
	}
	else if (color == 1)
	{
		i = 0;
		point->z = ft_atoi(s);
		while ((s[i] || s[i + 1] != 'x') && i++ > -1)
		{
			if (ft_strlen(s + i + 2) != 6)
				map_error(-1);
			point->color = ft_atoi_base(s + i + 2, 16);
		}
	}
}

void	tab_z(t_point *e, char *line, int i)
{
	char	**tmp;
	int		j;
	int		x;

    j = -1;
    x = 0;
    e->point[i] = (t_point*)malloc(sizeof(t_point) * (e->width + 1))));
    tmp = ft_strsplit(line, ' ');
    while (tmp[++j])
    {
        tab(&elem->point[i][j], tmp[j]);
        e->min_z = (e->point[i][j].z < e->min_z ? e->point[i][j].z : e->min_z);
        e->max_z = (e->point[i][j].z > e->max_z ? e->point[i][j].z : e->max_z);
        free(tmp[j]);
    }
    free(tmp);
}

void	reading(t_point *elem)
{
	char	*line;
	int		fd;
	int		i;
	int		j;

	i = 0;
	line = ft_strnew(1);
	validation(elem);
	fd = open(elem->file, O_RDONLY);
	if (fd < 0)
		it_is_error();
	elem->point = (t_point**)malloc(sizeof(t_point*) * (elem->height + 1));
	while (get_next_line(fd, &line) == 1)
	{
		j = -1;
		while (line[++j])
		{
			if ((ft_isdigit(s[i]) || (line[j] >= 65 && line[j] <= 70)
			|| (line[j] >= 97 && line[j] <= 102) || line[j] == ' ' ||
			line[j] == ',' || line[j] == '-' || line[j] == 'x') != 1)
				invalid_map();
		}
		tab_z(elem, line, i);
		i++;
	}
}

/*
	int main()
	{
		t_point *elem;

		reading(&elem);
	}
*/
// int		reading(int fd)
// {
// 	char	*line;
// 	int		height;
// 	int		width;
// 	char	**split_line;
// 	t_point	*grid;
//
// 	height = 0;
// 	grid = 0;
// 	get_next_line(fd, &line);
// 	split_line = ft_strsplit(line, ' ');
// 	grid_function(&grid, height, split_line);
// 	//grid_function - some func that applies our projections on display
// 	width = check_width(split_line);
// 	height = 1;
// 	while (get_next_line(fd, &line))
// 	{
// 		split_line = ft_strsplit(line ' ');
// 		if (width != check_width(split_line))
// 			invalid_map();
// 		else
// 			grid_function(&grid, height, split_line);
// 		height++;
// 	}
// 	//function(&grid, height, width);
// 	//function - some func that works with color and applies it on map
// 	return (0);
// }

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
// 	while (str[i])
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
