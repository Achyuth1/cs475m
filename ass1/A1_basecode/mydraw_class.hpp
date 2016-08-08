#ifndef _MYDRAW_CLASS_HPP_
#define _MYDRAW_CLASS_HPP_

//Define all classes like the color class, adding appropriate methods and data members. 
//Implementation of the methods go into the corresponding cpp file

//------------------------
//color_t class

class color_t {
private:
  float r,g,b;
public:
  color_t();
  color_t(const float _r, const float _g, const float _b);

  void set(const float _r, const float _g, const float _b);
  float R(void);
  float G(void);
  float B(void);
};
//------------------------
class pen_t
{
private:
	int size;
	bool mode;
	//Bckround color should be added?!
	color_t pen_color;
	color_t bgd_color;
public:
	pen_t();
	~pen_t();
	
};
//------------------------
class fill_t
{
private:
	color_t curr_color;
	// may be boundarycolorneed to be passed
public:
	fill_t();
	~fill_t();
	draw_fill();  // may OPENGL be with us//
	
};
//------------------------

//point_t class
class point_t {
private:
	int x,y;
public:
	point_t();
	~point_t();
	draw_point();
	};
//------------------------
class line_t
{
private:
	point_t Vi,Vf;
public:
	line_t();
	~line_t();
	draw_line();  //BRESSEN
	
};
//------------------------
class triangle_t
{
private:
	point_t A,B,C;
	color_t border_color;
	fill_t triangle_interior;
public:
	triangle_t();
	~triangle_t();
	draw_triangle();
	
};
//------------------------
class drawing_t
{
private:
	line_t *lines;
	triangle_t *triangles;
public:
drawing_t();
~drawing_t();
draw_drawing();
};
//------------------------
class canvas_t
{
private:
	drawing_t current_drawing;
	int height,width;
	color_t bgd_color;
	color_t *pixels;
public:
	canvas_t(int h, int w, color_t BGcolor);
	~canvas_t();
	clear_canvas();
	
};
//------------------------
#endif
