#ifndef SAUCER_H
#define SAUCER_H

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

/**Saucer Class
Creates saucer object derived from Thing Class
*/
class Saucer: public Thing {
  
  public:
  /**Constructor*/
   Saucer(QPixmap *pm,int nx, int ny, MainWindow *mw);
   /**Move Function*/
   void move();
   /**Set XY*/
   void setXY(int,int);
   /**Get X*/
   int getX();
   /**Get y*/
   int getY();
   /**Get Name*/
   std::string getName();
   /**Is Active Bool*/
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
  /**Mainwindow reference*/
  MainWindow *mw;
  /**Name*/
  std::string name;

};


#endif
