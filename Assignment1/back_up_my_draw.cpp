#ifndef _MYDRAW_CLASS_HPP_
#define _MYDRAW_CLASS_HPP_


#include "mydraw_class.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
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
	void set(const int _size, const bool _mode, color_t pen_c, color_t bg_c);
	
};
//------------------------
//point_t class
class point_t {
private:
	int x,y;
public:
	point_t();
	point_t(int _x, int _y);
	int get_x();
	int get_y();
	void set_point(int _x, int _y);
	void draw_point(color_t c, int t, color_t **buffer);
	};
//------------------------
class line_t
{
private:
	point_t Vi,Vf;
public:
	line_t();
	line_t(point_t _Vi, point_t _Vf);
	void set_line(point_t _Vi, point_t _Vf);
	point_t get_start()
	{
		return Vi;
	}
	point_t get_end()
	{
		return Vf;
	}	
	void draw_line(color_t c, int t, color_t **buffer);  //BRESSEN
	
};
//-----------------------
//fill_t
class fill_t
{
private:
	point_t internal_point;
	color_t curr_color;
	color_t bnd_color;
	
public:
	fill_t();
	fill_t(color_t _curr_color, color_t _bnd_color);
	void set_internal(point_t _internal)
	{	internal_point = _internal; }
	color_t get_bg()
	{	return bnd_color; }
	color_t get_curr()
	{	return curr_color; }
	void set_bg(color_t _bnd_color);
	void set_curr(color_t _curr_color);
	void draw_fill(color_t **buffer);  // may OPENGL be with us//
	
}
;//------------------------
class triangle_t
{
private:
	point_t A,B,C;
	color_t border_color;
	fill_t triangle_interior;
public:
	triangle_t();
	triangle_t(point_t _A, point_t _B, point_t _C, color_t _border_color);
	void set_internal_point_triangle(fill_t _triangle_interior);
	void set_triangle(point_t _A, point_t _B, point_t _C,color_t _border_color);
	void draw_triangle(int t, color_t **buffer);
};
//------------------------
class drawing_t
{
public:
	vector<line_t> lines;
	vector<triangle_t> triangles;
void draw_drawing(color_t c, int t, color_t **buffer);
};
//------------------------
class canvas_t
{
private:
	drawing_t current_drawing;
	int height,width;
	color_t bgd_color;
	color_t **pixels;
public:
	void set_canvas(drawing_t _current_drawing, int _height, int _width, color_t _bgd_color, color_t **buffer);
	void update_canvas(color_t c, drawing_t _current_drawing, int t);
	color_t** get_buffer();
	void clear_canvas();
};
//------------------------
#endif
