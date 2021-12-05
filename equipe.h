#include <string>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QSqlDatabase>
#include "sport.h"
#ifndef EQUIPE_H
#define EQUIPE_H


class Equipe
{
    int idE,points;
    QString nomE,typeE,pays,sportE;

public:
    Equipe();
    Equipe(int,int,QString,QString,QString,QString);

    int getIDE();
    QString getNom();
    QString getType();
    QString getPays();
    QString getSport();
    int getPoints();

    void setIDE(int idE);
    void setNom(QString ne);
    void setType(QString te);
    void setSport(QString se);
    void setPays(QString pe);
    void setPoints(int points);

    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * tri();
    bool supprimer(int);
    bool modifier(int);
};

#endif // EQUIPE_H
