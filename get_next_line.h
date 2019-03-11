/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 19:52:08 by hkuhic            #+#    #+#             */
/*   Updated: 2019/03/11 21:03:36 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 2056
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct	t_matrix
{
	float x;
	float y;
}				s;
typedef struct	t_screen
{
	float x;
	float y;
}				screen;

typedef	struct t_coor
{
	float x;
	float y;
	float z;
}				k;

k rotation_y(float x, float y, float z);
k rotation_z(float x, float y, float z);


int		get_next_line(const int fd, char **line);

#endif
