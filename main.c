/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:33:31 by elchrist          #+#    #+#             */
/*   Updated: 2019/03/14 20:23:00 by hkuhic           ###   ########.fr       */
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
      mlx_pixel_put(mlx, win1, x, y, color);
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
      mlx_pixel_put(mlx, win1, x, y, color);
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

t_point rotation_z(float x, float y, float z, float angle)
{
  t_point a;
  a.x = x * cos(angle) - y * sin(angle);
  a.y = x * sin(angle) + y * cos(angle);
  a.z = z;
  return (a);
}
t_point rotation_x(float x, float y, float z, float angle)
{
  t_point a;
  a.x = x;
  a.y = y * cos(angle) + z * sin(angle) ;
  a.z = (-y * sin(angle) + z * cos(angle));
  return (a);
}

t_point rotation_y(float x, float y, float z, float angle)
{
  t_point a;
  a.x = x * cos(angle) + z * sin(angle);
  a.y = y;
  a.z = -x * sin(angle) + z * cos(angle);
  return (a);
}

t_point new_sistem(t_point a)
{
  a.x = (int)((a.x + 1) * (float)(1000 / 2));
  a.y = (int)((-a.y + 1) * (float)(1000 / 2));
  return (a);
}
t_point mashtab_up(float x, float y, float z)
{
  t_point a;
  a.x = x * 2;
  a.y = y * 2;
  a.z = z * 1;
  return (a);
}
t_point mashtab_down(float x, float y, float z)
{
  t_point a;
  a.x = x * 1/2;
  a.y = y * 1/2;
  a.z = z * 1;
  return (a);
}

t_point proektcia(float x1, float y1, float x2, float y2, float z)
{
  t_point a;
  a.x = (-z / (z - 8) * (x2 - x1) + x2);
  a.y = (-z / (z - 8) * (y2 - y1) + y2);
  return (a);
}

t_point move_up(float x, float y, float z)
{
  t_point a;
  a.x = x;
  a.y = y + 0.1;
  a.z = z;
  return (a);
}

t_point move_right(float x, float y, float z)
{
  t_point a;
  a.x = x + 0.1;
  a.y = y;
  a.z = z;
  return (a);
}

t_point move_down(float x, float y, float z)
{
  t_point a;
  a.x = x;
  a.y = y - 0.1;
  a.z = z;
  return (a);
}

t_point move_left(float x, float y, float z)
{
  t_point a;
  a.x = x - 0.1;
  a.y = y;
  a.z = z;
  return (a);
}
t_point move_z_up(float x, float y, float z)
{
  t_point a;
  a.x = x;
  a.y = y;
  a.z = z * 1.1;
  return (a);
}
t_point move_z_down(float x, float y, float z)
{
  t_point a;
  a.x = x;
  a.y = y;
  a.z = z * 0.9;
  return (a);
}


void redraw(t_piz *a)
{
  t_point b0, b1,b2,b3,b4,b5,b6,b7, c0, c1,c2,c3,c4,c5,c6,c7;

      b0 = proektcia(0, 0, a->x0, a->y0, a->z0);
      b1 = proektcia(0, 0, a->x1, a->y1, a->z1);
      b2 = proektcia(0, 0, a->x2, a->y2, a->z2);
      b3 = proektcia(0, 0, a->x3, a->y3, a->z3);
      b4 = proektcia(0, 0, a->x4, a->y4, a->z4);
      b5 = proektcia(0, 0, a->x5, a->y5, a->z5);
      b6 = proektcia(0, 0, a->x6, a->y6, a->z6);
      b7 = proektcia(0, 0, a->x7, a->y7, a->z7);
      c0 = new_sistem(b0);
      c1 = new_sistem(b1);
      c2 = new_sistem(b2);
      c3 = new_sistem(b3);
      c4 = new_sistem(b4);
      c5 = new_sistem(b5);
      c6 = new_sistem(b6);
      c7 = new_sistem(b7);
      draw_line(c0.x,c0.y,c5.x , c5.y, 0xff0000);
      draw_line(c0.x,c0.y,c7.x , c7.y, 0xff0000);
      draw_line(c0.x,c0.y,c6.x , c6.y, 0xff0000);
      draw_line(c1.x,c1.y,c2.x , c2.y, 0x8b7500);
      draw_line(c1.x,c1.y,c3.x , c3.y, 0x8b7500);
      draw_line(c1.x,c1.y,c4.x , c4.y, 0x8b7500);
      draw_line(c2.x,c2.y,c5.x , c5.y, 0x8b7500);
      draw_line(c2.x,c2.y,c6.x , c6.y, 0x8b7500);
      draw_line(c3.x,c3.y,c5.x , c5.y, 0x8b7500);
      draw_line(c3.x,c3.y,c7.x , c7.y, 0x8b7500);
      draw_line(c4.x,c4.y,c6.x , c6.y, 0x8b7500);
      draw_line(c4.x,c4.y,c7.x , c7.y, 0x8b7500);
}

int  iso(int but, t_piz *param)
{
    mlx_clear_window(mlx, win1);
    if(but == 19)
    {
      param->x0 = (param->x0 + param->y0) * cos(M_PI / 6);
      param->x0 = -(param->z0) + (param->x0 - param->y0) * sin(M_PI /6);
      param->x1 = (param->x1 + param->y1) * cos(M_PI / 6);
      param->x1 = -(param->z1) + (param->x1 - param->y1) * sin(M_PI /6);
      param->x2 = (param->x2 + param->y2) * cos(M_PI / 6);
      param->x2 = -(param->z2) + (param->x2 - param->y2) * sin(M_PI /6);
      param->x3 = (param->x3 + param->y3) * cos(M_PI / 6);
      param->x3 = -(param->z3) + (param->x3 - param->y3) * sin(M_PI /6);
      param->x4 = (param->x4 + param->y4) * cos(M_PI / 6);
      param->x4 = -(param->z4) + (param->x4 - param->y4) * sin(M_PI /6);
      param->x5 = (param->x5 + param->y5) * cos(M_PI / 6);
      param->x5 = -(param->z5) + (param->x5 - param->y5) * sin(M_PI /6);
      param->x6 = (param->x6 + param->y6) * cos(M_PI / 6);
      param->x6 = -(param->z6) + (param->x6 - param->y6) * sin(M_PI /6);
      param->x7 = (param->x7 + param->y7) * cos(M_PI / 6);
      param->y7 = -(param->z7) + (param->x7 - param->y7) * sin(M_PI /6);
    }
    redraw(param);
    return (0);
}


int clear_and_close(int but, t_piz *param)
{
  t_point move0, move1, move2, move3, move4, move5, move6, move7;
  t_point rotate0, rotate1,rotate2,rotate3,rotate4,rotate5,rotate6,rotate7;
  
  
  if (but == 18)
  {
    mlx_clear_window(mlx, win1);
    return (0);
  }
  else if (but == 53)
    exit(EXIT_SUCCESS);
  else if (but == 6)
  {
      mlx_clear_window(mlx, win1);
      move0 = move_z_up(param->x0, param->y0, param->z0);
      move1 = move_z_up(param->x1, param->y1, param->z1);
      move2 = move_z_up(param->x2, param->y2, param->z2);
      move3 = move_z_up(param->x3, param->y3, param->z3);
      move4 = move_z_up(param->x4, param->y4, param->z4);
      move5 = move_z_up(param->x5, param->y5, param->z5);
      move6 = move_z_up(param->x6, param->y6, param->z6);
      move7 = move_z_up(param->x7, param->y7, param->z7);

      param->x0 = move0.x; param->y0 = move0.y; param->z0 = move0.z;
      param->x1 = move1.x; param->y1 = move1.y; param->z1 = move1.z;
      param->x2 = move2.x; param->y2 = move2.y; param->z2 = move2.z;
      param->x3 = move3.x; param->y3 = move3.y; param->z3 = move3.z;
      param->x4 = move4.x; param->y4 = move4.y; param->z4 = move4.z;
      param->x5 = move5.x; param->y5 = move5.y; param->z5 = move5.z;
      param->x6 = move6.x; param->y6 = move6.y; param->z6 = move6.z;
      param->x7 = move7.x; param->y7 = move7.y; param->z7 = move7.z;

  }
  else if (but == 7)
  {
      mlx_clear_window(mlx, win1);
      move0 = move_z_down(param->x0, param->y0, param->z0);
      move1 = move_z_down(param->x1, param->y1, param->z1);
      move2 = move_z_down(param->x2, param->y2, param->z2);
      move3 = move_z_down(param->x3, param->y3, param->z3);
      move4 = move_z_down(param->x4, param->y4, param->z4);
      move5 = move_z_down(param->x5, param->y5, param->z5);
      move6 = move_z_down(param->x6, param->y6, param->z6);
      move7 = move_z_down(param->x7, param->y7, param->z7);

      param->x0 = move0.x; param->y0 = move0.y; param->z0 = move0.z;
      param->x1 = move1.x; param->y1 = move1.y; param->z1 = move1.z;
      param->x2 = move2.x; param->y2 = move2.y; param->z2 = move2.z;
      param->x3 = move3.x; param->y3 = move3.y; param->z3 = move3.z;
      param->x4 = move4.x; param->y4 = move4.y; param->z4 = move4.z;
      param->x5 = move5.x; param->y5 = move5.y; param->z5 = move5.z;
      param->x6 = move6.x; param->y6 = move6.y; param->z6 = move6.z;
      param->x7 = move7.x; param->y7 = move7.y; param->z7 = move7.z;

  }
  else if (but == 13)
  {
      mlx_clear_window(mlx, win1);
      move0 = move_up(param->x0, param->y0, param->z0);
      move1 = move_up(param->x1, param->y1, param->z1);
      move2 = move_up(param->x2, param->y2, param->z2);
      move3 = move_up(param->x3, param->y3, param->z3);
      move4 = move_up(param->x4, param->y4, param->z4);
      move5 = move_up(param->x5, param->y5, param->z5);
      move6 = move_up(param->x6, param->y6, param->z6);
      move7 = move_up(param->x7, param->y7, param->z7);

      param->x0 = move0.x; param->y0 = move0.y; param->z0 = move0.z;
      param->x1 = move1.x; param->y1 = move1.y; param->z1 = move1.z;
      param->x2 = move2.x; param->y2 = move2.y; param->z2 = move2.z;
      param->x3 = move3.x; param->y3 = move3.y; param->z3 = move3.z;
      param->x4 = move4.x; param->y4 = move4.y; param->z4 = move4.z;
      param->x5 = move5.x; param->y5 = move5.y; param->z5 = move5.z;
      param->x6 = move6.x; param->y6 = move6.y; param->z6 = move6.z;
      param->x7 = move7.x; param->y7 = move7.y; param->z7 = move7.z;

  }
  else if (but == 2)
  {
      mlx_clear_window(mlx, win1);
      move0 = move_right(param->x0, param->y0, param->z0);
      move1 = move_right(param->x1, param->y1, param->z1);
      move2 = move_right(param->x2, param->y2, param->z2);
      move3 = move_right(param->x3, param->y3, param->z3);
      move4 = move_right(param->x4, param->y4, param->z4);
      move5 = move_right(param->x5, param->y5, param->z5);
      move6 = move_right(param->x6, param->y6, param->z6);
      move7 = move_right(param->x7, param->y7, param->z7);

      param->x0 = move0.x; param->y0 = move0.y; param->z0 = move0.z;
      param->x1 = move1.x; param->y1 = move1.y; param->z1 = move1.z;
      param->x2 = move2.x; param->y2 = move2.y; param->z2 = move2.z;
      param->x3 = move3.x; param->y3 = move3.y; param->z3 = move3.z;
      param->x4 = move4.x; param->y4 = move4.y; param->z4 = move4.z;
      param->x5 = move5.x; param->y5 = move5.y; param->z5 = move5.z;
      param->x6 = move6.x; param->y6 = move6.y; param->z6 = move6.z;
      param->x7 = move7.x; param->y7 = move7.y; param->z7 = move7.z;

  }
  else if (but == 1)
  {
      mlx_clear_window(mlx, win1);
      move0 = move_down(param->x0, param->y0, param->z0);
      move1 = move_down(param->x1, param->y1, param->z1);
      move2 = move_down(param->x2, param->y2, param->z2);
      move3 = move_down(param->x3, param->y3, param->z3);
      move4 = move_down(param->x4, param->y4, param->z4);
      move5 = move_down(param->x5, param->y5, param->z5);
      move6 = move_down(param->x6, param->y6, param->z6);
      move7 = move_down(param->x7, param->y7, param->z7);

      param->x0 = move0.x; param->y0 = move0.y; param->z0 = move0.z;
      param->x1 = move1.x; param->y1 = move1.y; param->z1 = move1.z;
      param->x2 = move2.x; param->y2 = move2.y; param->z2 = move2.z;
      param->x3 = move3.x; param->y3 = move3.y; param->z3 = move3.z;
      param->x4 = move4.x; param->y4 = move4.y; param->z4 = move4.z;
      param->x5 = move5.x; param->y5 = move5.y; param->z5 = move5.z;
      param->x6 = move6.x; param->y6 = move6.y; param->z6 = move6.z;
      param->x7 = move7.x; param->y7 = move7.y; param->z7 = move7.z;

  }
  else if (but == 0)
  {
      mlx_clear_window(mlx, win1);
      move0 = move_left(param->x0, param->y0, param->z0);
      move1 = move_left(param->x1, param->y1, param->z1);
      move2 = move_left(param->x2, param->y2, param->z2);
      move3 = move_left(param->x3, param->y3, param->z3);
      move4 = move_left(param->x4, param->y4, param->z4);
      move5 = move_left(param->x5, param->y5, param->z5);
      move6 = move_left(param->x6, param->y6, param->z6);
      move7 = move_left(param->x7, param->y7, param->z7);

      param->x0 = move0.x; param->y0 = move0.y; param->z0 = move0.z;
      param->x1 = move1.x; param->y1 = move1.y; param->z1 = move1.z;
      param->x2 = move2.x; param->y2 = move2.y; param->z2 = move2.z;
      param->x3 = move3.x; param->y3 = move3.y; param->z3 = move3.z;
      param->x4 = move4.x; param->y4 = move4.y; param->z4 = move4.z;
      param->x5 = move5.x; param->y5 = move5.y; param->z5 = move5.z;
      param->x6 = move6.x; param->y6 = move6.y; param->z6 = move6.z;
      param->x7 = move7.x; param->y7 = move7.y; param->z7 = move7.z;

  }
  else if (but == 126)
  {
      mlx_clear_window(mlx, win1);
      angle += M_PI / 18;
      rotate0 = rotation_x(param->x0, param->y0, param->z0, angle);
      rotate1 = rotation_x(param->x1, param->y1, param->z1, angle);
      rotate2 = rotation_x(param->x2, param->y2, param->z2, angle);
      rotate3 = rotation_x(param->x3, param->y3, param->z3, angle);
      rotate4 = rotation_x(param->x4, param->y4, param->z4, angle);
      rotate5 = rotation_x(param->x5, param->y5, param->z5, angle);
      rotate6 = rotation_x(param->x6, param->y6, param->z6, angle);
      rotate7 = rotation_x(param->x7, param->y7, param->z7, angle);

      param->x0 = rotate0.x; param->y0 = rotate0.y; param->z0 = rotate0.z;
      param->x1 = rotate1.x; param->y1 = rotate1.y; param->z1 = rotate1.z;
      param->x2 = rotate2.x; param->y2 = rotate2.y; param->z2 = rotate2.z;
      param->x3 = rotate3.x; param->y3 = rotate3.y; param->z3 = rotate3.z;
      param->x4 = rotate4.x; param->y4 = rotate4.y; param->z4 = rotate4.z;
      param->x5 = rotate5.x; param->y5 = rotate5.y; param->z5 = rotate5.z;
      param->x6 = rotate6.x; param->y6 = rotate6.y; param->z6 = rotate6.z;
      param->x7 = rotate7.x; param->y7 = rotate7.y; param->z7 = rotate7.z;

  }
  else if (but == 124)
  {
      mlx_clear_window(mlx, win1);
      angle += M_PI / 18;
      rotate0 = rotation_y(param->x0, param->y0, param->z0, angle);
      rotate1 = rotation_y(param->x1, param->y1, param->z1, angle);
      rotate2 = rotation_y(param->x2, param->y2, param->z2, angle);
      rotate3 = rotation_y(param->x3, param->y3, param->z3, angle);
      rotate4 = rotation_y(param->x4, param->y4, param->z4, angle);
      rotate5 = rotation_y(param->x5, param->y5, param->z5, angle);
      rotate6 = rotation_y(param->x6, param->y6, param->z6, angle);
      rotate7 = rotation_y(param->x7, param->y7, param->z7, angle);

      param->x0 = rotate0.x; param->y0 = rotate0.y; param->z0 = rotate0.z;
      param->x1 = rotate1.x; param->y1 = rotate1.y; param->z1 = rotate1.z;
      param->x2 = rotate2.x; param->y2 = rotate2.y; param->z2 = rotate2.z;
      param->x3 = rotate3.x; param->y3 = rotate3.y; param->z3 = rotate3.z;
      param->x4 = rotate4.x; param->y4 = rotate4.y; param->z4 = rotate4.z;
      param->x5 = rotate5.x; param->y5 = rotate5.y; param->z5 = rotate5.z;
      param->x6 = rotate6.x; param->y6 = rotate6.y; param->z6 = rotate6.z;
      param->x7 = rotate7.x; param->y7 = rotate7.y; param->z7 = rotate7.z;

  }
  else if (but == 125)
  {
      mlx_clear_window(mlx, win1);
      angle -= M_PI / 18;
      rotate0 = rotation_x(param->x0, param->y0, param->z0, angle);
      rotate1 = rotation_x(param->x1, param->y1, param->z1, angle);
      rotate2 = rotation_x(param->x2, param->y2, param->z2, angle);
      rotate3 = rotation_x(param->x3, param->y3, param->z3, angle);
      rotate4 = rotation_x(param->x4, param->y4, param->z4, angle);
      rotate5 = rotation_x(param->x5, param->y5, param->z5, angle);
      rotate6 = rotation_x(param->x6, param->y6, param->z6, angle);
      rotate7 = rotation_x(param->x7, param->y7, param->z7, angle);

      param->x0 = rotate0.x; param->y0 = rotate0.y; param->z0 = rotate0.z;
      param->x1 = rotate1.x; param->y1 = rotate1.y; param->z1 = rotate1.z;
      param->x2 = rotate2.x; param->y2 = rotate2.y; param->z2 = rotate2.z;
      param->x3 = rotate3.x; param->y3 = rotate3.y; param->z3 = rotate3.z;
      param->x4 = rotate4.x; param->y4 = rotate4.y; param->z4 = rotate4.z;
      param->x5 = rotate5.x; param->y5 = rotate5.y; param->z5 = rotate5.z;
      param->x6 = rotate6.x; param->y6 = rotate6.y; param->z6 = rotate6.z;
      param->x7 = rotate7.x; param->y7 = rotate7.y; param->z7 = rotate7.z;

  }
  else if (but == 123)
  {
      mlx_clear_window(mlx, win1);
      angle -= M_PI / 18;
      rotate0 = rotation_y(param->x0, param->y0, param->z0, angle);
      rotate1 = rotation_y(param->x1, param->y1, param->z1, angle);
      rotate2 = rotation_y(param->x2, param->y2, param->z2, angle);
      rotate3 = rotation_y(param->x3, param->y3, param->z3, angle);
      rotate4 = rotation_y(param->x4, param->y4, param->z4, angle);
      rotate5 = rotation_y(param->x5, param->y5, param->z5, angle);
      rotate6 = rotation_y(param->x6, param->y6, param->z6, angle);
      rotate7 = rotation_y(param->x7, param->y7, param->z7, angle);
      
      param->x0 = rotate0.x; param->y0 = rotate0.y; param->z0 = rotate0.z;
      param->x1 = rotate1.x; param->y1 = rotate1.y; param->z1 = rotate1.z;
      param->x2 = rotate2.x; param->y2 = rotate2.y; param->z2 = rotate2.z;
      param->x3 = rotate3.x; param->y3 = rotate3.y; param->z3 = rotate3.z;
      param->x4 = rotate4.x; param->y4 = rotate4.y; param->z4 = rotate4.z;
      param->x5 = rotate5.x; param->y5 = rotate5.y; param->z5 = rotate5.z;
      param->x6 = rotate6.x; param->y6 = rotate6.y; param->z6 = rotate6.z;
      param->x7 = rotate7.x; param->y7 = rotate7.y; param->z7 = rotate7.z;

  }
  redraw(param);
  return (0);
}

int   mouse(int but, int x, int y, t_piz *param)
{
    t_point scale0, scale1,scale2,scale3,scale4,scale5,scale6,scale7;
    t_point b0, b1,b2,b3,b4,b5,b6,b7, c0, c1,c2,c3,c4,c5,c6,c7;
    if (but == 1)
        mlx_string_put(mlx, win1, x, y, 0xfffafa, "SASHA HUI");
    else if (but == 5)
    {
      mlx_clear_window(mlx, win1);
            
      scale0 = mashtab_down(param->x0, param->y0, param->z0);
      scale1 = mashtab_down(param->x1, param->y1, param->z1);
      scale2 = mashtab_down(param->x2, param->y2, param->z2);
      scale3 = mashtab_down(param->x3, param->y3, param->z3);
      scale4 = mashtab_down(param->x4, param->y4, param->z4);
      scale5 = mashtab_down(param->x5, param->y5, param->z5);
      scale6 = mashtab_down(param->x6, param->y6, param->z6);
      scale7 = mashtab_down(param->x7, param->y7, param->z7);

      param->x0 = scale0.x; param->y0 = scale0.y; param->z0 = scale0.z;
      param->x1 = scale1.x; param->y1 = scale1.y; param->z1 = scale1.z;
      param->x2 = scale2.x; param->y2 = scale2.y; param->z2 = scale2.z;
      param->x3 = scale3.x; param->y3 = scale3.y; param->z3 = scale3.z;
      param->x4 = scale4.x; param->y4 = scale4.y; param->z4 = scale4.z;
      param->x5 = scale5.x; param->y5 = scale5.y; param->z5 = scale5.z;
      param->x6 = scale6.x; param->y6 = scale6.y; param->z6 = scale6.z;
      param->x7 = scale7.x; param->y7 = scale7.y; param->z7 = scale7.z;

    }
    else if (but == 4)
    {
      mlx_clear_window(mlx, win1);
            
      scale0 = mashtab_up(param->x0, param->y0, param->z0);
      scale1 = mashtab_up(param->x1, param->y1, param->z1);
      scale2 = mashtab_up(param->x2, param->y2, param->z2);
      scale3 = mashtab_up(param->x3, param->y3, param->z3);
      scale4 = mashtab_up(param->x4, param->y4, param->z4);
      scale5 = mashtab_up(param->x5, param->y5, param->z5);
      scale6 = mashtab_up(param->x6, param->y6, param->z6);
      scale7 = mashtab_up(param->x7, param->y7, param->z7);

      param->x0 = scale0.x; param->y0 = scale0.y; param->z0 = scale0.z;
      param->x1 = scale1.x; param->y1 = scale1.y; param->z1 = scale1.z;
      param->x2 = scale2.x; param->y2 = scale2.y; param->z2 = scale2.z;
      param->x3 = scale3.x; param->y3 = scale3.y; param->z3 = scale3.z;
      param->x4 = scale4.x; param->y4 = scale4.y; param->z4 = scale4.z;
      param->x5 = scale5.x; param->y5 = scale5.y; param->z5 = scale5.z;
      param->x6 = scale6.x; param->y6 = scale6.y; param->z6 = scale6.z;
      param->x7 = scale7.x; param->y7 = scale7.y; param->z7 = scale7.z;

    }
    redraw(param);
    return (0);
}

int main()
{
    t_piz p;
    t_piz a;
    

    mlx = mlx_init();
    win1 = mlx_new_window(mlx, 1000, 1000, "u sashi malenkiy");
    a.x0 = -0.5; a.y0 = -0.5; a.z0 = -0.5;
    a.x1 = 0.5; a.y1 = 0.5; a.z1 = 0.5;
    a.x2 = -0.5; a.y2 = 0.5; a.z2 = 0.5;
    a.x3 = 0.5; a.y3 = -0.5; a.z3 = 0.5;
    a.x4 = 0.5; a.y4 = 0.5; a.z4 = -0.5;
    a.x5 = -0.5; a.y5 = -0.5; a.z5 = 0.5;
    a.x6 = -0.5; a.y6 = 0.5; a.z6 = -0.5;
    a.x7 = 0.5; a.y7 = -0.5; a.z7 = -0.5;
       
    p.x0 = a.x0;p.y0 = a.y0;p.z0 = a.z0;
    p.x1 = a.x1;p.y1 = a.y1;p.z1 = a.z1;
    p.x2 = a.x2;p.y2 = a.y2;p.z2 = a.z2;
    p.x3 = a.x3;p.y3 = a.y3;p.z3 = a.z3;
    p.x4 = a.x4;p.y4 = a.y4;p.z4 = a.z4;
    p.x5 = a.x5;p.y5 = a.y5;p.z5 = a.z5;
    p.x6 = a.x6;p.y6 = a.y6;p.z6 = a.z6;
    p.x7 = a.x7;p.y7 = a.y7;p.z7 = a.z7;
    redraw(&a);   
    mlx_hook(win1,2 , 0, clear_and_close, &p);
   
    mlx_mouse_hook(win1, mouse, &p);
   
    mlx_loop(mlx);
    return (0);
}
