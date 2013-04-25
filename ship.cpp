#include "ship.h"
#include <iostream>
#include <cstdlib>

Ship::Ship(QPixmap* pm,int nx, int ny):Thing(pm,nx,ny)
{
  x=nx;
  y=ny;
  //setPos(x,y);
}

void Ship::move()
{
   //std::cout<< "MOVING! In Comet\n";
   setPos(x,y);
}

void Ship::setXY(int nx,int ny)
{
  x=nx;
  y=ny;
}

int Ship::getX()
{return x;}

int Ship::getY()
{return y;}
