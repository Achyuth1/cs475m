/*******************************
 * CS475m Assignment 1 Basecode 
 *
 *Achyutha Krishna
 *Athul AR
 *
 *******************************/


#include <cmath>
#include <cstdlib>
#include <iostream>
#include <GL/glut.h>
#include "mydraw_class.hpp"

using namespace std;

//unsigned
unsigned int W = 512;
unsigned int H = 512;
canvas_t my_canvas;

//boolean value
bool draw_mode=0; // 0 means line; 1 means triangle
bool fill_flag=0; //o means dont fill

color_t green(0.0,1.0,0.0);
color_t red(1.0,0.0,0.0);
color_t blue(0.0,0.0,1.0);
color_t b_c(1.0,1.0,1.0);
color_t d_c(0.0,0.0,0.0);
color_t f_c(1.0,0.0,0.0);

int thickness = 1;

//points from mouse clicks
vector<point_t> line_pts;
vector<point_t> triangle_pts;
int total_lines;
int total_triangles;

//Display callback
void display( )
{
  my_canvas.set_bgd_color(b_c);
  my_canvas.draw_current_drawing();
  fill_flag =0;
  glClearColor( 0, 0, 0, 1 );
  glClear( GL_COLOR_BUFFER_BIT );
  color_t** buffer;   
  GLubyte data[H][W][3];
  buffer = my_canvas.get_buffer();

    for( int b = 0; b <W; b++ )
    {
        for( int a = 0; a < H; a++ )
        {
            data[a][b][0] = (GLubyte) (int) (buffer[a][b].R() *255 );
            data[a][b][1] = (GLubyte) (int) (buffer[a][b].G() *255 );
            data[a][b][2] = (GLubyte) (int) (buffer[a][b].B() *255 );
        }
    }
  glDrawPixels( W, H, GL_RGB, GL_UNSIGNED_BYTE, data);
    
  glutSwapBuffers();
}

//Reshape callback
void reshape( int w, int h )
{
  if  ( h == 0 ) h = 1;

  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();

  glOrtho( 0.0, (GLdouble)w, 0.0, (GLdouble)h, -1., 1. );
  glViewport( 0, 0, w, h );

  W = w;
  H = h;

  glutPostRedisplay();
}

//Keyboard callback
void keyboard( unsigned char key, int x, int y ) {
  switch(key) {
  
  case 'N':
  //intialize new canvas
  //2D array to the background color
  //backg color for the is input from terminal/file
    break;
  case 'C':
    //clear the canvas
    break;
  case 'S':
    //save into file
    break;
  case 'L':
    //load from file
    break;
  case '1':
    //line drawing mode
    draw_mode = 0;
    break;
  case '2':
    //triangle mode
    draw_mode = 1;
    break;
  case 'F':
    //fill triangle
    fill_flag = 1;
    break;
  case 'G':
    //change fill color
    break;
  case 'H':
    //change pen color
    break;
  case 'I':
    //change bgrd color
    break;
  case 'J':
    //change pen width
    break;
  //Exit on pressing escape
  case 27: 
    exit(0);
    break;
  //Ignore all other keypresses
  default:
    break;
  }
}


//Mouse callback
void mouse(int button, int state, int x, int y) 
{
  int _x = x;
  int _y = H-y;
  
  point_t temp_point;
  line_t temp_line;
  triangle_t temp_triangle;

  if (state == GLUT_DOWN) 
  {
    if (button == GLUT_LEFT_BUTTON)
    {

      temp_point.set_point(_x,_y);
      if (!draw_mode)
      { 
        line_pts.push_back(temp_point);
        if(line_pts.size()==2)
        {
          temp_line.set_line(line_pts[0],line_pts[1], thickness, d_c);
          my_canvas.add_line_to_drawing(temp_line);
          total_lines = total_lines + 1;
        }    
      }
      else
      {
        triangle_pts.push_back(temp_point);
        if(triangle_pts.size()==3)
        {
          temp_triangle.set_triangle(triangle_pts[0],triangle_pts[1],triangle_pts[2],d_c,f_c,thickness,fill_flag);
          my_canvas.add_triangle_to_drawing(temp_triangle);
          total_triangles = total_triangles + 1;
        }  
      }
      if(line_pts.size()==2)
      {
        line_pts[0]=line_pts[1];
        line_pts.pop_back();
      }
      if(triangle_pts.size()==3)
      {
        triangle_pts[0]=triangle_pts[1];
        triangle_pts[1]=triangle_pts[2];
        triangle_pts.pop_back();
      }
    }
    if (button == GLUT_RIGHT_BUTTON)
    {
      if (!draw_mode)
      {
        if(total_lines!=0)
        {
          total_lines = total_lines-1;
          cout<<total_lines<<endl;
          temp_line = my_canvas.pop_line_from_drawing();
          line_pts.clear();
          line_pts.push_back(temp_line.get_start());
          line_pts.push_back(temp_line.get_end());
          my_canvas.clear_canvas();
        }
        if(total_lines==0)
        {
          if(line_pts.size()!=0)
          {
            line_pts.pop_back();
          }
        }
      }
      else
      {
        if(total_triangles!=0)
        {
          total_triangles = total_triangles-1;
          cout<<total_triangles<<endl;
          temp_triangle = my_canvas.pop_triangle_from_drawing();
          triangle_pts.clear();
          triangle_pts.push_back(temp_triangle.get_1());
          triangle_pts.push_back(temp_triangle.get_2());
          triangle_pts.push_back(temp_triangle.get_3());
          my_canvas.clear_canvas();
        }
        if(total_triangles==0)
        {
          if(triangle_pts.size()!=0)
          {
            triangle_pts.pop_back();
          }
        }
      }
    }
  }
  glutPostRedisplay();
} 

int main (int argc, char *argv[]) 
{

  int t = 2;  
  drawing_t my_drawing;
  color_t** buffer = new color_t*[H];
  for(int i = 0; i < H; ++i)
  { 
      buffer[i] = new color_t[W];
  }

  my_canvas.set_canvas(my_drawing, H, W, b_c, buffer);
  my_canvas.clear_canvas();

  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
  glutInitWindowSize( W, H );

  //Open a GLUT window
  glutCreateWindow( "MyDraw" );
  glutDisplayFunc( display );
  glutReshapeFunc( reshape );
  glutKeyboardFunc( keyboard );
  glutMouseFunc( mouse );
  glutMainLoop();
}
