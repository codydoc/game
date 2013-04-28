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
}

void Meteor::move()
{
   if(cx>5)
   {std::cout<< "MOVING! In Comet\n";
   cx-=5;
   setX(cx-5);
   
   }
   
   else
   {//cx=400;
   mw->destroyMeteor(this); //create destroyMeteor
   //call a self destruct or destruct function in mainwindow so that this is deleted if it gets this far
   }
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
