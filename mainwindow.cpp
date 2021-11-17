#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sport.h"
#include "equipe.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_ID->setValidator(new QIntValidator(0,999999, this));
    ui->tab_sport->setModel(S.afficher());
    ui->le_ID_equipe->setValidator(new QIntValidator(0,999999, this));
    ui->tab_equipe->setModel(E.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_confirmer_clicked()
{
    int id=ui->le_ID->text().toUInt();
    QString nom=ui->le_nom->text();
    QString type=ui->le_type->text();
    QString etat=ui->le_etat->text();
    QString dateAjout=ui->le_dateAjout->text();
    Sport S(id,nom,type,etat,dateAjout);

    bool test=S.ajouter();
    QMessageBox msgBox;
    if(test)
        msgBox.setText("Ajout confirmé !");
    else
        msgBox.setText("Echec de l'ajout !");
        msgBox.exec();
}

void MainWindow::on_supprimer_clicked()
{
    Sport S1; S1.setID(ui->le_idSport->text().toUInt());
    bool test=S1.supprimer(S1.getID());
    QMessageBox msgBox;
    if(test)
        msgBox.setText("Suppression confirmée !");
    else
        msgBox.setText("Echec de la suppression !");
        msgBox.exec();
}

void MainWindow::on_modifier_pushutton_clicked()
{
    QString nom=ui->modifier_nom->text();
    int id=ui->modifier_id->text().toUInt();
    QString type=ui->modifier_type->text();
    QString etat=ui->modifier_etat->text();
    QString dateAjout=ui->modifier_date->text();
    Sport S(id,nom,type,etat,dateAjout);

    bool test=S.modifier(id);
    QMessageBox msgBox;
    if(test)
    {
        ui->tab_sport->setModel(S.afficher());
        msgBox.setText("modification confirmée !");
    }
    else
        msgBox.setText("Echec de la modification !");
        msgBox.exec();
}

void MainWindow::on_confirmer_equipe_clicked()//Ajouter une equipe
{
    int idE=ui->le_ID_equipe->text().toUInt();
    QString nomE=ui->le_nom_equipe->text();
    QString typeE=ui->le_type_equipe->text();
    QString pays=ui->le_pays_equipe->text();
    QString sportE=ui->le_sport_equipe->text();
    Equipe E(idE,nomE,typeE,pays,sportE);

    bool test=E.ajouter();
    QMessageBox msgBox;
    if(test)
        msgBox.setText("Ajout confirmé !");
    else
        msgBox.setText("Echec de l'ajout !");
        msgBox.exec();
}

void MainWindow::on_supprimer_Equipe_clicked()
{
    Equipe E1; E1.setIDE(ui->le_idEquipe_supp->text().toUInt());
    bool test=E1.supprimer(E1.getIDE());
    QMessageBox msgBox;
    if(test)
        msgBox.setText("Suppression confirmée !");
    else
        msgBox.setText("Echec de la suppression !");
        msgBox.exec();
}

void MainWindow::on_modifier_equipe_clicked()
{
    int idE=ui->le_ID_equipe->text().toUInt();
    QString nomE=ui->le_nom_equipe->text();
    QString sportE=ui->le_sport_equipe->text();
    QString typeE=ui->le_type_equipe->text();
    QString pays=ui->le_pays_equipe->text();
    Equipe E(idE,nomE,sportE,typeE,pays);

    bool test=E.modifier(idE);
    QMessageBox msgBox;
    if(test)
    {
        ui->tab_equipe->setModel(E.afficher());
        msgBox.setText("modification confirmée !");
    }
    else
        msgBox.setText("Echec de la modification !");
        msgBox.exec();
}
