/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:33:31 by elchrist          #+#    #+#             */
/*   Updated: 2019/03/13 21:23:04 by hkuhic           ###   ########.fr       */
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

t_point new_sistem(float axisx, float axisy)
{
  t_point a;
  a.x = (int)((axisx + 1) * (float)(1000 / 2));
  a.y = (int)((-axisy + 1) * (float)(1000 / 2));
  return (a);
}
t_point mashtab(float x, float y)
{
  t_point a;
  a.x = x * 100;
  a.y = y * 100;
  return (a);
}

t_point proektcia(float x1, float y1, float x2, float y2, float z)
{
  t_point a;
  a.x = (-z / (z - 8) * (x2 - x1) + x2);
  a.y = (-z / (z - 8) * (y2 - y1) + y2);
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
    if(but == 18)
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
  t_point b0, b1,b2,b3,b4,b5,b6,b7, c0, c1,c2,c3,c4,c5,c6,c7;
  t_point rotate0, rotate1,rotate2,rotate3,rotate4,rotate5,rotate6,rotate7;
  t_point rotate10, rotate11,rotate12,rotate13,rotate14,rotate15,rotate16,rotate17;
  t_point rotate20, rotate21,rotate22,rotate23,rotate24,rotate25,rotate26,rotate27;
  t_point rotate30, rotate31,rotate32,rotate33,rotate34,rotate35,rotate36,rotate37;
  t_point rotate40, rotate41,rotate42,rotate43,rotate44,rotate45,rotate46,rotate47;
  t_point rotate50, rotate51,rotate52,rotate53,rotate54,rotate55,rotate56,rotate57;
  if (but == 53)
    exit(EXIT_SUCCESS);
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

int   mouse(int button, int x, int y, int x1, int y1)
{
    if (button == 1)
        mlx_string_put(mlx, win1, x, y, 0xfffafa, "P I Z D A");
    return (0);
}

int main()
{
    t_piz p;
    t_piz a;
    

    mlx = mlx_init();
    win1 = mlx_new_window(mlx, 1000, 1000, "win1");
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
    mlx_hook(win1,2 , 0,clear_and_close, &p);
    mlx_mouse_hook(win1, mouse, 0);
    mlx_key_hook(win1, iso, &p);
    mlx_loop(mlx);
    return (0);
}
