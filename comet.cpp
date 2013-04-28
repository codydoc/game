#include "comet.h"
#include <iostream>
#include <cstdlib>
#include "mainwindow.h"

Comet::Comet(QPixmap* pm,int nx, int ny, MainWindow* mainw):Thing(pm,nx,ny)
{
  cx=nx;
  cy=ny;
  //setPos(x,y);
  mw=mainw;
}

void Comet::move()
{
   if(cx>5)
   {std::cout<< "MOVING! In Comet\n";
   cx-=5;
   setX(cx-5);
   
   }
   
   else
   {//cx=400;
   mw->destroyComet(this);
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
