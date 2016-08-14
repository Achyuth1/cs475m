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

fill_t::
//---------------------