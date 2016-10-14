#include "HNode.hpp"

HNode::HNode(HNode* par, int node_shape)
{
  if(par!=NULL)
  {
    parent=par;
    parent->add_child(this);
  }
  shape = node_shape;
  tx=ty=tz=rx=ry=rz=0;
}


void HNode::add_child(HNode *child)
{
  children.push_back(child);
}

float HNode::get_rx()
{
  return rx;
}
float HNode::get_ry()
{
  return ry;
}
float HNode::get_rz()
{
  return rz;
}


void HNode::render()
{
  //Translate the origin
  glTranslatef(tx,ty,tz);
  //Rotate at translated origin
  glRotatef(rx, 1.0, 0.0, 0.0);
  glRotatef(ry, 0.0, 1.0, 0.0);
  glRotatef(rz, 0.0, 0.0, 1.0);
  if(shape == 1) //rod_a
  {
  //Render the node
  glColor3f(0.0f,0.0f,0.0f);
  GLUquadricObj *quadratic;
  quadratic = gluNewQuadric();
  gluCylinder(quadratic,0.2f,0.2f,5.0f,32,32);
  }
  else if(shape == 2) //rod_b
  {
  glColor3f(0.0f,0.0f,0.0f);    
  GLUquadricObj *quadratic;
  quadratic = gluNewQuadric();
  gluCylinder(quadratic,0.2,0.2,4.39f,32,32);    
  }
  else if(shape == 3)//rod_c
  {
  glColor3f(0.0f,0.0f,0.0f);    
  GLUquadricObj *quadratic;
  quadratic = gluNewQuadric();
  gluCylinder(quadratic,0.2,0.2,5.15f,32,32);    
  }
  else if(shape == 4)//rod_d
  {
  glColor3f(0.0f,0.0f,0.0f);    
  GLUquadricObj *quadratic;
  quadratic = gluNewQuadric();
  gluCylinder(quadratic,0.15,0.15,1.0,32,32);    
  }
  else if(shape == 5)//hnd_whl_f
  {
  glColor3f(0.2f,0.2f,0.2f);  
  GLUquadricObj *quadratic;
  quadratic = gluNewQuadric();
  gluCylinder(quadratic,0.14,0.14,3.2,32,32);    
  }
  else if(shape == 6)//handle
  {
  glColor3f(0.0f,0.0f,0.0f);  
  GLUquadricObj *quadratic;
  quadratic = gluNewQuadric();
  gluCylinder(quadratic,0.1,0.1,3.0,32,32);    
  }
  else if(shape == 7)//gripsx
  {
  glColor3f(1.0f,0.0f,0.0f);  
  GLUquadricObj *quadratic;
  quadratic = gluNewQuadric();
  gluCylinder(quadratic,0.11,0.11,0.7,32,32);    
  }
  else if(shape == 8)//f_wheel_t
  {
  glColor3f(0.2f,0.2f,0.2f);    
  GLUquadricObj *quadratic;
  quadratic = gluNewQuadric();
  gluCylinder(quadratic,0.09,0.09,1,32,32);    
  }
  else if(shape == 9)//f_wheel_b
  {
  glColor3f(0.2f,0.2f,0.2f);   
  GLUquadricObj *quadratic;
  quadratic = gluNewQuadric();
  gluCylinder(quadratic,0.1,0.05,3,32,32);    
  }  
  else if(shape == 10) //rod_e
  {
  glColor3f(0.0f,0.0f,0.0f);  
  GLUquadricObj *quadratic;
  quadratic = gluNewQuadric();
  gluCylinder(quadratic,0.1,0.1,1,32,32);    
  }  
  else if(shape == 11) //rod_f
  {
  glColor3f(0.0f,0.0f,0.0f);  
  GLUquadricObj *quadratic;
  quadratic = gluNewQuadric();
  gluCylinder(quadratic,0.1,0.1,0.5,32,32);    
  }  
  else if(shape == 12) //tyre
  {
    glColor3f(0.0f,0.0f,0.0f); 
    glutSolidTorus(0.3, 2, 10, 50);    
  }  
  else if(shape == 13) //spoke
  {
    glColor3f(0.7f,0.0f,0.0f); 
  GLUquadricObj *quadratic;
  quadratic = gluNewQuadric();
  gluCylinder(quadratic,0.03,0.03,2,32,32);    
  }
  else if(shape == 14) //pedal_axis
  {
  glColor3f(0.0f,0.0f,0.0f);   
  GLUquadricObj *quadratic;
  quadratic = gluNewQuadric();
  gluCylinder(quadratic,0.1,0.1,1.4,32,32);    
  }
  else if(shape == 15) //pedal_rod
  {
  glColor3f(0.0f,0.0f,0.0f);   
  GLUquadricObj *quadratic;
  quadratic = gluNewQuadric();
  gluCylinder(quadratic,0.1,0.05,1.5,32,32);  
  }
  else if(shape == 16) //pedal
  {
  glPushMatrix();  
  glColor3f(0.9f,0.0f,0.1f);  
  glScalef(0.7,1,0.2);  
  glutSolidCube(0.75);
  glPopMatrix();  
  }
  else if(shape == 17) //seat
  { 
  glColor3f(1.0f,0.0f,0.0f);  
   
  glBegin(GL_QUADS);
    glVertex3f(-1,1,0);
    glVertex3f(-1,-1,0);
    glVertex3f(1,-0.25,0);
    glVertex3f(1,0.25,0);
  glEnd();
  glBegin(GL_QUADS);
    glVertex3f(-1,1,0.25);
    glVertex3f(-1,-1,0.25);
    glVertex3f(1,-0.25,0.25);
    glVertex3f(1,0.25,0.25);
  glEnd();
  glColor3f(0.0f,0.0f,0.0f); 
  glBegin(GL_QUADS);
    glVertex3f(-1,1,0);
    glVertex3f(-1,1,0.25);
    glVertex3f(1,0.25,0.25);
    glVertex3f(1,0.25,0);
  glEnd();
  glBegin(GL_QUADS);
    glVertex3f(1,0.25,0);
    glVertex3f(1,0.25,0.25);
    glVertex3f(1,-0.25,0.25);
    glVertex3f(1,-0.25,0);
  glEnd();
  glBegin(GL_QUADS);
    glVertex3f(1,-0.25,0);
    glVertex3f(1,-0.25,0.25);
    glVertex3f(-1,-1,0.25);
    glVertex3f(-1,-1,0);
  glEnd();
  glBegin(GL_QUADS);
    glVertex3f(-1,1,0);
    glVertex3f(-1,-1,0);
    glVertex3f(-1,-1,0.25);
    glVertex3f(-1,1,0.25);
  glEnd();
  }
  else if(shape == 18) //pedal_axis_cover
  {
  glColor3f(0.4f,0.4f,0.4f);   
  GLUquadricObj *quadratic;
  quadratic = gluNewQuadric();
  gluCylinder(quadratic,0.11,0.11,1.0,32,32);    
  }
  else if(shape == 19) //wheel_add_on
  {
    glColor3f(1.0f,0.0f,0.0f); 
    glutSolidTorus(0.2, 2.2, 10, 50);    
  }  
}

void HNode::change_parameters(float tx,float ty,float tz,float rx,float ry,float rz){
  this->tx=tx;
  this->ty=ty;
  this->tz=tz;
  this->rx=rx;
  this->ry=ry;
  this->rz=rz;
}

void HNode::render_tree(){
  glPushMatrix();
  render();
  for(int i=0;i<children.size();i++){
    children[i]->render_tree();
  }
  glPopMatrix();
}


void HNode::inc_rx(){
  rx+= 1;
  if(rx>360)
  rx-=360;
}
void HNode::inc_ry(){
  ry+= 1;
  if(ry>360)
  ry-=360;
}
void HNode::inc_rz(){
  rz+= 1;
  if(rz>360)
  rz-=360;
}
void HNode::dec_rx(){
  rx-= 1;
  if(rx<0)
  rx+=360;
}
void HNode::dec_ry(){
  ry-= 1;
  if(ry<0)
  ry+=360;
}
void HNode::dec_rz(){
  rz-= 1;
  if(rz<0)
  rz+=360;
}
