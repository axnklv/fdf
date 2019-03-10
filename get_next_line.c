/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:10:56 by hkuhic            #+#    #+#             */
/*   Updated: 2019/02/14 19:03:16 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static int		end_line(char *buff)
{
	int						lenght;

	lenght = 0;
	while (buff[lenght] && buff[lenght] != '\n')
		lenght++;
	if (buff[lenght] == '\n')
	{
		return (lenght);
	}
	return (-1);
}

static char		*ft_gnl_strjoin(char *s1, char *s2)
{
	char					*tmp;

	tmp = ft_strjoin(s1, s2);
	free(s1);
	return (tmp);
}

static char		*ft_gnl_strdup(char **str, int len)
{
	char *tmp;
	char *s;

	tmp = ft_strsub(*str, 0, len);
	s = ft_strdup(*str + len + (*(*str + len) ? 1 : 0));
	free(*str);
	*str = s;
	return (tmp);
}

int				get_next_line(int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static char		*tmp[15000];
	int				len;

	if (!line || fd < 0 || BUFF_SIZE < 0 || fd > 15000)
		return (-1);
	if (!tmp[fd] && !(tmp[fd] = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((len = end_line(tmp[fd])) == -1)
	{
		if ((len = read(fd, buff, BUFF_SIZE)) < 1)
		{
			if (len == -1)
				return (-1);
			if (*tmp[fd] && (len = ft_strlen(tmp[fd])) > 0)
				break ;
			free(tmp[fd]);
			tmp[fd] = NULL;
			return (0);
		}
		*(buff + len) = '\0';
		tmp[fd] = ft_gnl_strjoin(tmp[fd], buff);
	}
	*line = ft_gnl_strdup(&tmp[fd], len);
	return (1);
}
