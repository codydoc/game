#include "thing.h"
#include <iostream>
#include <cstdlib>

/**Constructor*/
Thing::Thing(QPixmap *pm,int nx, int ny)
{
   pixmap=pm;
   setPixmap(*pm);
   x=nx;
   y=ny;
   setPos(x,y);
}

/**Destructor*/
Thing::~Thing()
{}
