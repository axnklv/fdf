/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:58:20 by elchrist          #+#    #+#             */
/*   Updated: 2019/03/14 21:43:23 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

void	it_is_error(void);
void	invalid_map(void);
void	usage(void);

typedef struct	s_point
{
	float				x;
	float				y;
	float				z;
	int				color; //надо hex  в dec
	float			x_pro;
	float			y_pro;
	char			*file;
	t_point			**point;
	int				height;
	int				width;
	//struct s_pixel	*next;
}				t_point;


typedef struct s_piz
{
    float x0,x1,x2,x3,x4,x5,x6,x7;
    float y0,y1,y2,y3,y4,y5,y6,y7;
    float z0,z1,z2,z3,z4,z5,z6,z7;
}                t_piz;

t_point	rotation_x(float x, float y, float z, float angle);
t_point rotation_y(float x, float y, float z, float angle);
t_point rotation_z(float x, float y, float z, float angle);
int		check_width(char **split_line);
void	validation(t_point *elem);
void	reading(t_point *elem);
void	map_error(int error);
int		letter_to_int(char hex);
void	tab(t_point *point, char *s);
void	tab_z(t_point *e, char *line, int i);

// typedef struct		s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }					t_list;

#endif
