#include "chris.h"
#include <iostream>
#include <cstdlib>

/**Constructor*/
Chris::Chris(QPixmap* pm,int nx, int ny):Thing(pm,nx,ny)
{
  x=nx;
  y=ny;
  //setPos(x,y);
  //moveby
  name="Chris";
}

/**Move*/
void Chris::move()
{
   //std::cout<< "MOVING! In Chris\n";
   //moveBy(x,y);
   setPos(x,y);
}

/**Set XY*/
void Chris::setXY(int nx,int ny)
{
  x=nx;
  y=ny;
}

/**Get X*/
int Chris::getX()
{return x;}

/**Get Y*/
int Chris::getY()
{return y;}

/**Get Name*/
std::string Chris::getName()
{return name;}

