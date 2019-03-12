/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:58:20 by elchrist          #+#    #+#             */
/*   Updated: 2019/03/12 23:14:44 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <math.h>
# include <mlx.h>

void	it_is_error(void);
void	invalid_map(void);
void	usage(void);

typedef struct	s_matrix
{
	float x;
	float y;
}				t_matrix;

typedef struct	s_screen
{
	float x;
	float y;
}				t_screen;

typedef	struct s_coord
{
	float x;
	float y;
	float z;
}				t_coord;

typedef struct s_piz
{
    float x0,x1,x2,x3,x4,x5,x6,x7;
    float y0,y1,y2,y3,y4,y5,y6,y7;
    float z0,z1,z2,z3,z4,z5,z6,z7;
}                t_piz;
// typedef struct	s_hueta
// {
//     int point_x;
//     int point_y;
// 	t_point	**point;
// 	void	*window;
// 	char	*file;
// }				t_hueta;

k rotation_y(float x, float y, float z);
k rotation_z(float x, float y, float z);

#endif
