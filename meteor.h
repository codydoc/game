#ifndef METEOR_H
#define METEOR_H

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

/**Meteor Class
Meteor object derives from Thing Class
*/
class Meteor: public Thing {
  
  public:
   /**Constructor*/
   Meteor(QPixmap *pm,int nx, int ny, MainWindow *mw);
   /**Move*/
   void move();
   /**Set XY*/
   void setXY(int,int);
   /**Get X*/
   int getX();
   /**Get Y*/
   int getY();
   /**Rotation Integer*/
   int rotation;
   /**Get Name*/
   std::string getName();
   /**Is Active*/
   bool isActive;
   
  private:
  /**X*/
  int cx;
  /**Y*/
  int cy;
  /**Velocity X*/
  int vX;
  /**Velocity Y*/
  int vY;
  /**Pixmap*/
  QPixmap *pixmap;
  /**Mainwindow Reference*/
  MainWindow *mw;
  /**Name*/
  std::string name;

};


#endif
