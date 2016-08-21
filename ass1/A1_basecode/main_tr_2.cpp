#include <cmath>
#include <cstdlib>
#include <iostream>
#include <GL/glut.h>
#include "mydraw_class.hpp"
using namespace std;

const unsigned int W = 100;
const unsigned int H = 100;
color_t green(0.0,1.0,0.0);
color_t red(1.0,0.0,0.0);
color_t blue(0.0,0.0,1.0);
color_t b_c(1.0,1.0,1.0);
color_t d_c(1.0,1.0,0.0);


void display()
{
	drawing_t my_drawing;
	color_t** buffer = new color_t*[H];
	for(int i = 0; i < H; ++i)
	{	
    	buffer[i] = new color_t[W];
	}
	canvas_t my_canvas(my_drawing, H, W, b_c, buffer);

	point_t a(50,50);
	point_t b(10,10);
	point_t c(10,50);
	point_t d(50,10);

	line_t ab(a,b);
	line_t cd(c,d);

	triangle_t abc(a,b,c, red);
	triangle_t bcd(b,c,d, blue);
	
	my_drawing.lines.push_back(ab);
	my_drawing.lines.push_back(cd);

	my_drawing.triangles.push_back(abc);
	my_drawing.triangles.push_back(bcd);

	int t = 2;	

	my_canvas.clear_canvas();
	my_canvas.update_canvas(d_c, my_drawing, t);

    glClearColor( 0, 0, 0, 1 );
    glClear( GL_COLOR_BUFFER_BIT );
	
	t=100;	
	GLubyte data[t][t][3];

    for( int b = 0; b <t; b++ )
    {
        for( int a = 0; a < t; a++ )
        {
            data[a][b][0] = (GLubyte) (int) (buffer[a][b].R() *255 );
            data[a][b][1] = (GLubyte) (int) (buffer[a][b].G() *255 );
            data[a][b][2] = (GLubyte) (int) (buffer[a][b].B() *255 );
        }
    }
	glDrawPixels( t, t, GL_RGB, GL_UNSIGNED_BYTE, data);
    
	glutSwapBuffers();
}

int main( int argc, char **argv )
{
	glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
    glutInitWindowSize( W, H );
    glutCreateWindow( "GLUT" );
    glutDisplayFunc( display );
    glutMainLoop();
    return 0;
}
