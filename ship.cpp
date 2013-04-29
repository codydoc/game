#include "ship.h"
#include "mainwindow.h"
#include <iostream>
#include <cstdlib>

/**Constructor*/
Ship::Ship(QPixmap* pm,int nx, int ny,MainWindow* mainw):Thing(pm,nx,ny)
{
  x=nx;
  y=ny;
  //setPos(x,y);
  hasLife=false;
  mw=mainw;
  name="Ship";
}

/**Destructor*/
Ship::~Ship()
{}

/**Move Function*/
void Ship::move()
{
   //std::cout<< "MOVING! In Comet\n";
   setPos(x,y);
}

/**Mouse Press Event Function
Calls redeem life function if hasLife bool is true
*/
void Ship::mousePressEvent(QGraphicsSceneMouseEvent* e)
{
  hasLife=true; 
  
  if(hasLife==true)
  {mw->redeemLife();}
}

/**Set XY*/
void Ship::setXY(int nx,int ny)
{
  x=nx;
  y=ny;
}

/**Get X*/
int Ship::getX()
{return x;}

/**Get Y*/
int Ship::getY()
{return y;}

/**Get Name*/
std::string Ship::getName()
{return name;}



