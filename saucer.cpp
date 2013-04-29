#include "saucer.h"
#include <iostream>
#include <cstdlib>
#include "mainwindow.h"

/**Constructor*/
Saucer::Saucer(QPixmap* pm,int nx, int ny, MainWindow* mainw):Thing(pm,nx,ny)
{
  cx=nx;
  cy=ny;
  //setPos(x,y);
  mw=mainw;
  vX=2;
  vY=2;
  name="Saucer";
  isActive=false;
}

/**Move function*/
void Saucer::move()
{
   
   cx-=vX;
   cy-=vY;
   
   if(cx>0)
   {
      if(cy<330 && cy>0)
      {
        cx-=vX;
        cy-=vY;
        setX(cx);
        setY(cy);
      }
      
      if(cy>330 || cy<0)
      {
      vY=-vY;
      cy-=vY;
      setY(cy);
      cx-=vX;
      setX(cx);
      }  
   }
   
   else
   {
   mw->destroySaucer(); 

   }
}

/**XY Setter*/
void Saucer::setXY(int nx,int ny)
{
  cx=nx;
  cy=ny;
}

/**Get X*/
int Saucer::getX()
{return cx;}

/**Get Y*/
int Saucer::getY()
{return cy;}

/**Get Name*/
std::string Saucer::getName()
{return name;}

