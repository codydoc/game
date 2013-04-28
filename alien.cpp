#include "alien.h"
#include <iostream>
#include <cstdlib>
#include "mainwindow.h"

Alien::Alien(QPixmap* pm,int nx, int ny, MainWindow* mainw):Thing(pm,nx,ny)
{
  cx=nx;
  cy=ny;
  //setPos(x,y);
  mw=mainw;
}

void Alien::move()
{
  
   int randx = rand()%75-75;
   int randy = rand()%75-75;  
   
   cx= cx+ randx;
   cy= cy+randy;

   std::cout<< "MOVING! In Alien\n";
  
   if(cx<0)
   {
     cx=cx-4*(randx);
   }
   
   if(cx>400)
   {
     cx=cx-4*(randx);
   }
   
   if(cy<0)
   {
     cy=cy-4*(randy);
   }
   
   if(cy>360)
   {
     cy=cy-4*(randy);
   }
 
   setX(cx);
   setY(cy);
   
}

void Alien::setXY(int nx,int ny)
{
  cx=nx;
  cy=ny;
}

void Alien::mousePressEvent(QGraphicsSceneMouseEvent* e)
{
  mw->killAlien(this);
}

int Alien::getX()
{return cx;}

int Alien::getY()
{return cy;}
