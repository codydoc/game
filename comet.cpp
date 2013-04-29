#include "comet.h"
#include <iostream>
#include <cstdlib>
#include "mainwindow.h"

/**Constructor*/
Comet::Comet(QPixmap* pm,int nx, int ny, MainWindow* mainw):Thing(pm,nx,ny)
{
  cx=nx;
  cy=ny;
  //setPos(x,y);
  mw=mainw;
  name="Comet";
  isActive=false;
}

/**Move*/
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

/**Set X*/
void Comet::setXY(int nx,int ny)
{
  cx=nx;
  cy=ny;
}

/**Get X*/
int Comet::getX()
{return x;}

/**Get Y*/
int Comet::getY()
{return y;}

/**Get Name*/
std::string Comet::getName()
{return name;}



