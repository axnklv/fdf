/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:58:20 by elchrist          #+#    #+#             */
/*   Updated: 2019/03/12 23:12:51 by elchrist         ###   ########.fr       */
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
