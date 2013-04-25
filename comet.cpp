#include "comet.h"
#include <iostream>
#include <cstdlib>

Comet::Comet(QPixmap* pm,int nx, int ny):Thing(pm,nx,ny)
{
  x=nx;
  y=ny;
  //setPos(x,y);
}

void Comet::move()
{
   if(x>0)
   {std::cout<< "MOVING! In Comet\n";
   setPos(x,y);}
   
   else
   {x=400;
   //call a self destruct or destruct function in mainwindow so that this is deleted if it gets this far
   }
}

void Comet::setXY(int nx,int ny)
{
  x=nx;
  y=ny;
}

int Comet::getX()
{return x;}

int Comet::getY()
{return y;}
