/*******************************
 * CS475m Assignment 1 Basecode 
 *
 *Achyutha Krishna
 *Athul AR
 *
 *May the force be with us
 *May the openGL also be with us 
 *
 *******************************/


#include <cmath>
#include <cstdlib>
#include <iostream>
#include <GL/glut.h>
#include "mydraw_class.hpp"

using namespace std;


unsigned int W = 100;
unsigned int H = 100;
canvas_t my_canvas;

color_t green(0.0,1.0,0.0);
color_t red(1.0,0.0,0.0);
color_t blue(0.0,0.0,1.0);
color_t b_c(1.0,1.0,1.0);
color_t d_c(1.0,1.0,0.0);

//Display callback
void display( )
{
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
    break;
  case '2':
    //triangle mode
    break;
  case 'F':
    //fill triangle
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
  if (state == GLUT_DOWN) 
  {
    if (button == GLUT_LEFT_BUTTON)
    {
      cout<<"button clicked"<<endl<<endl;
      cout<<"x ::"<< _x <<endl;
      cout<<"y ::"<< _y <<endl;
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

  point_t a(50,50);
  point_t b(10,10);
  point_t c(10,50);
  point_t d(50,10);

  line_t ab(a,b,t,d_c);
  line_t cd(c,d,t,d_c);

  triangle_t abc(a,b,c,red,t);
  triangle_t bcd(b,c,d,blue,t);


  my_canvas.clear_canvas();

  my_canvas.add_line_to_drawing(ab);
  my_canvas.add_line_to_drawing(cd);
  my_canvas.add_triangle_to_drawing(abc);
  my_canvas.add_triangle_to_drawing(bcd);

  my_canvas.draw_current_drawing();

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
