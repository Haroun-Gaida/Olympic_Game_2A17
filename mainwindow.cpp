#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logement.h"
#include <QMessageBox>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_logement->setModel(l.afficher());



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bouajouter_clicked()
{
QString nom=ui->le_nom->text();
QString coordonnee=ui->la_coordonnee->text();



    logement l(nom,coordonnee);
    bool test = l.ajouter();

        if(test)
        {   ui->tab_logement->setModel(l.afficher());

            QMessageBox::information(nullptr, QObject::tr("OK"),
                        QObject::tr("Ajout effectué.\n"
                                    "Click Ok to exit."), QMessageBox::Ok);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("Ajout non effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
    logement l1; l1.setnom(ui->l2nomsuppr->text());
    bool test=l1.supprimer(l1.getnom());
    QMessageBox msgBox;
    if(test)
      { msgBox.setText("suppression avec succes.");
        ui->tab_logement->setModel(l.afficher());
         }
    else
             msgBox.setText("Echec de suppression!");
       msgBox.exec();}



void MainWindow::on_pushButtonmodifier_clicked()
{
 logement l;
 bool test=l.modifier(1,ui->editnom->text());
 QMessageBox msgBox;
     if(test)
     {
        ui->tab_logement->setModel(l.afficher());
         msgBox.setText("Modification avec succes!");
     }
     else
     {
         msgBox.setText("Echec de modification");

     }
     msgBox.exec();
 }



