#include "mydraw_class.hpp"

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

pen_t::set(const int _size, const bool _mode, color_t pen_c, color_t bg_c)
{
	size = _size;
	mode = _mode;
	bgd_color = bg_c;
	pen_color = pen_c;
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

fill_t::set_bg(color_t _bnd_color)
{
	bnd_color = _bnd_color;
}

fill_t::set_curr(color_t _curr_color){
	curr_color = _curr_color;
}

fillt_t::draw_fill()
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
point_t::set_point(int _x, int _y)
{
	x = _x;
	y = _y;	
}
point_t::draw_point()
{
	//to be filled
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
line_t::set_line(point_t _Vi, point_t _Vf)
{
	Vi = _Vi;
	Vf = _Vf;
}
line_t::draw_line() //BRESSEN
{
	//to be filled
}
//--------------------------------
//traingle_t
traingle_t::triangle_t()
{
	point_t c;
	A = c;
	B = c;
	C = c;
}
traingle_t::triangle_t(point_t _A, point_t _B, point_t _C)
{
	A = _A;
	B = _B;
	C = _B;
}
traingle_t::set_triangle(point_t _A, point_t _B, point_t _C)
{
	A = _A;
	B = _B;
	C = _B;
}	
traingle_t::draw_triangle();
//--------------------------------
