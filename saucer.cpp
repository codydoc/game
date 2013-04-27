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
}

void Saucer::move()
{
   if(cx>0 && cy>0 && cy<350)
   {std::cout<< "MOVING! In Saucer\n";
   //setPos(x,y);
   cx=cx-10;
   cy=cy-5;
   setX(cx);
   setY(cy);
   }
   

   
   else
   {x=400;
    y=50;
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
