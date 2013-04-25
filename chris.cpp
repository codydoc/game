#include "chris.h"
#include <iostream>
#include <cstdlib>

Chris::Chris(QPixmap* pm,int nx, int ny):Thing(pm,nx,ny)
{
  x=nx;
  y=ny;
  //setPos(x,y);
}

void Chris::move()
{
   std::cout<< "MOVING! In Chris\n";
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
