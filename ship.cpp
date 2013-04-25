#include "ship.h"
#include "mainwindow.h"
#include <iostream>
#include <cstdlib>

Ship::Ship(QPixmap* pm,int nx, int ny,MainWindow* mainw):Thing(pm,nx,ny)
{
  x=nx;
  y=ny;
  //setPos(x,y);
  hasLife=false;
  mw=mainw;
}

void Ship::move()
{
   //std::cout<< "MOVING! In Comet\n";
   setPos(x,y);
}

void Ship::mousePressEvent(QGraphicsSceneMouseEvent* e)
{
  hasLife=true; //Temporary, make this change whenever 5 aliens are killed, add "setHasLife" function in this class
  
  if(hasLife==true)
  {mw->redeemLife();}
}

void Ship::setXY(int nx,int ny)
{
  x=nx;
  y=ny;
}

int Ship::getX()
{return x;}

int Ship::getY()
{return y;}
