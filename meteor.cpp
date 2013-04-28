#include "meteor.h"
#include <iostream>
#include <cstdlib>
#include "mainwindow.h"

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
}

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
   {//cx=400;
   mw->destroyMeteor(this); //create destroyMeteor
   //call a self destruct or destruct function in mainwindow so that this is deleted if it gets this far
   return;
   }
   
   //QPointF origin(10,10);
   //setTransformOriginPoint(origin);
   
}

void Meteor::setXY(int nx,int ny)
{
  x=nx;
  y=ny;
}

int Meteor::getX()
{return x;}

int Meteor::getY()
{return y;}

std::string Meteor::getName()
{return name;}



