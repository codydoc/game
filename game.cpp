#include <QtGui/QApplication>
#include "mainwindow.h"

/**
@mainpage CSCI 102 PA 5 Game
@section purpose Purpose/Overview
Chris Hadfield Defends Earth Game
@author Cody Rapp
*/

/**Main Function
Creates QApplication and Mainwindow, and then calls show.
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
