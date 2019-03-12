/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:39:51 by elchrist          #+#    #+#             */
/*   Updated: 2019/03/12 19:30:31 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	validation(t_hueta *elem)
{
	char	*line;
	int		fd;
	int		count;
	int		first;

	count = 0;
	first = 0;
	elem->point_x = 0;
	elem->point_y = 0;
	fd = open(elem->file, O_RDONLY);
    if (fd < 0)
        it_is_error();
	while (get_next_line(fd, &line) == 1)
	{
		count = ft_word_count(line, ' ');
		//условие для невалидности
		if ( || count != количеству иксов))
            invalid_map();
		elem->point_x = count;
		//elem->point_y++;
		free(line);
	}
}
