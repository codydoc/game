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
  name="Comet";
  isActive=false;
}

void Comet::move()
{
   setY(cy);
   
   if(cx>5)
   {//std::cout<< "MOVING! In Comet\n";
   cx-=5;
   setX(cx-5);
   }
   
   
   else
   {
   mw->destroyComet();
   }
}

void Comet::setXY(int nx,int ny)
{
  cx=nx;
  cy=ny;
}

int Comet::getX()
{return x;}

int Comet::getY()
{return y;}

std::string Comet::getName()
{return name;}



