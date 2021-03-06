#include "mydraw_class.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>
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
//float
float color_t::R(void) { return r; }
float color_t::G(void) { return g; }
float color_t::B(void) { return b; }


//---------------------
//pen_t methods

pen_t::pen_t()
{
	thickness = 1;
	mode = true;
}

pen_t::pen_t(const int _size, const bool _mode, color_t pen_c, color_t bg_c)
{
	thickness = _size;
	mode = _mode;
	bgd_color = bg_c;
	pen_color = pen_c;
}  

void pen_t::set(const int _size, const bool _mode, color_t pen_c, color_t bg_c)
{
	thickness = _size;
	mode = _mode;
	bgd_color = bg_c;
	pen_color = pen_c;
	return;
}
color_t pen_t::get_b_c()
{
	return bgd_color;
}
color_t pen_t::get_p_c()
{
	return pen_color;
}
bool pen_t::get_mode()
{
	return mode;
}
int pen_t::get_thickness()
{
	return thickness;
}
void pen_t::set_mode(bool _mode)
{
	mode = _mode;
}
void pen_t::set_b_c(color_t _bgd_color)
{
	bgd_color = _bgd_color;
}
void pen_t::set_p_c(color_t _pen_color)
{
	pen_color = _pen_color;
}
void pen_t::set_thickness(int _thickness)
{
	thickness - _thickness;
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

void fill_t::set_fill_color(color_t _curr_color)
{
	curr_color = _curr_color;
}


void floodFill(int x,int y, color_t oldColor, color_t newColor,color_t **buffer) 
{
	color_t color = buffer[y][x];

	if(color.R() == oldColor.R() && color.G() == oldColor.G() && color.B() == oldColor.B())
	{
		buffer[y][x] = newColor;
		floodFill(x+1, y, oldColor, newColor,buffer);
		floodFill(x, y+1, oldColor, newColor,buffer);
		floodFill(x-1, y, oldColor, newColor,buffer);
		floodFill(x, y-1, oldColor, newColor,buffer);
	}
	return;
}

void fill_t::draw_fill(color_t **buffer)
{
	int x = internal_point.get_x();
	int y = internal_point.get_y();
	color_t oldColor = this->get_bg();
	color_t newColor = this->get_curr();
	floodFill(x,y,oldColor,newColor,buffer);
}

//-----------------------------------------
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
	
	for (int i = 0; i < t; ++i)
	{
		for (int j = 0; j < t; ++j)
		{
			buffer[i+y][j+x] = c;
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
	thickness = 1;
}
line_t::line_t(point_t _Vi, point_t _Vf,int _thickness,color_t _color_line)
{
	Vi = _Vi;
	Vf = _Vf;
	thickness = _thickness;
	color_line = _color_line;

}
void line_t::set_line(point_t _Vi, point_t _Vf,int _thickness,color_t _color_line)
{
	Vi = _Vi;
	Vf = _Vf;
	thickness = _thickness;
	color_line = _color_line;

}
void line_t::draw_line(color_t **buffer)
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
      	temp_pt.draw_point(color_line, thickness, buffer);
        //buffer[y][x] = c;
      }
      else            //  change the color of pixel (x,y) with color c
      {
      	temp_pt.set_point(x,y);
      	temp_pt.draw_point(color_line, thickness, buffer);
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
	thickness = 1;
}
triangle_t::triangle_t(point_t _A, point_t _B, point_t _C, color_t _border_color, color_t _fill_color, int _thickness, bool flag)
{
	A = _A;
	B = _B;
	C = _C;
	border_color = _border_color;
	thickness = _thickness;
	triangle_interior.set_fill_color(_fill_color);
	fill_or_no = flag;
}
void triangle_t::set_triangle(point_t _A, point_t _B, point_t _C,color_t _border_color,color_t _fill_color, int _thickness, bool flag)
{ 
	A = _A;
	B = _B;
	C = _C;
	border_color = _border_color;
	thickness = _thickness;
	triangle_interior.set_fill_color(_fill_color);
	fill_or_no = flag;
}	
void triangle_t::set_fill_flag(bool flag)
{
	fill_or_no = flag;
}
void triangle_t::set_internal_point_triangle()
{
	// finding the centroid and setting it as the internal point
	point_t centroid;
	int sum_x = A.get_x() + B.get_x() + C.get_x();
	int sum_y = A.get_y() + B.get_y() + C.get_y();
	centroid.set_point(sum_x/3,sum_y/3);
	triangle_interior.set_internal(centroid);
}
point_t triangle_t::get_1(void)
{
	return A;
}
point_t triangle_t::get_2(void)
{
	return B;
}
point_t triangle_t::get_3(void)
{
	return C;
}


void triangle_t::draw_triangle(color_t **buffer)
{

	line_t AB(A,B,thickness,border_color);
	AB.draw_line(buffer);
	
	line_t BC(B,C,thickness,border_color);
	BC.draw_line(buffer);

	line_t CA(C,A,thickness,border_color);
	CA.draw_line(buffer);	

	if(fill_or_no)
	{
	//Setting the fill parameters into the triangle
	set_internal_point_triangle();	
	//Calling the floodfill function
	triangle_interior.draw_fill(buffer);
	}
}
//--------------------------------
//drawing_t
void drawing_t::change_background(color_t _bgd_color)
{
	for (int i = 0; i < triangles.size(); ++i)
	{
		triangles[i].triangle_interior.set_bg(_bgd_color);
	}	
}
void drawing_t::draw_drawing(color_t **buffer)
{
	for (int i = 0; i < lines.size(); ++i)
	{
		lines[i].draw_line(buffer);
	}
	for (int i = 0; i < triangles.size(); ++i)
	{
		triangles[i].draw_triangle(buffer);
	}
}

void drawing_t::save(color_t **buffer,int H,int W)
{
	ofstream myfile;

	myfile.open("drawinglines.txt");
	point_t writepoint;
	color_t writecolor;
	int i,j;
	for (i = 0; i < lines.size(); ++i)
	{
		writepoint = lines[i].get_start();
		myfile<<writepoint.get_x()<<" "<<writepoint.get_y()<<"\n";
		writepoint = lines[i].get_end();
		myfile<<writepoint.get_x()<<" "<<writepoint.get_y()<<"\n";
		myfile<<lines[i].get_thickness()<<"\n";
		writecolor = lines[i].get_line_color();
		myfile<<writecolor.R()<<" "<<writecolor.G()<<" "<<writecolor.B()<<"\n";

	}
	myfile.close();

	myfile.open("drawingtriangles.txt");
	
	for (i = 0; i < triangles.size(); ++i)
	{
		writepoint = triangles[i].get_1();
		myfile<<writepoint.get_x()<<" "<<writepoint.get_y()<<"\n";		
		writepoint = triangles[i].get_2();
		myfile<<writepoint.get_x()<<" "<<writepoint.get_y()<<"\n";
		writepoint = triangles[i].get_3();
		myfile<<writepoint.get_x()<<" "<<writepoint.get_y()<<"\n";		
		
		myfile<<triangles[i].get_thickness()<<"\n";
		myfile<<triangles[i].get_fill_or_no()<<"\n";

		writecolor = triangles[i].get_border_color();
		myfile<<writecolor.R()<<" "<<writecolor.G()<<" "<<writecolor.B()<<"\n";
		writecolor = triangles[i].triangle_interior.get_curr();
		myfile<<writecolor.R()<<" "<<writecolor.G()<<" "<<writecolor.B()<<"\n";

		//no need of internal point and the background color
	}

	myfile.close();
	// Add the buffer

	myfile.open("pixel_r.txt");
	for (i = 0; i < H; ++i)
	{	
		for (j = 0; j < W; ++j)
		{
			myfile<<buffer[i][j].R()<<"\n";
		}
	}
	myfile.close();

	myfile.open("pixel_g.txt");
	for ( i = 0; i < H; ++i)
	{	
		for ( j = 0; j < W; ++j)
		{
			myfile<<buffer[i][j].G()<<"\n";
		}
	}
	myfile.close();

	myfile.open("pixel_b.txt");
	for ( i = 0; i < H; ++i)
	{	
		for (j = 0; j < W; ++j)
		{
			myfile<<buffer[i][j].B()<<"\n";
		}
	}
	myfile.close();	

}


void drawing_t::load(color_t **buffer,int H, int W)
{
	//Pop the line vector
	lines.clear();
	//Pop the triangle vector
	triangles.clear();

	ifstream myfile;
	myfile.open("drawinglines.txt");
	
	int a[5],_thickness;
	float b[3];
	point_t _Vi,_Vf;
	color_t _color_line;
	line_t readline;
	while (myfile>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>b[0]>>b[1]>>b[2])
    {
    	_Vi.set_point(a[0],a[1]);
    	_Vf.set_point(a[2],a[3]);
    	_thickness = a[4];
    	_color_line.set(b[0],b[1],b[2]);
    	readline.set_line(_Vi,_Vf,_thickness,_color_line);
    	lines.push_back(readline);
    }

    myfile.close();

	myfile.open("drawingtriangles.txt");
	
	int c[7];
	float d[6];
	bool flag;
	point_t _A,_B,_C;
	triangle_t readtriangle;
	color_t _border_color,_fill_color;
	while (myfile>>c[0]>>c[1]>>c[2]>>c[3]>>c[4]>>c[5]>>c[6]>>flag>>d[0]>>d[1]>>d[2]>>d[3]>>d[4]>>d[5])
    {
    	_A.set_point(c[0],c[1]);
    	_B.set_point(c[2],c[3]);
    	_C.set_point(c[4],c[5]);
    	_thickness = c[6];
    	_border_color.set(d[0],d[1],d[2]);
    	_fill_color.set(d[3],d[4],d[5]);
    	readtriangle.set_triangle(_A,_B,_C,_border_color,_fill_color,_thickness,flag);
    	triangles.push_back(readtriangle);
    }

    myfile.close();

    ifstream myfile_r,myfile_g,myfile_b;
    myfile_r.open("pixel_r.txt");
    myfile_g.open("pixel_b.txt");
    myfile_b.open("pixel_b.txt");
    float re,gr,bl;
    color_t writebuffer;
	
	int i,j;
	for ( i = 0; i < H; ++i)
	{	
		for (j = 0; j < W; ++j)
		{
			myfile_r>>re;
			myfile_g>>gr;
			myfile_b>>bl;
			writebuffer.set(re,gr,bl);
			buffer[i][j] = writebuffer;
		}
	}  
}


//----------------------------------------------------
// canvas_t
canvas_t::canvas_t()
{

}
canvas_t::canvas_t(drawing_t _current_drawing, int _height, int _width, color_t _bgd_color, color_t **buffer)
{
	current_drawing = _current_drawing;
	height = _height;
	width = _width;
	bgd_color = _bgd_color;
	pixels = buffer;
}
void canvas_t::clear_canvas()
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			pixels[i][j] = bgd_color;	
		}
	}	
}
color_t** canvas_t::get_buffer()
{
	return pixels;
}
void canvas_t::draw_current_drawing()
{
	current_drawing.draw_drawing(pixels);
}

void canvas_t::add_triangle_to_drawing(triangle_t triangle) 
{ 
	current_drawing.triangles.push_back(triangle);
}

void canvas_t::add_line_to_drawing(line_t line)
{ 
	current_drawing.lines.push_back(line);
}

triangle_t canvas_t::pop_triangle_from_drawing(void)
{ 
	triangle_t temp;
	if (current_drawing.triangles.size()!=0)
	{
		temp = current_drawing.triangles.back(); 
		current_drawing.triangles.pop_back();	
	}
	return temp;
}

line_t canvas_t::pop_line_from_drawing(void)
{
	line_t temp;
	if (current_drawing.lines.size()!=0)
	{
		temp = current_drawing.lines.back();
		current_drawing.lines.pop_back();	
	}
	return temp;
}

void canvas_t::set_canvas(drawing_t _current_drawing, int _height, int _width, color_t _bgd_color, color_t **buffer)
{
	current_drawing = _current_drawing;
	height = _height;
	width = _width;
	bgd_color = _bgd_color;
	pixels = buffer;
}
void canvas_t::set_bgd_color(color_t _bgd_color)
{
	//Changing the buffer 
	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
			if (pixels[i][j].R() == bgd_color.R() && pixels[i][j].G() == bgd_color.G() && pixels[i][j].B() == bgd_color.B())
				pixels[i][j] = _bgd_color;

	//Changing the variable
	bgd_color = _bgd_color;

	current_drawing.change_background(_bgd_color);
}
void canvas_t::change_fill_color(color_t _fill_color, bool flag)
{
	int s = current_drawing.triangles.size();
	if(s != 0)
	{
		current_drawing.triangles[s-1].triangle_interior.set_fill_color(_fill_color);
		current_drawing.triangles[s-1].set_fill_flag(flag);
	}
}
void canvas_t::clear_lines()
{
	current_drawing.lines.clear();
}
void canvas_t::clear_triangles()
{
	current_drawing.lines.clear();
}
void canvas_t::save(int H,int W)
{
	current_drawing.save(pixels,H,W);
}

void canvas_t::load(int H,int W)
{
	current_drawing.load(pixels,H,W);
}
//--------------------------------