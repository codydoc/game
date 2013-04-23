#include "mainwindow.h"
#include <cstdlib>

/**
Handle Timer Function
@param is the pick value coming from GUITile MousePress Event
Function should handle where the timer connects, then start the timer 
*/
void MainWindow::handleTimer() {
    
    connect(timer, SIGNAL(timeout()), this, SLOT(moveTile(pick)));
    timer->start(); 
      
}

/**
Close Function
Closes the window 
*/
void MainWindow::close(){window->close();}

/**
Start Button Function

  This function takes in the three initialization ints, instantiates the board,
  dynamically allocates GUITiles, and then addes them to the scene in the right place. It also
  adds the GUITile objects to a vector in the correct order.
*/
void MainWindow::startButton()
{ 
  error->clear();
  error->insertPlainText("Start Button was pressed");
  
  
  scene->removeItem(bgitem);
  startGame();
  //scene->addItem(space1);
 
}

void MainWindow::startGame()
{
  scene->addItem(space1);
}
 

void MainWindow::pauseb()
{
   error->clear();
   error->insertPlainText("Pause button pressed...");
}


/**
MainWindow Function

This function creates the entire GUI using buttons, QTextEdit items, radio buttons,
scenes, views, QV and QH boxlayouts, addsWidgets to the main QWidget, and dynamically allocates all items.
All formatting of basic GUI occurs here
*/
MainWindow::MainWindow()  {
    

    window= new QWidget;
    
    window->setWindowTitle( "Graphical 8-Tile Puzzle");
    
    QVBoxLayout *main = new QVBoxLayout;

    //TIMER CALL - SET UP
    timer = new QTimer(this);
    timer->setInterval(5);
    //connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));


    start= new QPushButton("Start Game");
    quit= new QPushButton("Quit");
    pause = new QPushButton("Pause");
    


    connect(start,SIGNAL(clicked()),this,SLOT(startButton()));
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));
    connect(pause,SIGNAL(clicked()),this,SLOT(pauseb()));
   
    
    tbox1= new QTextEdit("Please enter your name:"); //Enter Size

    error = new QTextEdit("Message Box");
    
    tbox1->setMaximumHeight(30);
    error->setMaximumHeight(50);
    
    lives = new QLabel("Lives Remaining: ");
    score = new QLabel("Score: ");
    livesbox = new QTextEdit();
    scorebox = new QTextEdit();
    bool yes =true;
    livesbox->setReadOnly(yes);
    scorebox->setReadOnly(yes);
    livesbox->setMaximumHeight(30);
    scorebox->setMaximumHeight(30);
    livesbox->setMaximumWidth(40);
    
    
    //IMAGES
    QString title1("ChrisTitle.png");
    bground = new QPixmap(title1);
    QPixmap scaled = bground->scaledToHeight(390);
    bgitem = new QGraphicsPixmapItem(scaled);
   
    QString title("space.png");
    space = new QPixmap(title);
    QPixmap scaled1 = space->scaledToHeight(390);
    space1 = new QGraphicsPixmapItem(scaled1);
    
    
    layout = new QHBoxLayout;
    horlay = new QHBoxLayout;
    horlay2 = new QHBoxLayout;
    horlay3 = new QHBoxLayout;
    horlay4 = new QHBoxLayout;
    horlay5 = new QHBoxLayout;
    
    scene = new QGraphicsScene();
    view = new QGraphicsView( scene );
    view->setFixedSize( WINDOW_MAX_X, WINDOW_MAX_Y );
    
    horlay->addWidget(tbox1);

    layout->addWidget(start);
    layout->addWidget(pause);
    layout->addWidget(quit);

    horlay3->addWidget(view);
    horlay4->addWidget(score);
    horlay4->addWidget(scorebox);
    horlay4->addWidget(lives);
    horlay4->addWidget(livesbox);
    horlay5->addWidget(error);
   
   
   window->setLayout(main);
   main->addLayout(horlay);
   main->addLayout(horlay2);
   main->addLayout(layout);
   main->addLayout(horlay3);
   main->addLayout(horlay4);
   main->addLayout(horlay5);
    	
   scene->addItem(bgitem);

}


/**
Show Function

Shows the main window when called from main.
*/
void MainWindow::show() 
{
    window->show();
}




/**
Destructor
Deletes dynamically allocated objects
*/
MainWindow::~MainWindow()
{
    //timer->stop();
    delete timer;
    delete window;
    delete start;
    delete pause;
    delete quit;
    delete tbox1;
    delete tbox2;
    delete tbox3;
    delete layout;
    delete horlay;
    delete horlay2;

    //*
    delete scene;
    delete view;

    delete error;
    delete horlay3;
    delete horlay4;
    delete horlay5;



    
    
 
}

