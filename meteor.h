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

class Meteor: public Thing {
  
  public:
   Meteor(QPixmap *pm,int nx, int ny, MainWindow *mw);
   void move();
   void setXY(int,int);
   int getX();
   int getY();
   
  private:
  int cx;
  int cy;
  int vX;
  int vY;
  QPixmap *pixmap;
  MainWindow *mw;

};


#endif
