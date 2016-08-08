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
public:
	pen_t();
	~pen_t();
	
};
//------------------------
class fill_t
{
public:
	fill_t();
	~fill_t();
	
};
//------------------------

//point_t class
class point_t {
public:
	point_t();
	~point_t();
	};
//------------------------
class line_t
{
public:
	line_t();
	~line_t();
	
};
//------------------------
class traingle_t
{
public:
	traingle_t();
	~traingle_t();
	
};
//------------------------
class drawing_t
{
public:
drawing_t();
~drawing_t();

};
//------------------------
class canvas_t
{
public:
	canvas_t();
	~canvas_t();
	
};
//------------------------
#endif
