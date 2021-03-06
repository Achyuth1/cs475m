#include <cmath>
#include <cstdlib>
#include <iostream>
#include <GL/glut.h>
#include "mydraw_class.hpp"
using namespace std;

const unsigned int W = 100;
const unsigned int H = 100;
color_t** buffer = new color_t*[H];
	for(int i = 0; i < H; ++i)
	{	
    	buffer[i] = new color_t[W];
	}
void display()
{
    glClearColor( 0, 0, 0, 1 );
    glClear( GL_COLOR_BUFFER_BIT );
	
	unsigned int t=100;	
	GLubyte data[t][t][3];

	cout <<"check" <<endl;
	cout<< buffer[10][11].G() << endl;
    for( int b = 0; b <t; b++ )
    {
        for( int a = 0; a < t; a++ )
        {
            data[a][b][0] = (GLubyte) (int) (buffer[a][b].R() *255 );
            data[a][b][1] = (GLubyte) (int) (buffer[a][b].G() *255 );
            data[a][b][2] = (GLubyte) (int) (buffer[a][b].B() *255 );
            //cout<< buffer[a][b].R() << "::"<< buffer[a][b].G() << "::"<< buffer[a][b].B() << endl;
        }
    }
	glDrawPixels( t, t, GL_RGB, GL_UNSIGNED_BYTE, data);
    
	glutSwapBuffers();
}

int main( int argc, char **argv )
{
	point_t a(10,10);
	point_t b(18,18);
	line_t ab(a,b);
	color_t d_c(0.0,1.0,0.0);
	color_t b_c(1.0,1.0,1.0);

	//color_t temp_c(0.0,0.0,0.0);
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			buffer[i][j] = b_c;
		}
	}
	
	int t = 5;
	//ab.draw_line(d_c, t, buffer);
	a.draw_point(d_c, t, buffer);
	//cout << buffer[10][11].R()<<"::"<< buffer[10][11].G()<<"::"<<buffer[10][11].B() <<endl;
   
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
    glutInitWindowSize( W, H );
    glutCreateWindow( "GLUT" );
    glutDisplayFunc( display );
    glutMainLoop();
    return 0;
}
