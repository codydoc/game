#ifndef SHIP_H
#define SHIP_H

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

class MainWindow;

/**Ship Class
Ship Object created that inherits from Thing Class
*/
class Ship: public Thing {
  
  public:
   /**Constructor*/
   Ship(QPixmap *pm,int nx, int ny,MainWindow* mw);
   /**Destructor*/
   ~Ship();
   /**Move*/
   void move();
   /**Set XY*/
   void setXY(int,int);
   /**Get X*/
   int getX();
   /**Get Y*/
   int getY();
   /**MousePressEvent*/
   void mousePressEvent(QGraphicsSceneMouseEvent *e);
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
  /**Has Life Bool*/
  bool hasLife;
  /**Mainwindow Reference*/
  MainWindow *mw;
  /**Name*/
  std::string name;

};


#endif
