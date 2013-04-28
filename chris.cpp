#include "chris.h"
#include <iostream>
#include <cstdlib>

Chris::Chris(QPixmap* pm,int nx, int ny):Thing(pm,nx,ny)
{
  x=nx;
  y=ny;
  //setPos(x,y);
  //moveby
  name="Chris";
}

void Chris::move()
{
   //std::cout<< "MOVING! In Chris\n";
   //moveBy(x,y);
   setPos(x,y);
}

void Chris::setXY(int nx,int ny)
{
  x=nx;
  y=ny;
}

int Chris::getX()
{return x;}

int Chris::getY()
{return y;}

std::string Chris::getName()
{return name;}

