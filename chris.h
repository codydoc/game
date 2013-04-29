#ifndef CHRIS_H
#define CHRIS_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QTextEdit>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QtGui/QApplication>
#include <QLabel>
#include <QRadioButton>
#include <QListView>
#include <QString>
#include <QGridLayout>
#include <iostream>
#include <cstdlib>

#include "thing.h"

/**Chris Class
Chris Avatar Object inherits from THing
*/
class Chris: public Thing {
  
  public:
   /**Constructor*/
   Chris(QPixmap *pm,int nx, int ny);
   /**Move*/
   void move();
   /**Set XY*/
   void setXY(int,int);
   /**Get X*/
   int getX();
   /**Get Y*/
   int getY();
   /**Get Name*/
   std::string getName();
   
  private:
  /**X*/
  int x;
  /**Y*/
  int y;
  /**Velocity X*/
  int vX;
  /**Velocity Y*/
  int vY;
  /**Pixmap*/
  QPixmap *pixmap;
  /**Name*/
  std::string name;

};


#endif
