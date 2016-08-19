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
	float size;
	bool mode;
	//Bckround color should be added?!
	color_t pen_color;
	color_t bgd_color;
public:
	pen_t();
	pen_t(const int _size, const bool _mode, color_t pen_c, color_t bg_c);
	set(const int _size, const bool _mode, color_t pen_c, color_t bg_c);
	
};
//------------------------
class fill_t
{
private:
	color_t curr_color;
	color_t bnd_color;
	// may be boundarycolorneed to be passed
public:
	fill_t();
	fill_t(color_t _curr_color, color_t _bnd_color);
	set_bg(color_t _bnd_color);
	set_curr(color_t _curr_color);
	draw_fill();  // may OPENGL be with us//
	
};
//------------------------

//point_t class
class point_t {
private:
	int x,y;
public:
	point_t();
	point_t(int _x, int _y);
	set_point(int _x, int _y);
	draw_point();
	};
//------------------------
class line_t
{
private:
	point_t Vi,Vf;
public:
	line_t();
	line_t(point_t _Vi, point_t _Vf);
	set_line(point_t _Vi, point_t _Vf);
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
	triangle_t(point_t _A, point_t _B, point_t _C);
	set_triangle(point_t _A, point_t _B, point_t _C);
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
	canvas_t();
	canvas_t(int h, int w, color_t BGcolor);
	~canvas_t();
	clear_canvas();
};
//------------------------
#endif
