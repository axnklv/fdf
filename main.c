
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <math.h>

void *mlx;
void *win1;

int   draw_line(double x1, double  y1, double x2, double  y2, int color)
{
  double lenghtx = (x2 - x1);
  double lenghty = (y2 - y1);
  int dx = (lenghtx > 0 ? 1 : -1);
  int dy = (lenghty > 0 ? 1 : -1);
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
        mlx_pixel_put(mlx, win1,x, y, color);      
        x = x + dx;
        y = x * k + b;
      }
  }
  return (0);
}



k rotation_z(float x, float y, float z)
{
  k a;
  a.x = x * cos(0.5) - y * sin(0.5);
  a.y = x * sin(0.5) + y * cos(0.5);
  a.z = z;
  return (a);
}
k rotation_y(float x, float y, float z)
{
  k a;
  a.x = x * cos(0) + z * sin(0);
  a.y = y;
  a.z = -x * sin(0) + z * cos(0);
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

s line(float x1, float y1, float x2, float y2, float z)
{
  s a;
  a.x = (-z / (z - 40) * (x2 - x1) + x2);
  a.y = (-z / (z - 40) * (y2 - y1) + y2);
  return (a);
}

int   mouse(int button, int z, int x , int y)
{
    if (button == 1)
        mlx_string_put(mlx, win1, 500, 500, 0xfffafa, "P I Z D A");
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
    s b0,b8,b9,b10,b11,b12,b13,b14,b15,b16,b17,b18,b19,b20,b21,b22,b23,b24;
    s b1;
    s b2;
    s b3;
    s b4;
    s b5;
    s b6;
    s b7;
    k l0, l1, l2, l3,l4,l5,l6,l7,l8,l9,l10,l11,l12,l13,l14,l15,l16,l17,l18,l19,l20,l21,l22,l23,l24;
    mlx = mlx_init();
    win1 = mlx_new_window(mlx, 1000, 1000, "win1");
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
    /*a0 = rotation_z(a0.x, a0.y, a0.z);
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
    printf("%f\n%f\n%f\n", a10.x, a10.y, a10.z);*/




    b0 = line(-30, -30, a0.x, a0.y, a0.z);
    b1 = line(-30, -30, a1.x, a1.y, a1.z);
    b2 = line(-30, -30, a2.x, a2.y, a2.z);
    b3 = line(-30, -30, a3.x, a3.y, a3.z);
    b4 = line(-30, -30, a4.x, a4.y, a4.z);
    b5 = line(-30, -30, a5.x, a5.y, a5.z);
    b6 = line(-30, -30, a6.x, a6.y, a6.z);
    b7 = line(-30, -30, a7.x, a7.y, a7.z);
    b8 = line(-30, -30, a8.x, a8.y, a8.z);
    b9 = line(-30, -30, a9.x, a9.y, a9.z);
    b10 = line(-30, -30, a10.x, a10.y, a10.z);
    b11 = line(-30, -30, a11.x, a11.y, a11.z);
    b12 = line(-30, -30, a12.x, a12.y, a12.z);
    b13 = line(-30, -30, a13.x, a13.y, a13.z);
    b14 = line(-30, -30, a14.x, a14.y, a14.z);
    b15 = line(-30, -30, a15.x, a15.y, a15.z);
    b16 = line(-30, -30, a16.x, a16.y, a16.z);
    b17 = line(-30, -30, a17.x, a17.y, a17.z);
    b18 = line(-30, -30, a18.x, a18.y, a18.z);
    b19 = line(-30, -30, a19.x, a19.y, a19.z);
    b20 = line(-30, -30, a20.x, a20.y, a20.z);
    b21 = line(-30, -30, a21.x, a21.y, a21.z);
    b22 = line(-30, -30, a22.x, a22.y, a22.z);
    b23 = line(-30, -30, a23.x, a23.y, a23.z);
    b24 = line(-30, -30, a24.x, a24.y, a24.z);
    int x = 0, y = 0, lenx = 1000, leny = 1000;  
    
    s c0, c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13,c14,c15,c16,c17,c18,c19,c20,c21,c22,c23,c24;
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

    draw_line(c0.x, c0.y, c1.x , c1.y, 0xff0000);
    draw_line(c0.x, c0.y, c5.x , c5.y, 0xff0000);
    draw_line(c1.x, c1.y, c2.x , c2.y, 0xff0000);
    draw_line(c1.x, c1.y, c6.x , c6.y, 0xff0000);
    draw_line(c2.x, c2.y, c3.x , c3.y, 0xff0000);
    draw_line(c2.x, c2.y, c7.x , c7.y, 0xff0000);
    draw_line(c3.x, c3.y, c4.x , c4.y, 0xff0000);
    draw_line(c3.x, c3.y, c8.x , c8.y, 0xff0000);
    draw_line(c4.x, c4.y, c9.x , c9.y, 0xff0000);
    draw_line(c5.x, c5.y, c6.x , c6.y, 0xff0000);
    draw_line(c5.x, c5.y, c10.x , c10.y, 0xff0000);
    draw_line(c6.x, c6.y, c7.x , c7.y, 0xff0000);
    draw_line(c6.x, c6.y, c11.x , c11.y, 0xff0000);
    draw_line(c7.x, c7.y, c8.x , c8.y, 0xff0000);
    draw_line(c7.x, c7.y, c12.x , c12.y, 0xff0000);
    draw_line(c8.x, c8.y, c9.x , c9.y, 0xff0000);
    draw_line(c8.x, c8.y, c13.x , c13.y, 0xff0000);
    draw_line(c9.x, c9.y, c14.x , c14.y, 0xff0000);
    draw_line(c10.x, c10.y, c11.x , c11.y, 0xff0000);
    draw_line(c10.x, c10.y, c15.x , c15.y, 0xff0000);
    draw_line(c11.x, c11.y, c12.x , c12.y, 0xff0000);
    draw_line(c11.x, c11.y, c16.x , c16.y, 0xff0000);
    draw_line(c12.x, c12.y, c13.x , c13.y, 0xff0000);
    draw_line(c12.x, c12.y, c17.x , c17.y, 0xff0000);
    draw_line(c13.x, c13.y, c14.x , c14.y, 0xff0000);
    draw_line(c13.x, c13.y, c18.x , c18.y, 0xff0000);
    draw_line(c14.x, c14.y, c19.x , c19.y, 0xff0000);
    draw_line(c15.x, c15.y, c16.x , c16.y, 0xff0000);
    draw_line(c15.x, c15.y, c20.x , c20.y, 0xff0000);
    draw_line(c16.x, c16.y, c17.x , c17.y, 0xff0000);
    draw_line(c16.x, c16.y, c21.x , c21.y, 0xff0000);
    draw_line(c17.x, c17.y, c18.x , c18.y, 0xff0000);
    draw_line(c17.x, c17.y, c22.x , c22.y, 0xff0000);
    draw_line(c18.x, c18.y, c19.x , c19.y, 0xff0000);
    draw_line(c18.x, c18.y, c23.x , c23.y, 0xff0000);
    draw_line(c19.x, c19.y, c24.x , c24.y, 0xff0000);
    draw_line(c20.x, c20.y, c21.x , c21.y, 0xff0000);
    draw_line(c21.x, c21.y, c22.x , c22.y, 0xff0000);
    draw_line(c22.x, c22.y, c23.x , c23.y, 0xff0000);
    draw_line(c23.x, c23.y, c24.x , c24.y, 0xff0000);
    mlx_key_hook(win1, clear_and_close, 0);
    mlx_mouse_hook(win1, mouse, 0);
    //mlx_mouse_hook(win1, mouse, 0);
    mlx_loop(mlx);
    return (0);

}