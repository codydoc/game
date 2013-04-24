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

class Chris: public Thing {
  
  public:
   Chris(QPixmap *pm,int nx, int ny);
   void move();
   void setXY(int,int);
   int getX();
   int getY();
   
  private:
  int x;
  int y;
  int vX;
  int vY;
  QPixmap *pixmap;

};


#endif
