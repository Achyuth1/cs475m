#include <iostream>
#include <GL/glut.h>
#include <vector>

#ifndef _HNODE_HPP_
#define _HNODE_HPP_

#define rod_a 1
#define rod_b 2
#define rod_c 3
#define rod_d 4
#define rod_e 10
#define rod_f 11
#define hnd_whl_f 5
#define hnd 6
#define grips 7
#define f_wheel_t 8
#define f_wheel_b 9
#define tyre 12
#define spoke 13
#define pedal_axis_cover 18
#define pedal_axis 14
#define pedal_rod 15
#define pedal 16
#define seat 17
#define wheel_addOn 19

void vertexcopy(float *src,float *dest);

// A simple class that represents a node in the hierarchy tree
class HNode {
private:
  float tx,ty,tz;
  float rx,ry,rz;
  int shape;

  std::vector<HNode*> children;
  HNode* parent;

public:
  HNode (HNode* parent, int node_shape);
  void add_child(HNode*);
  void render();
  void change_parameters(float tx,float ty,float tz,float rx,float ry,float rz);
  void render_tree();
  float get_rx();
  float get_ry();
  float get_rz();
  
  void inc_rx();
  void inc_ry();
  void inc_rz();
  void dec_rx();
  void dec_ry();
  void dec_rz();
};

#endif
