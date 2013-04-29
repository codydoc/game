#ifndef COMET_H
#define COMET_H

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

/**Comet Class
Inherits from Thing, creates Comet Object
*/
class Comet: public Thing {
  
  public:
   /**Constructor*/
   Comet(QPixmap *pm,int nx, int ny, MainWindow *mw);
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
   /**Is Active*/
   bool isActive;
   
  private:
  /**X*/
  int cx;
  /**Y*/
  int cy;
  /**velocity X*/
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
