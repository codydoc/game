#include "mainwindow.h"
#include <cstdlib>

/**
Handle Timer Function
Function handles most of gameplay as objects move relative to the main timer instances
Moves avatar to new position set by mouseclick
Creates and moves other Things if they are not on the board
Checks to see if lives left is greater than zero, otherwise ends the game, clears the scene, etc.
Also checks for collisions 
*/
void MainWindow::handleTimer() {
    
   if(livesleft>0)
   {
   
   timercount++; 
   avatar->move();
   
   if(timercount%1000==0)
   {
     timerint-=10;
     if(timerint>0)
     {
     timer->setInterval(timerint);
     }
     else
     {timerint+=50;}
   }
   
   //std::cout<<"LIST SIZE: "<<thinglist->size()<<std::endl;
   
   for(int i=0;i<thinglist->size();i++)
   {
       //std::cout<<"iteminlist: "<<thinglist->at(i)->getName()<<std::endl;
     
     if(avatar->collidesWithItem(thinglist->at(i)))
     {
       mainscore-=10;
       QString s;
       livesleft--;
       livesbox->clear();
       livesbox->insertPlainText(s.setNum(livesleft));
       
       QString m;
       scorebox->clear();
       scorebox->insertPlainText(m.setNum(mainscore));
       
       error->clear();
       error->insertPlainText("Oh no! You lost a life!");
       
       //std::cout<<"BEING HIT BY"<<thinglist->at(i)->getName()<<std::endl;
       if(thinglist->at(i)->isActive)
       {
         scene->removeItem(thinglist->at(i));
         ((thinglist->at(i))->isActive)=false;
         thinglist->remove(thinglist->at(i));
       }
       
       
     }
   
   }
      
   if(timercount%20==0)
   {
   mainscore+=1000;
   QString s;
   scorebox->clear();
   scorebox->insertPlainText(s.setNum(mainscore));
   error->clear();}
   
   if(alienskilled%3==0 && heartshowing==false && alienskilled>0)
   {
    scene->addItem(heart);
    heartshowing=true;
   }
   
   if(!thecomet->isActive)
   {
     createComet();
   }
   
   if(thecomet->isActive)
   {thecomet->move();}
   
   int randalien = rand()%250+1;
   
   if(timercount%randalien==0)
   {createAlien();}
   
   if(isAlien==true && timercount%50==0)
   {alien->move();}
   
   int randsauce = rand()%150+1;
   if(!isSaucer && timercount%randsauce==0)
   {
     createSaucer();
   }
   
   if(isSaucer)
   {
     sauceship->move();
   }
   
   int randmet = rand()%150+1;
   if(!isMeteor && timercount%randmet==0)
   {
     createMeteor();
   }
   
   if(isMeteor)
   {
     meteorite->move();
   }
   
 }
 
 else
 {
   error->clear();
   error->insertPlainText("Game Over");
   timer->stop();
   QString lose;
   startm->setText("Game Over!\n Your score was: " + lose.setNum(mainscore)+"\nTo restart please quit and run the program again.");
   startm->exec();
 
   scene->clear();
 
   QString gover("game_over.jpg");
   gameo = new QPixmap(gover);
   gameover = new QGraphicsPixmapItem(*gameo);
   scene->addItem(gameover);

 }     
  
  
  
}

/**
Close Function
Closes the game 
*/
void MainWindow::close(){window->close();}

/**
Destroy Comet Function
Destroys the comet
*/
void MainWindow::destroyComet()
{

  if(thecomet->isActive)
  {
    scene->removeItem(thecomet);
    isComet=false;
    thecomet->isActive=false;
  
    if(thinglist->remove(thecomet))
    {
       //std::cout<<"COMET DESTROYED"<<std::endl;
    }
  
  } 
}

/**
Destroy Meteor Function
Destroys the meteor
*/
void MainWindow::destroyMeteor()
{
  if(meteorite->isActive)
  {
  scene->removeItem(meteorite);
  isMeteor=false;
  meteorite->isActive=false;
  
   if(thinglist->remove(meteorite))
   {
    //std::cout<<"DESTROYING METEOR"<<std::endl;
   }
  
  }
  
}

/**
Destroy Saucer Function
Destroys the saucer
*/
void MainWindow::destroySaucer()
{
  if(sauceship->isActive)
  {
  scene->removeItem(sauceship);
  isSaucer=false;
  sauceship->isActive=false;
  
    if(thinglist->remove(sauceship))
    {
      //std::cout<<"DESTROYING SAUCER"<<std::endl;
      
    }
  }
}

/**
Kill Alien Function
Kills the alien if it is called from mousepressevent in alien class
Gives player 100 points for killing alien
Changes number of aliens killed count
*/
void MainWindow::killAlien()
{
  
  if(alien->isActive)
  {
  scene->removeItem(alien);
  isAlien=false;
  alien->isActive=false;
  error->clear();
  error->insertPlainText("You killed the alien! +100 points");
  
  thinglist->remove(alien);
    
  
  mainscore+=100;
  alienskilled++;
  }
}

/**
Create comet Function
Adds a new comet to the scene randomly 
*/
void MainWindow::createComet()
{
    int random;
    random = rand() %300+10;
    
    if(!thecomet->isActive)
    {
    //std::cout<<"Adding comet"<<std::endl;
    
    thecomet->setXY(450,random);
    scene->addItem(thecomet);
     
    thinglist->push_back(thecomet);
    isComet=true;
    thecomet->isActive=true;
    }
}

/**
Create Meteor Function
Adds a new meteor to the scene randomly
*/
void MainWindow::createMeteor()
{
    int random;
    random = rand() %250+50;
    
    if(!meteorite->isActive)
    {
    //std::cout<<"Adding meteor"<<std::endl;
    
    meteorite->setXY(340,random);
    scene->addItem(meteorite);
     
    thinglist->push_back(meteorite);
    isMeteor=true;
    meteorite->isActive=true;
    }
}

/**
Create Alien Function
Adds a new alien to the scene randomly 
*/
void MainWindow::createAlien()
{
    int randomx;
    randomx=rand()%300+75;
    int randomy;
    randomy = rand() %300+15;
    
    if(!alien->isActive)
    {
    //std::cout<<"Adding alien"<<std::endl;
    
    alien->setXY(randomx,randomy);
    scene->addItem(alien);
    
    alien->isActive=true;
    thinglist->push_back(alien);
    isAlien=true;
    }

}

/**
Create Saucer Function
Adds a new saucer to the scene randomly
*/
void MainWindow::createSaucer()
{
    
    int randomy;
    randomy = rand() %300+15;
    
    if(!sauceship->isActive)
    {
    //std::cout<<"Adding saucer"<<std::endl;
    
    sauceship->setXY(490,randomy);
    scene->addItem(sauceship);
    
    thinglist->push_back(sauceship);
    isSaucer=true;
    sauceship->isActive=true;
    }

}

/**
Key Press Event Function
@argument QKeyEvent
When the up or down arrows are pressed, changes the position of the avatar 
*/
void MainWindow::keyPressEvent(QKeyEvent *e)
{
  switch(e->key())
  {
  case Qt::Key_Up: if(avatar->getY()>0){avatar->setXY(avatar->getX(),avatar->getY()-10);}
  break;
  case Qt::Key_Down: if(avatar->getY()<325){avatar->setXY(avatar->getX(),avatar->getY()+10);}
  break;
  }

}


/**
Start Button Function
Slot connected to start button, launches starting instructions pop up
Launches start game function
Starts the timer
*/
void MainWindow::startButton()
{ 
 
  if(!hasStarted)
  {
  error->clear();
  error->insertPlainText("Start Button was pressed");
  
  startm->setText("Welcome to Chris Hadfield Defends Earth!\n\n Use the arrow keys to move Chris up and down.\n Avoid asteroids, UFOs, and comets.\nUse your mouse to click on and kill aliens. \nFor each alien you kill, you get 100 bonus points.\nWhen you kill three aliens, a heart will appear on the spaceship. Click the spaceship to redeem +1 life. \nYou have three lives");
  startm->exec();
  
  scene->removeItem(bgitem);
  scene->clear();
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

/**
Start Game Function
Adds key elements to the scene to start the game (avatar, background ship), and then
dynamically allocates other objects to be added randomly later. 
*/
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
    
    QString title2("comet.png");
    comet = new QPixmap(title2);
    int random;
    random = rand() %300+10;
    thecomet = new Comet(comet,450,random,this);
    
    QString title3("saucer.png");
    sauce = new QPixmap(title3);
    int randomys;
    randomys = rand() %300+15;
    sauceship = new Saucer(sauce,490,randomys,this);
    
    QString title4("a1.png");
    ali = new QPixmap(title4);
    int randomx;
    randomx=rand()%300+75;
    int randomy;
    randomy = rand() %300+15;
    alien = new Alien(ali,randomx,randomy,this);
    
    QString title5("asteroid.png");
    met = new QPixmap(title5);
    int random2;
    random2 = rand() %250+50;
    meteorite = new Meteor(met,350,random2,this);
    
    QString title6("heart.png");
    hear=new QPixmap(title6);
    heart=new QGraphicsPixmapItem(*hear);
    heart->setX(50);
    heart->setY(335);
    
}
 
/**
Pause Button Function
Pauses the game 
*/
void MainWindow::pauseb() 
{
   
        if(timer->isActive())
	{
	  timer->stop();
	  pause->setText("Resume");
	  error->clear();
          error->insertPlainText("Game paused...");
	}

	else if(!timer->isActive())
	{
	  timer->start();
	  pause->setText("Pause");
	  error->clear();
          error->insertPlainText("Game resumed!");
	}
   
   
  
}

/**
Redeem Life Function
Allows the user to press the spaceship to redeem a life when he/she has killed three aliens
*/
void MainWindow::redeemLife()
{
  if(alienskilled>0 && alienskilled%3==0)
  {
    QString s;
    livesleft++;
    livesbox->clear();
    livesbox->insertPlainText(s.setNum(livesleft));
    alienskilled=0;
    scene->removeItem(heart);
    heartshowing=false;
  } 
}

/**
MainWindow Constructor Function

This function creates the entire GUI and game. It dynamically allocates the necessary QT elements,
brings in all of the QPixmap items, asks the user for name input, connects buttons, etc.
*/
MainWindow::MainWindow()  {
    
  inputname= new QInputDialog;
  bool ok=false;
  playername = inputname->getText(this, tr("QInputDialog::getText()"),
                                        tr("User name:"), QLineEdit::Normal,
                                        tr("Type your name here"), &ok);
  if(ok){
    window= new QWidget;
    

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
   
   
                                         
    
    tbox1= new QLabel("Welcome "+ playername); 
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
    livesbox->setMaximumWidth(60);
    
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
   
   heartshowing=false;
   
   livesleft=3;
   hasStarted=false;
   alienskilled=0;
   
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
  
    delete scene;
    delete view;
    delete timer;
    delete start;
    delete quit;
    delete pause;
    delete window;
    delete tbox1;
    delete error;
    delete livesbox;
    delete scorebox;
    
    delete horlay;
    delete layout;
    delete horlay2;
    delete horlay3;
    delete horlay4;
    delete horlay5;
    
    /**Labels*/
    delete lives;
    delete score;
    
    /**Images*/
    delete bground;
    delete bgitem;
    
    delete space;
    delete space1;
    
    delete chris;
    delete avatar;
    
    delete comet;
    delete thecomet;
    
    delete ship;
    delete spaceship;
    
    delete ali;
    delete alien;
    
    delete sauce;
    delete sauceship;
    
    delete met;
    delete meteorite;

    delete thinglist;
    
    delete startm;
    delete inputname;
    
    delete gameo;
    delete gameover;
    
    delete hear;
    delete heart;
    
}

