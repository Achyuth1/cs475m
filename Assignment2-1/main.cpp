#include <GL/glut.h>
#include <iostream>
#include <vector>
#include "HNode.hpp"

using namespace std;

HNode *node[100];

int curr=0; //Index of current oprational node

void create_cycle()
{

//===============FRAME==============================
  node[0] = new HNode(NULL,rod_a);  
  node[0]->change_parameters(0.0,0.0,0.0,0.0,0.0,0.0);

  node[1] = new HNode(node[0],rod_b);
  node[1]->change_parameters(0.0,0.0,0.0,74.5,0.0,0.0);

  node[2] = new HNode(node[0],rod_d);
  node[2]->change_parameters(0.0,0.0,5.0,73.5,0.0,0.0);

  node[5] = new HNode(node[0],rod_c);
  node[5]->change_parameters(0,-4.23,1.17,-40.0,0.0,0.0);  
//==================================================

//============HANDLE===================================  
  node[3] = new HNode(node[0],hnd_whl_f);
  node[3]->change_parameters(0.0,1.91,4.43,73.5,0.0,0.0);

  node[81] = new HNode(node[3], rod_f );
  node[81]->change_parameters(0,-0.07,-0.02,-90,0,0);  

  node[4] = new HNode(node[81],hnd);
  node[4]->change_parameters(-1.5,0,0.5,0,90.0,0);

  node[6] = new HNode(node[4],grips);
  node[6]->change_parameters(0,0,0,0,0,0); 

  node[7] = new HNode(node[4],grips);
  node[7]->change_parameters(0,0,2.3,0,0,0); 
//======================================================

//===================Front wheel Frame========================  
  node[8] = new HNode(node[3],f_wheel_t);
  node[8]->change_parameters(-0.5,0,3.2,0,90,0); 

  node[9] = new HNode(node[3],f_wheel_b);
  node[9]->change_parameters(0.5,0,3.2,0,0,0); 

  node[10] = new HNode(node[3],f_wheel_b);
  node[10]->change_parameters(-0.5,0,3.2,0,0,0); 
//======================================================

//===============Back wheel Frame======================
  node[11] = new HNode(node[0], rod_e );
  node[11]->change_parameters(0,0,0,124,0,0);

  node[12] = new HNode(node[11],f_wheel_t);
  node[12]->change_parameters(-0.5,0,1,0,90,0);

  node[13] = new HNode(node[11], f_wheel_b);
  node[13]->change_parameters(0.5,0,1,0,0,0);

  node[14] = new HNode(node[11], f_wheel_b);
  node[14]->change_parameters(-0.5,0,1,0,0,0);

  node[15] = new HNode(node[5], rod_f );
  node[15]->change_parameters(0,0,0,-124,0,0);

  node[16] = new HNode(node[15],f_wheel_t);
  node[16]->change_parameters(-0.5,0,0.5,0,90,0);

  node[17] = new HNode(node[15], f_wheel_b);
  node[17]->change_parameters(0.5,0,0.5,0,0,0);

  node[18] = new HNode(node[15], f_wheel_b);
  node[18]->change_parameters(-0.5,0,0.5,0,0,0);
//========================================================


//================Pedalling Division================== 
  node[73] = new HNode(node[0], pedal_axis); //PEDAL AXIS
  node[73]->change_parameters(-0.7,-4.23,1.17,0,90,0);

  node[74] = new HNode(node[73], pedal_rod);//pedal_rod
  node[74]->change_parameters(0,0,0,-90,0,0);

  node[75] = new HNode(node[73], pedal_rod);//pedal_rod
  node[75]->change_parameters(0,0,1.4,90,0,0);

  node[77] = new HNode(node[74], pedal); //Pedal
  node[77]->change_parameters(0,0.35,1.5,0,0,0);

  node[78] = new HNode(node[75], pedal); //Pedal
  node[78]->change_parameters(0,0.35,1.5,0,0,0);

  node[80] = new HNode(node[0], pedal_axis_cover); //PEDAL AXIS COVER 
  node[80]->change_parameters(-0.5,-4.23,1.17,0,90,0);
//=====================================================


//==================tyre assembly front and back=========
  node[21] = new HNode(node[0], f_wheel_t);// BACK wheel axis
  node[21]->change_parameters(-0.5,-3.3,-2.2,0,90,0);

  node[22] = new HNode(node[8], f_wheel_t);// FRONT wheel axis
  node[22]->change_parameters(-3,0,0,0,0,0);   

  node[19] = new HNode(node[22], tyre );//front_tyre
  node[19]->change_parameters(0,0,0.5,0,0,0);

  node[20] = new HNode(node[21], tyre );//back_tyre
  node[20]->change_parameters(0,0,0.5,0,0,0);  

  node[82] = new HNode(node[20], wheel_addOn );//back_tyre_addon
  node[82]->change_parameters(0,0,0.0,0,0,0);    

  node[83] = new HNode(node[19], wheel_addOn );//front_tyre_addon
  node[83]->change_parameters(0,0,0.0,0,0,0);

  node[23] = new HNode(node[19], spoke );//front wheel spokes
  node[23]->change_parameters(0,0,0,90,0,0); 

  for (int i = 0; i < 19; ++i)
   {
      node[24+i] = new HNode(node[23], spoke );
      node[24+i]->change_parameters(0,0,0,0,18.0*i+18.0,0);  
   }

  node[53] = new HNode(node[20], spoke );//back wheel spokes
  node[53]->change_parameters(0,0,0,90,0,0);

  for (int i = 0; i < 19; ++i)
    {
      node[54+i] = new HNode(node[53], spoke );
      node[54+i]->change_parameters(0,0,0,0,18.0*i+18.0,0);
    }

//========================SEAT===================================
  node[76] = new HNode(node[0], rod_f); // elevation for seat
  node[76]->change_parameters(0,0,0,-90,0,0);

  node[79] = new HNode(node[76], seat);//seat
  node[79]->change_parameters(0,0,0.4,0,0,-90);

//===============================================================  

}


//Our function for processing ASCII keys
void processNormalKeys(unsigned char key, int x, int y) {
  if (key == 27)
    exit(0);
  else if(key == '1')
  {
    curr = 73;
  }
  else if(key == '2')
  {
    curr = 3;
  }
  else if(key == '0')
  {
    curr = 0;
  }
}

//Our function for processing Non-ASCII keys
void processSpecialKeys(int key, int x, int y) {
  switch(key) {
    case GLUT_KEY_LEFT :
      if(curr!= 3 && curr != 73)
      {
        node[curr]->dec_ry();  
      }
      else if(((curr ==3 && ( node[curr]->get_rz()!=270 || node[curr]->get_rz() == 0) )) && curr != 73) 
      {
        node[curr]->dec_rz();
      }
      break;
    
    case GLUT_KEY_RIGHT :
      if(curr != 3 && curr != 73)
      {
        node[curr]->inc_ry();  
      }
      else if (((curr ==3 && node[curr]->get_rz()!= 90.0)) && curr !=73)
      {
        node[curr]->inc_rz();
      }
      break;
    
    case GLUT_KEY_DOWN :
      if(curr != 3)
      {
        node[curr]->dec_rx();
        if(curr == 73)
        {
          node[77]->dec_ry();//pedal_Hinge model
          node[78]->inc_ry();//pedal_hinge_model
        }
      }
      break;
    
    case GLUT_KEY_UP :
      if(curr != 3)
      {  
        node[curr]->inc_rx();
        if(curr == 73)
        {
          node[77]->inc_ry();//pedal_hinge_model
          node[78]->dec_ry();//pedal_hinge_model
          node[21]->inc_rx();
          node[21]->inc_rx();
          node[22]->inc_rz();
          node[22]->inc_rz(); 
        }
      }
      break;
    
    case GLUT_KEY_PAGE_UP : 
      if(curr != 3  && curr != 73 )
      {
        node[curr]->dec_rz();
      }
      break;
    
    case GLUT_KEY_PAGE_DOWN :
      if (curr !=3 && curr !=73)
      {
        node[curr]->inc_rz();
      }
      break;
  }
  //Redraw
  glutPostRedisplay();
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(1.0f,1.0f,1.0f,1.0f);
  node[0]->render_tree();
  glutSwapBuffers();
}

void init(void)
{
  // Use depth buffering for hidden surface elimination.
  glEnable(GL_DEPTH_TEST);
  // Setup the view of the cube.
  glMatrixMode(GL_PROJECTION);
  //gluPerspective(field of view in degree, aspect ratio, Z near, Z far);
  gluPerspective(80.0, 1.0, 1.0, 30.0);

  glMatrixMode(GL_MODELVIEW);
  gluLookAt(0.0, 0.0, 14.0,  // eye is at (0,0,8)
  0.0, 0.0, 0.0,      // center is at (0,0,0)
  0.0, 1.0, 0.0);      // up is in positive Y direction
}

int main(int argc, char **argv)
{

  create_cycle();

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(900,900);
  glutCreateWindow("Hierarchical Modeling");
  glutDisplayFunc(display);
  glutKeyboardFunc(processNormalKeys);
  glutSpecialFunc(processSpecialKeys);
  init();
  glutMainLoop();
  return 0;
}
