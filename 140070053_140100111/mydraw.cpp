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
unsigned int W = 900;
unsigned int H = 512;

unsigned int window_W = W;
unsigned int window_H = H;

canvas_t my_canvas;
pen_t my_pen;

//colors taken as input from terminal
float r,g,b;

//boolean value
bool pen_mode=0;//0 means draw  1 means erase
bool draw_mode=0; // 0 means line; 1 means triangle
bool fill_flag=0; //0 means dont fill

bool triangle_empty=1;
bool line_empty=1;

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
int total_lines=0;
int total_triangles=0;


//Save the other important global variables

void save_globals()
{
  ofstream myfile;
  myfile.open("globals.txt");
  if(!line_pts.empty())
  {
    line_empty = 0;
  myfile<<line_pts[0].get_x()<<" "<<line_pts[0].get_y()<<"\n";
  myfile<<line_pts[1].get_x()<<" "<<line_pts[1].get_y()<<"\n";
  }
  else
    line_empty = 1;

  if(!triangle_pts.empty())
  {
    triangle_empty = 0;
  myfile<<triangle_pts[0].get_x()<<" "<<triangle_pts[0].get_y()<<"\n";
  myfile<<triangle_pts[1].get_x()<<" "<<triangle_pts[1].get_y()<<"\n";
  myfile<<triangle_pts[2].get_x()<<" "<<triangle_pts[2].get_y()<<"\n";
  }
  else
    triangle_empty = 1;

  myfile<<total_lines<<"\n";
  myfile<<total_triangles<<"\n";

  myfile.close();
}


//Load the other important global variables
void load_globals()
{
  ifstream myfile;
  myfile.open("globals.txt");
  int a[12];
  int i = 0;
  while(!myfile.eof())
   {
      myfile >> a[i];
      i++;
   }
   if(triangle_empty && line_empty)
   {
   total_lines = a[0];
   total_triangles = a[1]; 
   }

  else if(triangle_empty && !line_empty) 
  { 
   line_pts[0].set_point(a[0],a[1]);
   line_pts[1].set_point(a[2],a[3]);
   total_lines = a[4];
   total_triangles = a[5]; 
  }
  
  else if(!triangle_empty && line_empty) 
  { 
   triangle_pts[0].set_point(a[0],a[1]);
   triangle_pts[1].set_point(a[2],a[3]);
   triangle_pts[2].set_point(a[4],a[5]);
   total_lines = a[6];
   total_triangles = a[7]; 
  }  

  else
  {
   line_pts[0].set_point(a[0],a[1]);
   line_pts[1].set_point(a[2],a[3]);
   triangle_pts[0].set_point(a[4],a[5]);
   triangle_pts[1].set_point(a[6],a[7]);
   triangle_pts[2].set_point(a[8],a[9]);
   total_lines = a[10];
   total_lines = a[11];
  }

   myfile.close();     
}

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
  if(h == 0) 
  {
    h = 1;
  }  
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  glOrtho( 0.0, (GLdouble)w, 0.0, (GLdouble)h, -1., 1. );
  glViewport( 0, 0, w, h );
  window_W = w;
  window_H = h;
  glutPostRedisplay();
}
//Keyboard callback
void keyboard( unsigned char key, int x, int y ) {
  switch(key) {
  
  case 'N':
  //intialize new canvas
  //2D array to the background color
  //backg color for the is input from terminal/file
    my_canvas.clear_canvas();
    my_canvas.clear_lines();
    my_canvas.clear_triangles();
    line_pts.clear();
    triangle_pts.clear();
    total_lines = 0;
    total_triangles = 0;
    cout<<"enter the new background color::"<<endl;
    cout<<"Red part::"<<endl;
    cin>> r;
    cout<<"Green part::"<<endl;
    cin>>g;
    cout<<"Blue part::"<<endl;
    cin>>b;
    b_c.set(r,g,b);
    glutPostRedisplay();
    break;
  case 'C':
    //clear the canvas
    my_canvas.clear_canvas();
    my_canvas.clear_lines();
    my_canvas.clear_triangles();
    line_pts.clear();
    triangle_pts.clear();
    total_lines = 0;
    total_triangles = 0;
    glutPostRedisplay();
    break;
  case 'S':
    //save into file
    //save into file
    my_canvas.save(H,W);
    save_globals();

    break;
  case 'L':
    //load from file
    my_canvas.load(H,W);
    load_globals();
    glutPostRedisplay();
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
    my_canvas.change_fill_color(f_c, fill_flag);
    glutPostRedisplay();
    break;
  case 'G':
    //change fill color
    cout<<"enter the new fill color::"<<endl;
    cout<<"Red part::"<<endl;
    cin>> r;
    cout<<"Green part::"<<endl;
    cin>>g;
    cout<<"Blue part::"<<endl;
    cin>>b;
    f_c.set(r,g,b);
    glutPostRedisplay();
    break;
  case 'H':
    //change pen color
    cout<<"enter the new pen color::"<<endl;
    cout<<"Red part::"<<endl;;
    cin>> r;
    cout<<"Green part::"<<endl;
    cin>>g;
    cout<<"Blue part::"<<endl;
    cin>>b;
    d_c.set(r,g,b);
    my_pen.set_p_c(d_c);
    glutPostRedisplay();
    break;
  case 'I':
    //change bgrd color
    cout<<"enter the new background color::"<<endl;
    cout<<"Red part::"<<endl;;
    cin>> r;
    cout<<"Green part::"<<endl;
    cin>>g;
    cout<<"Blue part::"<<endl;
    cin>>b;
    b_c.set(r,g,b);
    my_pen.set_b_c(b_c);
    glutPostRedisplay();
    break;
  case 'J':
    //change pen width
    cout<<"enter the thickness of pen"<<endl;
    cin>>thickness;
    my_pen.set_thickness(thickness);
    glutPostRedisplay();
    break;
  case 'M':
    cout<<"enter mode, 0-pen, 1-eraser"<<endl;
    cin>>pen_mode;
    my_pen.set_mode(pen_mode);
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
  int _y = window_H-y;
 // cout<<_x << "::"<<_y<<endl;
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
        if(line_pts.size()==2)
        {
          line_pts[0]=line_pts[1];
          line_pts.pop_back();
        }
        line_pts.push_back(temp_point);
        if(line_pts.size()==2)
        { 
          if(!my_pen.get_mode())
          {
            temp_line.set_line(line_pts[0],line_pts[1], thickness, my_pen.get_p_c());
          }
          else
          {
            temp_line.set_line(line_pts[0],line_pts[1], thickness, my_pen.get_b_c());
          } 
          my_canvas.add_line_to_drawing(temp_line);
          total_lines = total_lines + 1;
        }    
      }
      else
      {
        if(triangle_pts.size()==3)
        {
          triangle_pts[0]=triangle_pts[1];
          triangle_pts[1]=triangle_pts[2];
          triangle_pts.pop_back();
        }
        triangle_pts.push_back(temp_point);
        if(triangle_pts.size()==3)
        {
          temp_triangle.set_triangle(triangle_pts[0],triangle_pts[1],triangle_pts[2],my_pen.get_p_c(),f_c,thickness,fill_flag);
          my_canvas.add_triangle_to_drawing(temp_triangle);
          total_triangles = total_triangles + 1;
        }  
      }
      //===//
    }
    if (button == GLUT_RIGHT_BUTTON)
    {
      if (!draw_mode)
      {
        if(total_lines!=0)
        {
          total_lines = total_lines-1;
          //cout<<total_lines<<endl;
          temp_line = my_canvas.pop_line_from_drawing();
          line_pts.clear();
          line_pts.push_back(temp_line.get_end());
          line_pts.push_back(temp_line.get_start());
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
          //cout<<total_triangles<<endl;
          temp_triangle = my_canvas.pop_triangle_from_drawing();
          triangle_pts.clear();
          triangle_pts.push_back(temp_triangle.get_3());
          triangle_pts.push_back(temp_triangle.get_1());
          triangle_pts.push_back(temp_triangle.get_2());
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
  my_pen.set_mode(pen_mode);
  my_pen.set_thickness(thickness);
  my_pen.set_p_c(d_c);
  my_pen.set_b_c(b_c);

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
  glutInitWindowSize( window_W, window_H );

  //Open a GLUT window
  glutCreateWindow( "MyDraw" );
  glutDisplayFunc( display );
  glutReshapeFunc( reshape );
  glutKeyboardFunc( keyboard );
  glutMouseFunc( mouse );
  glutMainLoop();
}
