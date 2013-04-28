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

class Saucer: public Thing {
  
  public:
   Saucer(QPixmap *pm,int nx, int ny, MainWindow *mw);
   void move();
   void setXY(int,int);
   int getX();
   int getY();
   std::string getName();
   bool isActive;
   
  private:
  int cx;
  int cy;
  int vX;
  int vY;
  QPixmap *pixmap;
  MainWindow *mw;
  std::string name;

};


#endif
