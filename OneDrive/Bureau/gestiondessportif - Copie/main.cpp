#include "mainwindow.h"
#include<QMessageBox>
#include"connection.h"
#include <QApplication>
#include <QDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connection c;
    bool test=c.createconnection();
    MainWindow w;

    if(test)
    {
    w.show();

    QMessageBox::information(nullptr,QObject::tr("database is open "),QObject::tr("connection successful.\n"
                                                                                  "click cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("data is not open"),QObject::tr("connection failed.\n"
                                                                                  "click cancel to exit."),QMessageBox::Cancel);

    return a.exec();
}

