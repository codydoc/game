#include "alien.h"
#include <iostream>
#include <cstdlib>
#include "mainwindow.h"

/**Constructor*/
Alien::Alien(QPixmap* pm,int nx, int ny, MainWindow* mainw):Thing(pm,nx,ny)
{
  cx=nx;
  cy=ny;
  mw=mainw;
  name="Alien";
  isActive=false;
}

/**Destructor*/
Alien::~Alien()
{}

/**Move Function
Moves alien to new position randomly
*/
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

/**Sets X and Y*/
void Alien::setXY(int nx,int ny)
{
  cx=nx;
  cy=ny;
}

/**MousePressEvent Function
Calls kill alien
*/
void Alien::mousePressEvent(QGraphicsSceneMouseEvent* e)
{
  mw->killAlien();
}

/**Get X*/
int Alien::getX()
{return cx;}

/**Get Y*/
int Alien::getY()
{return cy;}

/**Gets Name*/
std::string Alien::getName()
{return name;}
