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
   
   std::cout<<"LIST SIZE: "<<thinglist->size()<<std::endl;
   
   for(int i=0;i<thinglist->size();i++)
   {
     if(avatar->collidesWithItem(thinglist->at(i)))
     {
       mainscore-=200;
       QString s;
       livesleft--;
       livesbox->clear();
       livesbox->insertPlainText(s.setNum(livesleft));
       
       QString m;
       scorebox->clear();
       scorebox->insertPlainText(m.setNum(mainscore));
       
       error->clear();
       error->insertPlainText("Oh no! You lost a life!");
       
     }
   
   }
      
   if(timercount%20==0)
   {mainscore+=10;
   QString s;
   scorebox->clear();
   scorebox->insertPlainText(s.setNum(mainscore));
   error->clear();}
   
   createComet();
   thecomet->move();
   
   int randalien = rand()%250+1;
   
   if(timercount%randalien==0)
   {createAlien();
   }
   
   if(isAlien==true && timercount%50==0)
   {alien->move();}
   
   int randsauce = rand()%150+1;
   if(timercount%randsauce==0)
   {
     createSaucer();
   }
   
   if(isSaucer)
   {
     sauceship->move();
   }
   
   int randmet = rand()%150+1;
   if(timercount%randmet==0)
   {
     createMeteor();
   }
   
   if(isMeteor)
   {
     meteorite->move();
   }
   
      

}

/**
Close Function
Closes the window 
*/
void MainWindow::close(){window->close();}

void MainWindow::destroyComet(Comet* com)
{
  scene->removeItem(com);
  isComet=false;
  
  for(int i=0;i<thinglist->size();i++)
  {
    if(thinglist->at(i)==com)
    {
      std::cout<<"DESTROYING COMET"<<std::endl;
      thinglist->remove(com);
      //delete com; //need to make sure not a ton of memory leaks here
    }
  }
}

void MainWindow::destroyMeteor(Meteor* met)
{
  scene->removeItem(met);
  isMeteor=false;
  
  for(int i=0;i<thinglist->size();i++)
  {
    if(thinglist->at(i)==met)
    {
      std::cout<<"DESTROYING METEOR"<<std::endl;
      thinglist->remove(met);
      //delete com;
      
    }
  }
}

void MainWindow::destroySaucer(Saucer* sau)
{
  scene->removeItem(sau);
  isSaucer=false;
  
  for(int i=0;i<thinglist->size();i++)
  {
    if(thinglist->at(i)==sau)
    {
      std::cout<<"DESTROYING SAUCER"<<std::endl;
      thinglist->remove(sau);
      //delete com;
      
    }
  }
}

void MainWindow::killAlien(Alien* ali)
{

  scene->removeItem(ali);
  isAlien=false;
  error->clear();
  error->insertPlainText("You killed the alien! +100 points");
  
  for(int i=0;i<thinglist->size();i++)
  {
    if(thinglist->at(i)==ali)
    {
      thinglist->remove(ali);
      //delete com;
    }
  }
  
  mainscore+=100;
}

void MainWindow::createComet()
{
    int random;
    random = rand() %300+10;
    
    if(isComet==false)
    {
    std::cout<<"Adding comet"<<std::endl;
    QString title("comet.png");
    comet = new QPixmap(title);
    thecomet = new Comet(comet,450,random,this);
    scene->addItem(thecomet);
     
    thinglist->push_back(thecomet);
    isComet=true;
    }
}

void MainWindow::createMeteor()
{
    int random;
    random = rand() %250+50;
    
    if(isMeteor==false)
    {
    std::cout<<"Adding meteor"<<std::endl;
    QString title("asteroid.png");
    met = new QPixmap(title);
    meteorite = new Meteor(met,350,random,this);
    scene->addItem(meteorite);
     
    thinglist->push_back(meteorite);
    isMeteor=true;
    }
}

void MainWindow::createAlien()
{
    int randomx;
    randomx=rand()%400+75;
    int randomy;
    randomy = rand() %300+15;
    
    if(isAlien==false){
    std::cout<<"Adding alien"<<std::endl;
    QString title("a1.png");
    ali = new QPixmap(title);
    alien = new Alien(ali,randomx,randomy,this);
    scene->addItem(alien);
    isAlien=true;
    thinglist->push_back(alien);}

}

void MainWindow::createSaucer()
{
    
    int randomy;
    randomy = rand() %300+15;
    
    if(isSaucer==false){
    std::cout<<"Adding saucer"<<std::endl;
    QString title("saucer.png");
    sauce = new QPixmap(title);
    sauceship = new Saucer(sauce,490,randomy,this);
    scene->addItem(sauceship);
    isSaucer=true;
    thinglist->push_back(sauceship);}

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
 
  
  if(!hasStarted)
  {
  error->clear();
  error->insertPlainText("Start Button was pressed");
  
  startm->setText("Welcome to Chris Hadfield Defends Earth!\n\n Use the arrow keys to move Chris up and down.\n Avoid asteroids, UFOs, and comets.\nUse your mouse to click on and kill aliens. \nFor each alien you kill, you get 100 bonus points. \nYou have three lives");
  startm->exec();
  
  scene->removeItem(bgitem);
  startGame();
  
  timer->start(); 
  
  QString s;
  scorebox->insertPlainText(s.setNum(mainscore));
  
  QString p;
  livesbox->insertPlainText(p.setNum(livesleft));
 
  hasStarted=true;
  }
  
  else
  {
  error->clear();
  error->insertPlainText("The game has already been started!");
  }
 
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
   
        if(timer->isActive())
	{timer->stop();
	pause->setText("Resume");
	error->clear();
        error->insertPlainText("Game paused...");
	
	}

	else if(!timer->isActive())
	{timer->start();
	pause->setText("Pause");
	error->clear();
        error->insertPlainText("Game resumed!");
	}
   
   
  
}

void MainWindow::redeemLife()
{
  QString s;
  livesleft++;
  livesbox->clear();
  livesbox->insertPlainText(s.setNum(livesleft)); //set this to lifecount...
}

/**
MainWindow Function

This function creates the entire GUI using buttons, QTextEdit items, radio buttons,
scenes, views, QV and QH boxlayouts, addsWidgets to the main QWidget, and dynamically allocates all items.
All formatting of basic GUI occurs here
*/
MainWindow::MainWindow()  {
    
   inputname= new QInputDialog;
   bool ok=false;
   playername = inputname->getText(this, tr("QInputDialog::getText()"),
                                         tr("User name:"), QLineEdit::Normal,
                                         tr("Type your name here"), &ok);
 if(ok){
    window= new QWidget;
    
    //setFocusPolicy(Qt::StrongFocus);
    setFocus();
    
    window->setWindowTitle( "Chris Hadfield");
    
    QVBoxLayout *main = new QVBoxLayout;

    //TIMER CALL - SET UP
    timerint=50;
    timer = new QTimer(this);
    timer->setInterval(timerint); //was 1000
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
    timercount=1;

    start= new QPushButton("Start Game");
    quit= new QPushButton("Quit");
    pause = new QPushButton("Pause");
    
    mainscore=0;

    connect(start,SIGNAL(clicked()),this,SLOT(startButton()));
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));
    connect(pause,SIGNAL(clicked()),this,SLOT(pauseb()));
   
   
                                         
    
    tbox1= new QLabel("Welcome "+ playername); //Enter Size

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
    
    startm = new QMessageBox();
    
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
    
    QBrush brush(Qt::black);
    scene->setBackgroundBrush(brush);
    
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
   isAlien=false;
   isSaucer=false;
   isMeteor=false;
   
   livesleft=3;
   hasStarted=false;
   
   }
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

