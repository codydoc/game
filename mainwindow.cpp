#include "mainwindow.h"
#include <cstdlib>

/**
Handle Timer Function
@param is the pick value coming from GUITile MousePress Event
Function should handle where the timer connects, then start the timer 
*/
void MainWindow::handleTimer() {
    
   timercount++; 
   avatar->move();
      
  
   createComet();
   thecomet->setXY(thecomet->getX()-5,avatar->getY());
   thecomet->move();
      
      //input determines state/position of the object
      //timer actually updates the position
      //so, mouse click event should change the dx/dy in teh class
      //timer function should make sure the position is updated... ie setPos()
}

/**
Close Function
Closes the window 
*/
void MainWindow::close(){window->close();}

void MainWindow::createComet()
{
    if(isComet==false)
    {
    std::cout<<"Adding comet"<<std::endl;
    QString title("comet.png");
    comet = new QPixmap(title);
    thecomet = new Comet(comet,490,10);
    scene->addItem(thecomet);
     
    thinglist->push_back(thecomet);
    isComet=true;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
  
 // QWidget::keyPressEvent(e);
  std::cout<< "IN KEY PRESS EVENT"<<std::endl;
  //error->insertPlainText("In key press");
  
  switch(e->key())
  {
  case Qt::Key_Up: std::cout<<"PRESSED UP KEY"<<std::endl;
  avatar->setXY(avatar->getX(),avatar->getY()-10);
  break;
  case Qt::Key_Down: std::cout<<"PRESSED DOWN KEY"<<std::endl;
  avatar->setXY(avatar->getX(),avatar->getY()+10);
  break;
  }


}

void MainWindow::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
  avatar->setXY(avatar->getX()+5,avatar->getY()+5);
  std::cout<<"MOUSE PRESSED..."<<std::endl;
}

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
  
  timer->start(); 
 
 
}

void MainWindow::startGame() //Implement gameplay here
{
    scene->addItem(space1);
  
    QString title("chrissmall.png");
    chris = new QPixmap(title);
    avatar = new Chris(chris,30,160);
    scene->addItem(avatar);
    
    QString t1("spaceship.png");
    ship = new QPixmap(t1);
    spaceship = new Ship(ship,0,288,this);
    scene->addItem(spaceship);
}
 

void MainWindow::pauseb() //change what is happening in here to the keypress event
{
   
   //avatar->setXY(avatar->getX(),avatar->getY()+10);
   
   
   error->clear();
   error->insertPlainText("Pause button pressed...");
}

void MainWindow::redeemLife()
{
  livesbox->insertPlainText("1"); //set this to lifecount...
}

/**
MainWindow Function

This function creates the entire GUI using buttons, QTextEdit items, radio buttons,
scenes, views, QV and QH boxlayouts, addsWidgets to the main QWidget, and dynamically allocates all items.
All formatting of basic GUI occurs here
*/
MainWindow::MainWindow()  {
    
 
    window= new QWidget;
    
    //setFocusPolicy(Qt::StrongFocus);
    setFocus();
    
    window->setWindowTitle( "Chris Hadfield");
    
    QVBoxLayout *main = new QVBoxLayout;

    //TIMER CALL - SET UP
    timer = new QTimer(this);
    timer->setInterval(50); //was 1000
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
    timercount=0;

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
    
    //grabKeyboard(); //new dummy class that derives from qgraphicsview that has keypressevents
    
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
  
   thinglist = new MyList<Thing*>;
   isComet=false;
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

    delete thinglist;

    
    
 
}

