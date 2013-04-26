#include "alien.h"
#include <iostream>
#include <cstdlib>
#include "mainwindow.h"

Alien::Alien(QPixmap* pm,int nx, int ny, MainWindow* mainw):Thing(pm,nx,ny)
{
  x=nx;
  y=ny;
  //setPos(x,y);
  mw=mainw;
}

void Alien::move()
{
  
   int randx = rand()%210+1;
   int randy = rand()%210+1;  
   
   int newx;
   int newy;
   
   newx = x+ randx;
   newy= y+randy;
   
   if(x>0 && newx<350 && newy<350)
   {std::cout<< "MOVING! In Comet\n";
   setX(x+randx);
   setY(y+randy);
   
   }
   
}

void Alien::setXY(int nx,int ny)
{
  x=nx;
  y=ny;
}

void Alien::mousePressEvent(QGraphicsSceneMouseEvent* e)
{
  mw->killAlien(this);
}

int Alien::getX()
{return x;}

int Alien::getY()
{return y;}
