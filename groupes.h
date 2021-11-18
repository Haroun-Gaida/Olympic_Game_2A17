ifndef GROUPES_H
#define GROUPES_H
#include <QString>
#include <QSqlQuery>
#include <QDateTime>
#include <QSqlQueryModel>
#include <vector>
#include <QgroupeileDialog>
#include <QDir>
#include <QTextStream>
#include <QPrinter>
#include <QSqlTableModel>
#include <tableprinter.h>
#include "mainwindow.h"

class groupes
{
public:
    groupes();
    groupes(int,QString,int,QString,QString,QString);
     bool ajouter_groupes();
     int getId(){return id_groupe;}
     QString getNom(){return nom_groupe;}
     QString getSport(){return sport_groupe;}
     QString getGendre(){return genre_groupe;}

     QSqlQueryModel * agroupegroupeicher();
     bool supp_groupes(int);
     bool modigroupeier_groupes();
     QSqlQueryModel * rechercher (QString);
     QSqlQueryModel * trier_id();
     QSqlQueryModel * trier_nom_groupe();
     QSqlQueryModel * trier_sport_groupe();

private:
    int id_groupe;
    QString nom_groupe;
    QString sport_groupe;
    QString genre_groupe;

};

#endif // groupes_H
