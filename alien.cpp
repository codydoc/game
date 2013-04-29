#include "alien.h"
#include <iostream>
#include <cstdlib>
#include "mainwindow.h"

Alien::Alien(QPixmap* pm,int nx, int ny, MainWindow* mainw):Thing(pm,nx,ny)
{
  cx=nx;
  cy=ny;
  mw=mainw;
  name="Alien";
  isActive=false;
}

Alien::~Alien()
{}

void Alien::move()
{
  
   int randx = rand()%75-75;
   int randy = rand()%75-75;  
   
   cx= cx+ randx;
   cy= cy+randy;

   //std::cout<< "MOVING! In Alien\n";
  
   if(cx<0)
   {
     cx=cx-4*(randx);
   }
   
   if(cx>300)
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
  mw->killAlien();
}

int Alien::getX()
{return cx;}

int Alien::getY()
{return cy;}

std::string Alien::getName()
{return name;}
