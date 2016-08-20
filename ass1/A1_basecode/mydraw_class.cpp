#include "mydraw_class.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

void swap (int &x, int &y)
{
  int temp = x;
  x = y; y = temp;
}

//-------------------
//color_t methods

color_t::color_t():r(0.0),g(0.0),b(0.0) { }

color_t::color_t(const float _r, const float _g, const float _b) :r(_r),g(_g),b(_b) {}

void color_t::set(const float _r, const float _g, const float _b)
{ 
  r=_r; g=_g; b=_b;
  return ;
}

float color_t::R(void) { return r; }
float color_t::G(void) { return g; }
float color_t::B(void) { return b; }


//---------------------
//pen_t methods

pen_t::	pen_t()
{
	size = 1;
	mode = true;
}

pen_t::pen_t(const int _size, const bool _mode, color_t pen_c, color_t bg_c)
{
	size = _size;
	mode = _mode;
	bgd_color = bg_c;
	pen_color = pen_c;
}  

void pen_t::set(const int _size, const bool _mode, color_t pen_c, color_t bg_c)
{
	size = _size;
	mode = _mode;
	bgd_color = bg_c;
	pen_color = pen_c;
	return;
}

//---------------------
//fill_t methods
fill_t::fill_t()
{
	color_t temp(0.0,0.0,0.0);
	curr_color = temp;
	bnd_color = temp;
}
fill_t::fill_t(color_t _curr_color, color_t _bnd_color)
{
	curr_color = _curr_color;
	bnd_color = _bnd_color;
}

void fill_t::set_bg(color_t _bnd_color)
{
	bnd_color = _bnd_color;
}

void fill_t::set_curr(color_t _curr_color){
	curr_color = _curr_color;
}

void fill_t::draw_fill()
{
	// may OPENGL be with us//
	//have to fill the code
}  
//---------------------
//point_t methods

point_t::point_t()
{
	x = 0;
	y = 0;
}
point_t::point_t(int _x, int _y)
{
	x = _x;
	y = _y;
}
void point_t::set_point(int _x, int _y)
{
	x = _x;
	y = _y;	
}
int point_t::get_x()
{
	return x;
}
int point_t::get_y()
{
	return y;
}
void point_t::draw_point(color_t c, int t, color_t **buffer)
{
	//to be filled
/*	GLubyte data[t][t][3];
    for( int b = 0; b <t; b++ )
    {
        for( int a = 0; a < t; a++ )
        {
            data[a][b][0] = (GLubyte) (int) ( c.r *255 );
            data[a][b][1] = (GLubyte) (int) ( c.g *255 );
            data[a][b][2] = (GLubyte) (int) ( c.b *255 );
        }
    }
    float _x = (float) (x- W/2)*2/W;
    float _y = (float) (y- H/2)*2/H;
    
	glRasterPos2f(_x,_y);
    glDrawPixels( t, t, GL_RGB, GL_UNSIGNED_BYTE, data);*/
	cout<<"inside"<<endl;
	cout<<buffer[0][0].R() << endl;
	for (int i = 0; i < t; ++i)
	{
		cout<<"in 1"<<endl;
		for (int j = 0; j < t; ++j)
		{
			cout<<"in2"<<endl;
			cout<<buffer[0][0].R() << endl;
			//c is also color_t type
			buffer[i+x][j+y] = c;
			cout<< i <<"::"<<j<<endl;
		}
	}
}

//------------------------------
//line_t methods
line_t::line_t()
{
	point_t c;
	Vi = c;
	Vf = c;
}
line_t::line_t(point_t _Vi, point_t _Vf)
{
	Vi = _Vi;
	Vf = _Vf;
}
void line_t::set_line(point_t _Vi, point_t _Vf)
{
	Vi = _Vi;
	Vf = _Vf;
}
void line_t::draw_line(color_t c, int t, color_t **buffer)
{

  int x0 = Vi.get_x();
  int x1 = Vf.get_x();
  int y0 = Vi.get_y();
  int y1 = Vf.get_y();

  bool steep = std::abs(y1 - y0) > std::abs(x1 - x0);
  
  if (steep)                // swap x and y of both the points
    {
      swap(x0, y0);
      swap(x1, y1);
    }
  if (x0 > x1)              // swap the start and end of the line
    {
      swap(x0, x1);
      swap(y0, y1);
    }

  int deltax = x1 - x0;
  int deltay = abs(y1 - y0);

  float error = 0.0;
  float deltaerr = (float)deltay / (float)deltax;

  int ystep;
  int y = y0;

  if (y0 < y1)
     ystep = 1;
  else 
     ystep = -1;

  point_t temp_pt;
  for (int x=x0; x < x1; x++)
    {
      if (steep)      //  change the color of pixel (y,x) with color c
      {
      	temp_pt.set_point(y,x);
      	temp_pt.draw_point(c, t, buffer);
        //buffer[y][x] = c;
      }
      else            //  change the color of pixel (x,y) with color c
      {
      	temp_pt.set_point(x,y);
      	temp_pt.draw_point(c, t, buffer);
        //buffer[x][y] = c;
      }

      error = error + deltaerr;
      if (error >= 0.5) 
        {
            y = y + ystep;
            error = error - 1.0;
        }
    }
}
//--------------------------------
//triangle_t
triangle_t::triangle_t()
{
	point_t c;
	A = c;
	B = c;
	C = c;
}
triangle_t::triangle_t(point_t _A, point_t _B, point_t _C)
{
	A = _A;
	B = _B;
	C = _B;
}
void triangle_t::set_triangle(point_t _A, point_t _B, point_t _C)
{
	A = _A;
	B = _B;
	C = _B;
}	
void triangle_t::draw_triangle(color_t c, int t, color_t **buffer)
{
	line_t AB(A,B), BC(B,C), CA(C,A);
	AB.draw_line(c, t, buffer);
	BC.draw_line(c, t, buffer);
	CA.draw_line(c, t, buffer);	
}
//--------------------------------
//drawing_t
drawing_t::drawing_t()
{

}
void drawing_t::draw_drawing()
{

}
//--------------------------------
//canvas
canvas_t::canvas_t()
{
	color_t c;
	height = 512;
	width = 512;
	bgd_color = c;
	for (int i = 0; i < 512; ++i)
	{
		for (int j = 0; j < 512; ++j)
		{
			pixels[i][j] = c;
		}
	}
}
canvas_t::canvas_t(drawing_t _current_drawing, int h, int w, color_t BGcolor, color_t **pixels_1)
{
	current_drawing = _current_drawing;
	height = h;
	width = w;
	bgd_color = BGcolor;
	for (int i = 0; i < 512; ++i)
	{
		for (int j = 0; j < 512; ++j)
		{
			pixels[i][j] = pixels_1[i][j];
		}
	}	
}
void canvas_t::clear_canvas()
{
	for (int i = 0; i < 512; ++i)
	{
		for (int j = 0; j < 512; ++j)
		{
			pixels[i][j] = bgd_color;	
		}
	}	
}
//--------------------------------