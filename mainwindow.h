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
#include <QInputDialog>
#include <QLabel>
#include <QRadioButton>
#include <QListView>
#include <QString>
#include <QGridLayout>
#include <QMessageBox>
#include <QKeyEvent>
#include <iostream>
#include <cstdlib>
#include <deque>
#include <cmath>

#include "mylist.h"
#include "thing.h"
#include "chris.h"
#include "comet.h"
#include "ship.h"
#include "alien.h"
#include "saucer.h"
#include "meteor.h"



#include <vector>

#define WINDOW_MAX_X 600
#define WINDOW_MAX_Y 400


/**
MainWindow Class

This is the mainwindow class that inherits from QWidget, and it stores
a scene, view, QV and QH BoxLayouts, and the gameplay is managed and allocated here.
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
    /**Timer count int*/
    int timercount;
    /**Function starts the game by adding initial items to scene, called by startbutton slot function*/
    void startGame();
    /**Creates a new comet if there is not an active comet in the scene*/
    void createComet();
    /**Allows the player to redeem a life if he/she has killed three aliens*/
    void redeemLife();
    /**Destroys a comet if it passes the restricted range or hits the avatar*/
    void destroyComet();
    /**Destroys meteor if it passes the restricted range or hits the avatar*/
    void destroyMeteor();
    /**Kills an alien, called from mousepressevent in alien class*/
    void killAlien();
    /**Kills the flying saucer when passes out of range or hits avatar*/
    void destroySaucer();
    /**Creates an alien if not an active one*/
    void createAlien();
    /**Creates a flying saucer if there is no active one*/
    void createSaucer();
    /**Creates a meteor if no active one*/
    void createMeteor();

 
protected:
    /**Key press event to grab the keyboard when moving avatar with up/down arrows */
    void keyPressEvent(QKeyEvent *e); //grabkeyboard
    /**Mouse Press event*/
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
    
private:
    /**Scene*/
    QGraphicsScene *scene;
    /**View*/
    QGraphicsView *view;
    /**QTimer*/
    QTimer *timer;
    /**Timer interval*/
    int timerint;
    /**Start Button*/
    QPushButton *start;
    /**Exit button*/
    QPushButton *quit;
    /**Pause button*/
    QPushButton *pause;

    /**Window*/
    QWidget *window;
    
    /**Welcomes playername*/
    QLabel *tbox1;
    /**Message box on bottom*/
    QTextEdit *error;
    /**Lives Box*/
    QTextEdit *livesbox;
    /**Score Box*/
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
    
    /**Images*/
    /**Background image*/
    QPixmap *bground;
    QGraphicsPixmapItem *bgitem;
    
    /**Space Background*/
    QPixmap *space;
    QGraphicsPixmapItem *space1;
    
    /**Chris Avatar*/
    QPixmap *chris;
    Chris* avatar;
    
    /**Comet and bool*/
    QPixmap *comet;
    Comet* thecomet;
    bool isComet;
    
    /**Space shuttle*/
    QPixmap *ship;
    Ship* spaceship;
    
    /**Alien*/
    QPixmap *ali;
    Alien* alien;
    bool isAlien;
    
    /**Flying Saucer*/
    QPixmap *sauce;
    Saucer* sauceship;
    bool isSaucer;
    
    /**Meteorite*/
    QPixmap *met;
    Meteor* meteorite;
    bool isMeteor;

    /**MyList of Thing*s to store active things*/
    MyList<Thing*>* thinglist;
   
    /**Starting message box*/
    QMessageBox *startm;
    /**Name input in startm*/
    QInputDialog *inputname;
    /**Player Name - Important*/
    QString playername;
    
    /**Game Over screen*/
    QPixmap *gameo;
    QGraphicsPixmapItem *gameover;
    
    /**Heart Image*/
    QPixmap *hear;
    QGraphicsPixmapItem *heart;
    
    /**Main Score*/
    int mainscore;
    /**Number of Lives Left*/
    int livesleft;
    /**Has Started Bool*/
    bool hasStarted;
    /**Number of aliens killed*/
    int alienskilled;
    /**Heart bool*/
    bool heartshowing;

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
