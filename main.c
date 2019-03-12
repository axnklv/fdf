/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:33:31 by elchrist          #+#    #+#             */
/*   Updated: 2019/03/12 19:33:36 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <math.h>

void *mlx;
void *win1;

float   draw_line(float x1, float  y1, float x2, float  y2, int color)
{
  float lenghtx = (x2 - x1);
  float lenghty = (y2 - y1);
  float dx = (lenghtx > 0 ? 1 : -1);
  float dy = (lenghty > 0 ? 1 : -1);
  float x = x1;
  float y = y1;
  float k = lenghty / lenghtx;
  float b = (y1 * x2 - y2 * x1) / lenghtx;
  lenghtx = fabs(lenghtx);
  lenghty = fabs(lenghty);
  if (lenghtx == 0)
  {
      if (lenghty == 0)
        mlx_pixel_put(mlx, win1, x, y, color);
      while (lenghty--)
      {
        mlx_pixel_put(mlx, win1, x, y, color);
        y = y + dy;
      }
  }
  else
  {

      while(lenghtx--)
      {
        mlx_pixel_put(mlx, win1, x, y, color);
        x = x + dx;
        y = x * k + b;
      }
  }
  return (0);
}



k rotation_z(float x, float y, float z)
{
  k a;
  a.x = x * cos(0.523599) - y * sin(0.523599);
  a.y = x * sin(0.523599) + y * cos(0.523599);
  a.z = z;
  return (a);
}
k rotation_y(float x, float y, float z)
{
  k a;
  a.x = x * cos(0.523599) + z * sin(0.523599);
  a.y = y;
  a.z = -x * sin(0.523599) + z * cos(0.523599);
  return (a);
}

s new_sistem(float axisx, float axisy)
{
  float m = 0.91;
  s a;
  a.x = (axisx + 1000 / 2);
  a.y = (-axisy + 1000 / 2);
  return (a);
}


int clear_and_close(int but,void *param)
{
  int x = 0;
  int y = 0;
  if (but == 53)
    exit(EXIT_SUCCESS);
  if (but == 18)
    mlx_clear_window(mlx, win1);
  if (but == 51)
  {
    while (((x += 50) <= 1000) && ((y += 50) <= 1000))
    {
      draw_line(x, 0, x, 1000, 0xfffafa);
      draw_line(0, y, 1000, y, 0xfffafa);
    }
  }

  return (0);

}

s proektcia(float x1, float y1, float x2, float y2, float z)
{
  s a;
  a.x = (-z / (z - 40) * (x2 - x1) + x2);
  a.y = (-z / (z - 40) * (y2 - y1) + y2);
  return (a);
}

int   mouse(int button, int x, int y, int x1, int y1)
{
   // s c;
    //c = new_sistem(x, y);
    if (button == 1)
        mlx_string_put(mlx, win1, x, y, 0xfffafa, "P I Z D A");
    if (button == 3)
        draw_line(x,y,x1,y1,0xfffafa);
    return (0);
}

int main()
{
    k a0, a8, a9, a10, a11, a12, a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24;
    k a1;
    k a2;
    k a3;
    k a4;
    k a5;
    k a6;
    k a7;
    k atest;
    k atest1;
    s b0,b8,b9,b10,b11,b12,b13,b14,b15,b16,b17,b18,b19,b20,b21,b22,b23,b24;
    s b1;
    s b2;
    s b3;
    s b4;
    s b5;
    s b6;
    s b7;
    s btest;
    s btest1;
    k l0, l1, l2, l3,l4,l5,l6,l7,l8,l9,l10,l11,l12,l13,l14,l15,l16,l17,l18,l19,l20,l21,l22,l23,l24;
    mlx = mlx_init();
    win1 = mlx_new_window(mlx, 1000, 1000, "win1");
    atest.x = -400; atest.y = 400; atest.z = 0;
    atest1.x = -300; atest1.y = 300; atest1.z = 0;
    l0 = rotation_z(atest.x, atest.y, atest.z);
    l1 = rotation_z(atest1.x, atest1.y, atest1.z);
    a0.x = -100; a0.y = -100; a0.z = 0;
    a1.x = -50; a1.y = -100; a1.z = 0;
    a2.x = 0; a2.y = -100; a2.z = 20;
    a3.x = 50; a3.y = -100; a3.z = 0;
    a4.x = 100; a4.y = -100; a4.z = 0;
    a5.x = -100; a5.y = -50; a5.z = 0;
    a6.x = -50; a6.y = -50; a6.z = 0;
    a7.x = 0; a7.y = -50; a7.z = 20;
    a8.x = 50; a8.y = -50; a8.z = 0;
    a9.x = 100; a9.y = -50; a9.z = 0;
    a10.x = -100; a10.y = 0; a10.z = 20;
    a11.x = -50; a11.y = 0; a11.z = 20;
    a12.x = 0; a12.y = 0; a12.z = 20;
    a13.x = 50; a13.y = 0; a13.z = 20;
    a14.x = 100; a14.y = 0; a14.z = 20;
    a15.x = -100; a15.y = 50; a15.z = 0;
    a16.x = -50; a16.y = 50; a16.z = 0;
    a17.x = 0; a17.y = 50; a17.z = 20;
    a18.x = 50; a18.y = 50; a18.z = 0;
    a19.x = 100; a19.y = 50; a19.z = 0;
    a20.x = -100; a20.y = 100; a20.z = 0;
    a21.x = -50; a21.y = 100; a21.z = 0;
    a22.x = 0; a22.y = 100; a22.z = 20;
    a23.x = 50; a23.y = 100; a23.z = 0;
    a24.x = 100; a24.y = 100; a24.z = 0;
    a0 = rotation_z(a0.x, a0.y, a0.z);
    a1 = rotation_z(a1.x, a1.y, a1.z);
    a2 = rotation_z(a2.x, a2.y, a2.z);
    a3 = rotation_z(a3.x, a3.y, a3.z);
    a4 = rotation_z(a4.x, a4.y, a4.z);
    a5 = rotation_z(a5.x, a5.y, a5.z);
    a6 = rotation_z(a6.x, a6.y, a6.z);
    a7 = rotation_z(a7.x, a7.y, a7.z);
    a8 = rotation_z(a8.x, a8.y, a8.z);
    a9 = rotation_z(a9.x, a9.y, a9.z);
    a10 = rotation_z(a10.x, a10.y, a10.z);
    a11 = rotation_z(a11.x, a11.y, a11.z);
    a12 = rotation_z(a12.x, a12.y, a12.z);
    a13 = rotation_z(a13.x, a13.y, a13.z);
    a14 = rotation_z(a14.x, a14.y, a14.z);
    a15 = rotation_z(a15.x, a15.y, a15.z);
    a16 = rotation_z(a16.x, a16.y, a16.z);
    a17 = rotation_z(a17.x, a17.y, a17.z);
    a18 = rotation_z(a18.x, a18.y, a18.z);
    a19 = rotation_z(a19.x, a19.y, a19.z);
    a20 = rotation_z(a20.x, a20.y, a20.z);
    a21 = rotation_z(a21.x, a21.y, a21.z);
    a22 = rotation_z(a22.x, a22.y, a22.z);
    a23 = rotation_z(a23.x, a23.y, a23.z);
    a24 = rotation_z(a24.x, a24.y, a24.z);

    btest = proektcia(0, 0, l0.x, l0.y, l0.z);
    btest1 = proektcia(0, 0, l1.x, l1.y, l1.z);
    b0 = proektcia(0, 0, a0.x, a0.y, a0.z);
    b1 = proektcia(0, 0, a1.x, a1.y, a1.z);
    b2 = proektcia(0, 0, a2.x, a2.y, a2.z);
    b3 = proektcia(0, 0, a3.x, a3.y, a3.z);
    b4 = proektcia(0, 0, a4.x, a4.y, a4.z);
    b5 = proektcia(0, 0, a5.x, a5.y, a5.z);
    b6 = proektcia(0, 0, a6.x, a6.y, a6.z);
    b7 = proektcia(0, 0, a7.x, a7.y, a7.z);
    b8 = proektcia(0, 0, a8.x, a8.y, a8.z);
    b9 = proektcia(0, 0, a9.x, a9.y, a9.z);
    b10 = proektcia(0, 0, a10.x, a10.y, a10.z);
    b11 = proektcia(0, 0, a11.x, a11.y, a11.z);
    b12 = proektcia(0, 0, a12.x, a12.y, a12.z);
    b13 = proektcia(0, 0, a13.x, a13.y, a13.z);
    b14 = proektcia(0, 0, a14.x, a14.y, a14.z);
    b15 = proektcia(0, 0, a15.x, a15.y, a15.z);
    b16 = proektcia(0, 0, a16.x, a16.y, a16.z);
    b17 = proektcia(0, 0, a17.x, a17.y, a17.z);
    b18 = proektcia(0, 0, a18.x, a18.y, a18.z);
    b19 = proektcia(0, 0, a19.x, a19.y, a19.z);
    b20 = proektcia(0, 0, a20.x, a20.y, a20.z);
    b21 = proektcia(0, 0, a21.x, a21.y, a21.z);
    b22 = proektcia(0, 0, a22.x, a22.y, a22.z);
    b23 = proektcia(0, 0, a23.x, a23.y, a23.z);
    b24 = proektcia(0, 0, a24.x, a24.y, a24.z);
    int x = 0, y = 0, lenx = 1000, leny = 1000;

    s c0, c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13,c14,c15,c16,c17,c18,c19,c20,c21,c22,c23,c24, ctest, ctest1;
    c0 = new_sistem(b0.x, b0.y);
    c1 = new_sistem(b1.x, b1.y);
    c2 = new_sistem(b2.x, b2.y);
    c3 = new_sistem(b3.x, b3.y);
    c4 = new_sistem(b4.x, b4.y);
    c5 = new_sistem(b5.x, b5.y);
    c6 = new_sistem(b6.x, b6.y);
    c7 = new_sistem(b7.x, b7.y);
    c8 = new_sistem(b8.x, b8.y);
    c9 = new_sistem(b9.x, b9.y);
    c10 = new_sistem(b10.x, b10.y);
    c11 = new_sistem(b11.x, b11.y);
    c12 = new_sistem(b12.x, b12.y);
    c13 = new_sistem(b13.x, b13.y);
    c14 = new_sistem(b14.x, b14.y);
    c15 = new_sistem(b15.x, b15.y);
    c16 = new_sistem(b16.x, b16.y);
    c17 = new_sistem(b17.x, b17.y);
    c18 = new_sistem(b18.x, b18.y);
    c19 = new_sistem(b19.x, b19.y);
    c20 = new_sistem(b20.x, b20.y);
    c21 = new_sistem(b21.x, b21.y);
    c22 = new_sistem(b22.x, b22.y);
    c23 = new_sistem(b23.x, b23.y);
    c24 = new_sistem(b24.x, b24.y);
    ctest = new_sistem(btest.x, btest.y);
    ctest1 = new_sistem(btest1.x, btest1.y);
    printf("%d\n%d\n", (int)c17.x, (int)c17.y);
    printf("%d\n%d\n", (int)c12.x, (int)c12.y);
    //printf("%f\n%f\n", ctest.x, ctest.y);
    //printf("%f\n%f\n", ctest1.x, ctest1.y);
   /* c0 = rotation_z(b0.x, b0.y);
    c1 = rotation_z(b1.x, b1.y);
    c2 = rotation_z(b2.x, b2.y);
    c3 = rotation_z(b3.x, b3.y);
    c4 = rotation_z(b4.x, b4.y);
    c5 = rotation_z(b5.x, b5.y);
    c6 = rotation_z(b6.x, b6.y);
    c7 = rotation_z(b7.x, b7.y);
    c8 = rotation_z(b8.x, b8.y);
    c9 = rotation_z(b9.x, b9.y);
    c10 = rotation_z(b1.x, b10.y);
    c11 = rotation_z(b11.x, b11.y);
    c12 = rotation_z(b12.x, b12.y);
    c13 = rotation_z(b13.x, b13.y);
    c14 = rotation_z(b14.x, b14.y);
    c15 = rotation_z(b15.x, b15.y);
    c16 = rotation_z(b16.x, b16.y);
    c17 = rotation_z(b17.x, b17.y);
    c18 = rotation_z(b18.x, b18.y);
    c19 = rotation_z(b19.x, b19.y);
    c20 = rotation_z(b20.x, b20.y);
    c21 = rotation_z(b21.x, b21.y);
    c22 = rotation_z(b22.x, b22.y);
    c23 = rotation_z(b23.x, b23.y);
    c24 = rotation_z(b24.x, b24.y);
*/

    //draw_line((int)ctest.x, (int)ctest.y, (int)ctest1.x , (int)ctest1.y, 0xff0000);
    //draw_line(899, 900, 799 , 800, 0xff0000);
    draw_line((int)c0.x, (int)c0.y, (int)c1.x , (int)c1.y, 0xff0000);
    draw_line((int)c0.x,(int)c0.y,(int)c5.x , (int)c5.y, 0xff0000);
    draw_line((int)c1.x,(int)c1.y,(int)c2.x , (int)c2.y, 0xff0000);
    draw_line((int)c1.x,(int)c1.y,(int)c6.x , (int)c6.y, 0xff0000);
    draw_line((int)c2.x,(int)c2.y,(int)c3.x , (int)c3.y, 0xff0000);
    draw_line((int)c2.x,(int)c2.y,(int)c7.x , (int)c7.y, 0xff0000);
    draw_line((int)c3.x,(int)c3.y,(int)c4.x , (int)c4.y, 0xff0000);
    draw_line((int)c3.x,(int)c3.y,(int)c8.x , (int)c8.y, 0xff0000);
    draw_line((int)c4.x,(int)c4.y,(int)c9.x , (int)c9.y, 0xff0000);
    draw_line((int)c5.x,(int)c5.y,(int)c6.x , (int)c6.y, 0xff0000);
    draw_line((int)c5.x,(int)c5.y,(int)c10.x , (int)c10.y, 0xff0000);
    draw_line((int)c6.x,(int)c6.y,(int)c7.x , (int)c7.y, 0xff0000);
    draw_line((int)c6.x,(int)c6.y,(int)c11.x , (int)c11.y, 0xff0000);
    draw_line((int)c7.x,(int)c7.y,(int)c8.x , (int)c8.y, 0xff0000);
    draw_line((int)c7.x,(int)c7.y,(int)c12.x , (int)c12.y, 0xff0000);
    draw_line((int)c8.x,(int)c8.y,(int)c9.x , (int)c9.y, 0xff0000);
    draw_line((int)c8.x,(int)c8.y,(int)c13.x , (int)c13.y, 0xff0000);
    draw_line((int)c9.x,(int)c9.y,(int)c14.x , (int)c14.y, 0xff0000);
    draw_line((int)c10.x,(int)c10.y,(int)c11.x , (int)c11.y, 0xff0000);
    draw_line((int)c10.x,(int)c10.y,(int)c15.x , (int)c15.y, 0xff0000);
    draw_line((int)c11.x,(int)c11.y,(int)c12.x , (int)c12.y, 0xff0000);
    draw_line((int)c11.x,(int)c11.y,(int)c16.x , (int)c16.y, 0xff0000);
    draw_line((int)c12.x,(int)c12.y,(int)c13.x , (int)c13.y, 0xff0000);
    draw_line((int)c12.x,(int)c12.y,(int)c17.x ,(int)c17.y, 0xff0000);
    draw_line((int)c13.x,(int)c13.y,(int)c14.x , (int)c14.y, 0xff0000);
    draw_line((int)c13.x,(int)c13.y,(int)c18.x , (int)c18.y, 0xff0000);
    draw_line((int)c14.x,(int)c14.y,(int)c19.x , (int)c19.y, 0xff0000);
    draw_line((int)c15.x,(int)c15.y,(int)c16.x , (int)c16.y, 0xff0000);
    draw_line((int)c15.x,(int)c15.y,(int)c20.x ,(int)c20.y, 0xff0000);
    draw_line((int)c16.x,(int)c16.y,(int)c17.x ,(int)c17.y, 0xff0000);
    draw_line((int)c16.x,(int)c16.y,(int)c21.x ,(int)c21.y, 0xff0000);
    draw_line((int)c17.x,(int)c17.y,(int)c18.x ,(int)c18.y, 0xff0000);
    draw_line((int)c17.x,(int)c17.y,(int)c22.x ,(int)c22.y, 0xff0000);
    draw_line((int)c18.x,(int)c18.y,(int)c19.x ,(int)c19.y, 0xff0000);
    draw_line((int)c18.x,(int)c18.y,(int)c23.x ,(int)c23.y, 0xff0000);
    draw_line((int)c19.x,(int)c19.y,(int)c24.x ,(int)c24.y, 0xff0000);
    draw_line((int)c20.x,(int)c20.y,(int)c21.x ,(int)c21.y, 0xff0000);
    draw_line((int)c21.x,(int)c21.y,(int)c22.x ,(int)c22.y, 0xff0000);
    draw_line((int)c22.x,(int)c22.y,(int)c23.x ,(int)c23.y, 0xff0000);
    draw_line((int)c23.x,(int)c23.y,(int)c24.x ,(int)c24.y, 0xff0000);
    mlx_key_hook(win1, clear_and_close, 0);
    mlx_mouse_hook(win1, mouse, 0);
    //mlx_mouse_hook(win1, mouse, 0);
    mlx_loop(mlx);
    return (0);

}
