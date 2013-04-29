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

/**Thing Class
Is the basis for all thing objects, inherits from QGraphicsPixmap Item
*/
class Thing: public QGraphicsPixmapItem {
  
  public:
  /**Constructor*/
   Thing(QPixmap *pm,int nx, int ny);
   /**Destructor*/
   ~Thing();
   /**Move*/
   virtual void move() = 0;
   /**Get Name*/
   virtual std::string getName() = 0;
   /**Is Active*/
   bool isActive;
   
  protected:
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
  

};


#endif
