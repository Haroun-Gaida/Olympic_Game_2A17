#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connexion C;
   bool test;
       test=C.createConnection();
       MainWindow m;
    MainWindow w;
    w.show();
    return a.exec();
}
