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
    int idE;
    QString nomE,typeE,pays,sportE;

public:
    Equipe();
    Equipe(int,QString,QString,QString,QString);

    int getIDE();
    QString getNom();
    QString getType();
    QString getPays();
    QString getSport();

    void setIDE(int idE);
    void setNom(QString ne);
    void setType(QString te);
    void setSport(QString se);
    void setPays(QString pe);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
};

#endif // EQUIPE_H
