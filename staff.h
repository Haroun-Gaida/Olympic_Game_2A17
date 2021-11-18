#ifndef STAFF_H
#define STAFF_H
#include <QString>
#include <QSqlQuery>
#include <QDateTime>
#include <QSqlQueryModel>
#include <vector>
#include <QFileDialog>
#include <QDir>
#include <QTextStream>
//#include <QPrinter>
#include <QSqlTableModel>
//#include <tableprinter.h>
//#include "mainwindow.h"

class staff
{
public:
    staff();
    staff(int,QString,int,QString,QDateTime,QString,QString);
     bool ajouter_staff();
     int getId(){return id_s;}
     int getTel(){return tel_s;}
     QString getNom(){return nom;}
     QString getPreNom(){return prenom;}
     QString getAdresse(){return adresse_add_s;}
     QString getEmail(){return email_s;}

     QSqlQueryModel * afficher();
     bool supp_staff(int);
     bool modifier_staff();
     QSqlQueryModel * rechercher (QString);
     QSqlQueryModel * trier_id();
     QSqlQueryModel * trier_nom();
     QSqlQueryModel * trier_specialite();

private:
    int id_s;
    QString nom;
    QString prenom;
    int tel_s;
    QString email_s;
    QDateTime date_add_s;
    QString specialite_s;
    QString adresse_add_s;

};

#endif // STAFF_H
