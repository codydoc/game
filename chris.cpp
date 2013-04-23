#include "chris.h"
#include <iostream>
#include <cstdlib>

Chris::Chris(QPixmap* pm,int nx, int ny):Thing(pm,nx,ny)
{
  
}

void Chris::move()
{
   std::cout<< "MOVING! In Chris\n";
}
