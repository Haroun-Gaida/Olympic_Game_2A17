#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matchs.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QDate>
#include <QDateEdit>
#include <QDateTimeEdit>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_etudiant->setModel(Etmp.afficher());
    ui->tabmatch->setModel(Etmp.tri());
    ui->le_score->setValidator(new QIntValidator(0,999999,this));
     ui->le_num->setValidator(new QIntValidator(0,999999,this));
     QDate date = QDate::currentDate();
      ui->dateEdit->setDate(date);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int score=ui->le_score->text().toInt();
    QString equipe1=ui->le_nom->text();
    QString equipe2=ui->le_prenom->text();
    QString discpline=ui->le_discpline->text();
    int nummatch=ui->le_num->text().toInt();
    QString temps=ui->le_temps->text();
    QDate date=ui->dateEdit->date();



    Etudiant E(score,equipe1,equipe2,discpline,nummatch,temps,date);
    bool test=E.ajouter();
        if(test)
        {
              ui->tab_etudiant->setModel(Etmp.afficher());
               ui->tabmatch->setModel(Etmp.tri());
               ui->tableView_2->setModel(Etmp.tri2());
            QMessageBox::information(nullptr,QObject::tr("ok"),
                    QObject::tr("ajout effectué\n""click concel to exit."),QMessageBox::Cancel);
        }
            else
                QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                      QObject::tr("ajout non effectué.\n""click cancel to exit."),QMessageBox::Cancel);

}

void MainWindow::on_pushButton_2_clicked()
{
      ui->tab_etudiant->setModel(Etmp.afficher());
       ui->tabmatch->setModel(Etmp.tri());
 int nummatch=ui->lineEdit->text().toInt();
 bool test= Etmp.supprimer(nummatch);
 if(test)
 {
       ui->tab_etudiant->setModel(Etmp.afficher());
        ui->tabmatch->setModel(Etmp.tri());
     QMessageBox::information(nullptr,QObject::tr("ok"),
             QObject::tr("supp effectué\n""click concel to exit."),QMessageBox::Cancel);
 }
     else
         QMessageBox::critical(nullptr,QObject::tr("not ok"),
                               QObject::tr("supp non effectué.\n""click cancel to exit."),QMessageBox::Cancel);

}





void MainWindow::on_pushButton_6_clicked()
{

    int score=ui->le_score_2->text().toInt();
    QString equipe1=ui->le_nom_2->text();
    QString equipe2=ui->le_prenom_2->text();
    QString discpline=ui->le_discpline_2->text();
    int nummatch=ui->le_num_2->text().toInt();
    QString temps=ui->le_temps_2->text();
    QDate date=ui->dateEdit->date();

    Etudiant E(score,equipe1,equipe2,discpline,nummatch,temps,date);
    bool test=E.editer();
    if(test)
    {
          ui->tab_etudiant->setModel(Etmp.afficher());
           ui->tabmatch->setModel(Etmp.tri());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("ajout effectué\n""click concel to exit."),QMessageBox::Cancel);
    }
        else
            QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                  QObject::tr("ajout non effectué.\n""click cancel to exit."),QMessageBox::Cancel);

}



void MainWindow::on_dateEdit_userDateChanged(const QDate &date)
{

     ui->dateEdit->setDate(date);
}


void MainWindow::on_pushButton_3_clicked()
{

            int e1=ui->le_e1->text().toInt();
            int e2=ui->le_e2->text().toInt();
             QString player=ui->le_player->text();
            int egalite=ui->le_e3->text().toInt();
            int nummatch2=ui->le_num_3->text().toInt();
        Etudiant E1(e1,e2,player,egalite,nummatch2);
        bool test=E1.ajouterp();
        if(test)
        {
ui->tableView->setModel(Etmp.afficherp());

            QMessageBox::information(nullptr,QObject::tr("ok"),
                    QObject::tr("paris effectué\n""click concel to exit."),QMessageBox::Cancel);
        }
            else
                QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                      QObject::tr("paris non effectué.\n""click cancel to exit."),QMessageBox::Cancel);



}

void MainWindow::on_pushButton_4_clicked()
{

 int nummatch2=ui->le_num_3->text().toInt();
bool test= Etmp.supprimerp(nummatch2);
if(test)
{
ui->tableView->setModel(Etmp.afficherp());

    QMessageBox::information(nullptr,QObject::tr("ok"),
            QObject::tr("supp effectué\n""click concel to exit."),QMessageBox::Cancel);
}
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("supp non effectué.\n""click cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_5_clicked()
{
     int id=ui->le_id->text().toInt();
     float prix=ui->le_prix->text().toFloat();
     Etudiant E(id,prix);
      bool test=E.ajouterb();
      if(test)
      {
      ui->tableView_3->setModel(Etmp.afficherb());

          QMessageBox::information(nullptr,QObject::tr("ok"),
                  QObject::tr("ajout effectué\n""click concel to exit."),QMessageBox::Cancel);
      }
          else
              QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                    QObject::tr("ajout non effectué.\n""click cancel to exit."),QMessageBox::Cancel);
}

