#include "meteor.h"
#include <iostream>
#include <cstdlib>
#include "mainwindow.h"

/**Constructor*/
Meteor::Meteor(QPixmap* pm,int nx, int ny, MainWindow* mainw):Thing(pm,nx,ny)
{
  cx=nx;
  cy=ny;
  //setPos(x,y);
  mw=mainw;
  rotation=0;
  vX=1;
  vY=1;
  name="Meteor";
  isActive=false;
}

/**Move Function*/
void Meteor::move()
{
   cx-=vX;
   cy-=vY;
   
   if(cx>100)
   {
      if(cy<250 && cy>150)
      {
        cx-=vX;
        cy-=vY;
        setX(cx);
        setY(cy);
      }
      
      if(cy>250 || cy<150)
      {
      vY=-vY;
      cy-=vY;
      setY(cy);
      cx-=vX;
      setX(cx);
      } 
      
      rotate(rotation-10); 
   }
   
   
   else
   {
   mw->destroyMeteor(); 
   return;
   }
   
   
}

/**Set XY Function*/
void Meteor::setXY(int nx,int ny)
{
  cx=nx;
  cy=ny;
}

/**Get X*/
int Meteor::getX()
{return x;}

/**Get Y*/
int Meteor::getY()
{return y;}

/**Get Name*/
std::string Meteor::getName()
{return name;}



