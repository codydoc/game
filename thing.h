#ifndef THING_H
#define THING_H

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

class Thing: public QGraphicsPixmapItem {
  
  public:
   Thing(QPixmap *pm,int nx, int ny);
   virtual void move() = 0;
   
  private:
  int x;
  int y;
  int vX;
  int vY;
  QPixmap *pixmap;

};


#endif
