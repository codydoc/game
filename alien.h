#ifndef ALIEN_H
#define ALIEN_H

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

/**
Alien Class
Basic Alien class, inherits from Thing Class
*/
class Alien: public Thing {
  
  public:
   /**Constructor*/
   Alien(QPixmap *pm,int nx, int ny, MainWindow *mw);
   /**Destructor*/
   ~Alien();
   /**Move*/
   void move();
   /**Set X and Y values*/
   void setXY(int,int);
   /**Get X*/
   int getX();
   /**Get Y*/
   int getY();
   /**Mouse press event to kill alien*/
   void mousePressEvent(QGraphicsSceneMouseEvent* e);
   /**Get Name*/
   std::string getName();
   /**Is Active Bool*/
   bool isActive;
   
  private:
  /**X*/
  int cx;
  /**Y*/
  int cy;
  /**X velocity*/
  int vX;
  /**Y Velocity*/
  int vY;
  /**Pixmap*/
  QPixmap *pixmap;
  /**Mainwindow reference*/
  MainWindow *mw;
  /**Name*/
  std::string name;
  

};


#endif
