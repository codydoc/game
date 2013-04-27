#include "saucer.h"
#include <iostream>
#include <cstdlib>
#include "mainwindow.h"

Saucer::Saucer(QPixmap* pm,int nx, int ny, MainWindow* mainw):Thing(pm,nx,ny)
{
  cx=nx;
  cy=ny;
  //setPos(x,y);
  mw=mainw;
  vX=2;
  vY=2;
}

void Saucer::move()
{
   std::cout<< "MOVING! In Saucer\n";
   
   cx-=vX;
   cy-=vY;
   
   if(cx>0)
   {
      if(y<350)
      {
        cx-=vX;
        cy-=vY;
        setX(cx);
        setY(cy);
      }
      
      if(y>350 || y<0)
      {
      vY=-vY;
      cy-=vY;
      setY(cy);
      cx-=vX;
      setX(cx);
      }  
   }
   
//setPos(x,y);
   
   else
   {cx=400;
   //mw->destroyComet(this); //change to destroy saucer
   //call a self destruct or destruct function in mainwindow so that this is deleted if it gets this far
   }
}

void Saucer::setXY(int nx,int ny)
{
  x=nx;
  y=ny;
}

int Saucer::getX()
{return x;}

int Saucer::getY()
{return y;}
