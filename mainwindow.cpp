#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"etudiant.h"
#include"connection.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Etmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    int ID=ui->le_id->text().toInt();
    QString NOM=ui->le_nom->text();
    QString PRENOM=ui->le_prenom->text();
    QString DICIPLINE=ui->le1->text();
    QString FORFAIT=ui->le2->text();
    QString TESTD=ui->le3->text();

    SPORTIF s(ID,NOM,PRENOM,DICIPLINE,FORFAIT,TESTD);
    bool test=s.ajouter();
    if(test)
    {
        ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("database is open "),QObject::tr("connection successful.\n"
                                                                                      "click cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("data is not open"),QObject::tr("connection failed.\n"
                                                                                  "click cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_clicked()
{
int ID=ui->lineEdit_4->text().toInt();
bool test=Etmp.supprimer(ID);
if(test)
{
    ui->tableView->setModel(Etmp.afficher());

    QMessageBox::information(nullptr,QObject::tr("database is open "),QObject::tr("connection successful.\n"
                                                                                  "click cancel to exit."),QMessageBox::Cancel);
}
else
    QMessageBox::critical(nullptr,QObject::tr("data is not open"),QObject::tr("connection failed.\n"
                                                                              "click cancel to exit."),QMessageBox::Cancel);
}


void MainWindow::on_pushButton_3_clicked()
{
    int ID =ui->lineEdit->text().toInt();
       QString NOM=ui->lineEdit_2->text();
       QString PRENOM=ui->lineEdit_3->text();
       QString DICIPLINE=ui->lineEdit_5->text();
       QString TESTD=ui->lineEdit_6->text();
       QString FORFAIT =ui->lineEdit_7->text();
       SPORTIF a(ID,NOM,PRENOM,DICIPLINE,FORFAIT,TESTD);
     bool test=a.modifier(ID);
     if(test)
     {
         ui->tableView->setModel(Etmp.afficher());

         QMessageBox::information(nullptr,QObject::tr("database is open "),QObject::tr("connection successful.\n"
                                                                                       "click cancel to exit."),QMessageBox::Cancel);
     }
     else
         QMessageBox::critical(nullptr,QObject::tr("data is not open"),QObject::tr("connection failed.\n"
                                                                                   "click cancel to exit."),QMessageBox::Cancel);
}

