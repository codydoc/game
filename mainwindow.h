#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
#include <deque>
#include <cmath>

#include "mylist.h"



#include <vector>

#define WINDOW_MAX_X 400
#define WINDOW_MAX_Y 400


/**
MainWindow Class

This is the mainwindow class that inherits from QWidget, and it stores
a scene, view, QV and QH BoxLayouts, a Board Object, GUITile vector, solutions lists,
and other member functions and public slots...
@author CodyRapp
*/
class MainWindow : public QWidget {
    Q_OBJECT
    
public:
    /**Default constructor*/
    explicit MainWindow();
    /**Destructor*/
    ~MainWindow();
    /**Show function*/
    void show();
    /**Timer count int, not used*/
    int timercount;
 

    
private:
    /**Scene*/
    QGraphicsScene *scene;
    /**View*/
    QGraphicsView *view;
    /**QTimer*/
    QTimer *timer;
    /**Start Button*/
    QPushButton *start;
    /**Exit button*/
    QPushButton *quit;
    /**A star algorithm button*/
    
    QPushButton *pause;

    /**Window*/
    QWidget *window;
    
    /**Size input*/
    QTextEdit *tbox1;
    /**NuminitMoves input*/
    QTextEdit *tbox2;
    /**Seed input*/
    QTextEdit *tbox3;
    /**Error box*/
    QTextEdit *error;
    
    QTextEdit *livesbox;
    QTextEdit *scorebox;
    
    /**Horizontal layouts*/
    QHBoxLayout *horlay;
    QHBoxLayout *layout;
    QHBoxLayout *horlay2;
    QHBoxLayout *horlay3;
    QHBoxLayout *horlay4;
    QHBoxLayout *horlay5;
    
    /**Labels*/
    QLabel *lives;
    QLabel *score;
    
    

public slots:
    /**Slot to handle timer*/
    void handleTimer();
    /**Slot to handle start button push*/
    void startButton();
    /**Slot to close the window*/
    void close();
    /**Slot to handle the pause button*/
    void pauseb();
 
    

};

#endif // MAINWINDOW_H
