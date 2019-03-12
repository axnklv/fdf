/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:33:31 by elchrist          #+#    #+#             */
/*   Updated: 2019/03/12 23:07:33 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void *mlx;
void *win1;
float angle = 0;

float   draw_line(float x1, float  y1, float x2, float  y2, int color)
{
  float lenghtx = (x2 - x1);
  float lenghty = (y2 - y1);
  float len;
  float dx = (lenghtx > 0 ? 1 : -1);
  float dy = (lenghty > 0 ? 1 : -1);
  lenghtx = fabs(lenghtx);
  lenghty = fabs(lenghty);
  len = fmax(lenghtx, lenghty);
  if (len == 0)
    mlx_pixel_put(mlx, win1, x1, y1, 0x8deeee);
  if (lenghty <= lenghtx)
  {
    int x = x1;
    int y = y1;
    float d = -lenghtx;
    while (len--)
    {
      mlx_pixel_put(mlx, win1, x, y, 0x8deeee);
      x += dx;
      d += 2 * lenghty;
      if (d > 0)
      {
        d -= 2 * lenghtx;
        y += dy;
      }
    }
  }
  else
  {
    int y = y1;
    int x = x1;
    float d = -lenghty;
    while (len--)
    {
      mlx_pixel_put(mlx, win1, x, y, 0x8deeee);
      y += dy;
      d += 2 * lenghtx;
      if (d > 0)
      {
        d -= 2 * lenghty;
        x +=dx;
      }
    }
  }

  return (0);
}

t_coord rotation_z(float x, float y, float z, float angle)
{
  t_coord a;
  a.x = x * cos(angle) - y * sin(angle);
  a.y = x * sin(angle) + y * cos(angle);
  a.z = z;
  return (a);
}
t_coord rotation_x(float x, float y, float z, float angle)
{
  t_coord a;
  a.x = x;
  a.y = y * cos(angle) + z * sin(angle) ;
  a.z = (-y * sin(angle) + z * cos(angle));
  return (a);
}

t_coord rotation_y(float x, float y, float z, float angle)
{
  t_coord a;
  a.x = x * cos(angle) + z * sin(angle);
  a.y = y;
  a.z = -x * sin(angle) + z * cos(angle);
  return (a);
}

t_matrix new_sistem(float axisx, float axisy)
{
  t_matrix a;
  a.x = (int)((axisx + 1) * (float)(1000 / 2));
  a.y = (int)((-axisy + 1) * (float)(1000 / 2));
  return (a);
}
t_matrix mashtab(float x, float y)
{
  t_matrix a;
  a.x = x * 100;
  a.y = y * 100;
  return (a);
}

t_matrix proektcia(float x1, float y1, float x2, float y2, float z)
{
  t_matrix a;
  a.x = (-z / (z - 8) * (x2 - x1) + x2);
  a.y = (-z / (z - 8) * (y2 - y1) + y2);
  return (a);
}

int clear_and_close(int but, t_piz *param)
{
  t_matrix b0, b1,b2,b3,b4,b5,b6,b7, c0, c1,c2,c3,c4,c5,c6,c7;
  t_coord rotate0, rotate1,rotate2,rotate3,rotate4,rotate5,rotate6,rotate7;
  t_coord rotate10, rotate11,rotate12,rotate13,rotate14,rotate15,rotate16,rotate17;
  if (but == 53)
    exit(EXIT_SUCCESS);
  if (but == 18)
    mlx_clear_window(mlx, win1);
  if (but == 126)
  {
      mlx_clear_window(mlx, win1);
      angle += 0.1;
      rotate0 = rotation_x(param->x0, param->y0, param->z0, angle);
      rotate1 = rotation_x(param->x1, param->y1, param->z1, angle);
      rotate2 = rotation_x(param->x2, param->y2, param->z2, angle);
      rotate3 = rotation_x(param->x3, param->y3, param->z3, angle);
      rotate4 = rotation_x(param->x4, param->y4, param->z4, angle);
      rotate5 = rotation_x(param->x5, param->y5, param->z5, angle);
      rotate6 = rotation_x(param->x6, param->y6, param->z6, angle);
      rotate7 = rotation_x(param->x7, param->y7, param->z7, angle);
      b0 = proektcia(0, 0, rotate0.x, rotate0.y, rotate0.z);
      b1 = proektcia(0, 0, rotate1.x, rotate1.y, rotate1.z);
      b2 = proektcia(0, 0, rotate2.x, rotate2.y, rotate2.z);
      b3 = proektcia(0, 0, rotate3.x, rotate3.y, rotate3.z);
      b4 = proektcia(0, 0, rotate4.x, rotate4.y, rotate4.z);
      b5 = proektcia(0, 0, rotate5.x, rotate5.y, rotate5.z);
      b6 = proektcia(0, 0, rotate6.x, rotate6.y, rotate6.z);
      b7 = proektcia(0, 0, rotate7.x, rotate7.y, rotate7.z);
      c0 = new_sistem(b0.x, b0.y);
      c1 = new_sistem(b1.x, b1.y);
      c2 = new_sistem(b2.x, b2.y);
      c3 = new_sistem(b3.x, b3.y);
      c4 = new_sistem(b4.x, b4.y);
      c5 = new_sistem(b5.x, b5.y);
      c6 = new_sistem(b6.x, b6.y);
      c7 = new_sistem(b7.x, b7.y);
      draw_line(c0.x,c0.y,c5.x , c5.y, 0xff0000);
      draw_line(c0.x,c0.y,c7.x , c7.y, 0xff0000);
      draw_line(c0.x,c0.y,c6.x , c6.y, 0xff0000);
      draw_line(c1.x,c1.y,c2.x , c2.y, 0xff0000);
      draw_line(c1.x,c1.y,c3.x , c3.y, 0xff0000);
      draw_line(c1.x,c1.y,c4.x , c4.y, 0xff0000);
      draw_line(c2.x,c2.y,c5.x , c5.y, 0xff0000);
      draw_line(c2.x,c2.y,c6.x , c6.y, 0xff0000);
      draw_line(c3.x,c3.y,c5.x , c5.y, 0xff0000);
      draw_line(c3.x,c3.y,c7.x , c7.y, 0xff0000);
      draw_line(c4.x,c4.y,c6.x , c6.y, 0xff0000);
      draw_line(c4.x,c4.y,c7.x , c7.y, 0xff0000);
  }
  if (but == 124)
  {
      mlx_clear_window(mlx, win1);
      angle += 0.1;
      rotate10 = rotation_y(param->x0, param->y0, param->z0, angle);
      rotate11 = rotation_y(param->x1, param->y1, param->z1, angle);
      rotate12 = rotation_y(param->x2, param->y2, param->z2, angle);
      rotate13 = rotation_y(param->x3, param->y3, param->z3, angle);
      rotate14 = rotation_y(param->x4, param->y4, param->z4, angle);
      rotate15 = rotation_y(param->x5, param->y5, param->z5, angle);
      rotate16 = rotation_y(param->x6, param->y6, param->z6, angle);
      rotate17 = rotation_y(param->x7, param->y7, param->z7, angle);
      b0 = proektcia(0, 0, rotate10.x, rotate10.y, rotate10.z);
      b1 = proektcia(0, 0, rotate11.x, rotate11.y, rotate11.z);
      b2 = proektcia(0, 0, rotate12.x, rotate12.y, rotate12.z);
      b3 = proektcia(0, 0, rotate13.x, rotate13.y, rotate13.z);
      b4 = proektcia(0, 0, rotate14.x, rotate14.y, rotate14.z);
      b5 = proektcia(0, 0, rotate15.x, rotate15.y, rotate15.z);
      b6 = proektcia(0, 0, rotate16.x, rotate16.y, rotate16.z);
      b7 = proektcia(0, 0, rotate17.x, rotate17.y, rotate17.z);
      c0 = new_sistem(b0.x, b0.y);
      c1 = new_sistem(b1.x, b1.y);
      c2 = new_sistem(b2.x, b2.y);
      c3 = new_sistem(b3.x, b3.y);
      c4 = new_sistem(b4.x, b4.y);
      c5 = new_sistem(b5.x, b5.y);
      c6 = new_sistem(b6.x, b6.y);
      c7 = new_sistem(b7.x, b7.y);
      draw_line(c0.x,c0.y,c5.x , c5.y, 0xff0000);
      draw_line(c0.x,c0.y,c7.x , c7.y, 0xff0000);
      draw_line(c0.x,c0.y,c6.x , c6.y, 0xff0000);
      draw_line(c1.x,c1.y,c2.x , c2.y, 0xff0000);
      draw_line(c1.x,c1.y,c3.x , c3.y, 0xff0000);
      draw_line(c1.x,c1.y,c4.x , c4.y, 0xff0000);
      draw_line(c2.x,c2.y,c5.x , c5.y, 0xff0000);
      draw_line(c2.x,c2.y,c6.x , c6.y, 0xff0000);
      draw_line(c3.x,c3.y,c5.x , c5.y, 0xff0000);
      draw_line(c3.x,c3.y,c7.x , c7.y, 0xff0000);
      draw_line(c4.x,c4.y,c6.x , c6.y, 0xff0000);
      draw_line(c4.x,c4.y,c7.x , c7.y, 0xff0000);
  }
  return (0);
}

int   mouse(int button, int x, int y, int x1, int y1)
{
    if (button == 1)
        mlx_string_put(mlx, win1, x, y, 0xfffafa, "PIZDA");
    return (0);
}

int main()
{
    t_piz p;
    t_coord a0;
    t_coord a1;
    t_coord a2;
    t_coord a3;
    t_coord a4;
    t_coord a5;
    t_coord a6;
    t_coord a7;
    t_matrix b0;
    t_matrix b1;
    t_matrix b2;
    t_matrix b3;
    t_matrix b4;
    t_matrix b5;
    t_matrix b6;
    t_matrix b7;

    mlx = mlx_init();
    win1 = mlx_new_window(mlx, 1000, 1000, "win1");
    a0.x = -0.5; a0.y = -0.5; a0.z = -0.5;
    a1.x = 0.5; a1.y = 0.5; a1.z = 0.5;
    a2.x = -0.5; a2.y = 0.5; a2.z = 0.5;
    a3.x = 0.5; a3.y = -0.5; a3.z = 0.5;
    a4.x = 0.5; a4.y = 0.5; a4.z = -0.5;
    a5.x = -0.5; a5.y = -0.5; a5.z = 0.5;
    a6.x = -0.5; a6.y = 0.5; a6.z = -0.5;
    a7.x = 0.5; a7.y = -0.5; a7.z = -0.5;

    b0 = proektcia(0, 0, a0.x, a0.y, a0.z);
    b1 = proektcia(0, 0, a1.x, a1.y, a1.z);
    b2 = proektcia(0, 0, a2.x, a2.y, a2.z);
    b3 = proektcia(0, 0, a3.x, a3.y, a3.z);
    b4 = proektcia(0, 0, a4.x, a4.y, a4.z);
    b5 = proektcia(0, 0, a5.x, a5.y, a5.z);
    b6 = proektcia(0, 0, a6.x, a6.y, a6.z);
    b7 = proektcia(0, 0, a7.x, a7.y, a7.z);

    int x = 0, y = 0, lenx = 1000, leny = 1000;
    t_matrix c0, c1,c2,c3,c4,c5,c6,c7;
    c0 = new_sistem(b0.x, b0.y);
    c1 = new_sistem(b1.x, b1.y);
    c2 = new_sistem(b2.x, b2.y);
    c3 = new_sistem(b3.x, b3.y);
    c4 = new_sistem(b4.x, b4.y);
    c5 = new_sistem(b5.x, b5.y);
    c6 = new_sistem(b6.x, b6.y);
    c7 = new_sistem(b7.x, b7.y);

    p.x0 = a0.x;p.y0 = a0.y;p.z0 = a0.z;
    p.x1 = a1.x;p.y1 = a1.y;p.z1 = a1.z;
    p.x2 = a2.x;p.y2 = a2.y;p.z2 = a2.z;
    p.x3 = a3.x;p.y3 = a3.y;p.z3 = a3.z;
    p.x4 = a4.x;p.y4 = a4.y;p.z4 = a4.z;
    p.x5 = a5.x;p.y5 = a5.y;p.z5 = a5.z;
    p.x6 = a6.x;p.y6 = a6.y;p.z6 = a6.z;
    p.x7 = a7.x;p.y7 = a7.y;p.z7 = a7.z;

    draw_line(c0.x,c0.y,c5.x , c5.y, 0xff0000);
    draw_line(c0.x,c0.y,c7.x , c7.y, 0xff0000);
    draw_line(c0.x,c0.y,c6.x , c6.y, 0xff0000);
    draw_line(c1.x,c1.y,c2.x , c2.y, 0xff0000);
    draw_line(c1.x,c1.y,c3.x , c3.y, 0xff0000);
    draw_line(c1.x,c1.y,c4.x , c4.y, 0xff0000);
    draw_line(c2.x,c2.y,c5.x , c5.y, 0xff0000);
    draw_line(c2.x,c2.y,c6.x , c6.y, 0xff0000);
    draw_line(c3.x,c3.y,c5.x , c5.y, 0xff0000);
    draw_line(c3.x,c3.y,c7.x , c7.y, 0xff0000);
    draw_line(c4.x,c4.y,c6.x , c6.y, 0xff0000);
    draw_line(c4.x,c4.y,c7.x , c7.y, 0xff0000);

    mlx_hook(win1,2 , 0,clear_and_close, &p);
    mlx_mouse_hook(win1, mouse, 0);
    mlx_loop(mlx);
    return (0);
}
