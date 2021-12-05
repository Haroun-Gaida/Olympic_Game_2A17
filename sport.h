#ifndef SPORT_H
#define SPORT_H
#include <string>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QSqlDatabase>

class Sport
{
    QString nom, type,etat,dateAjout,dateDebut;
    int id;
public:
    Sport();
    Sport(int,QString,QString,QString,QString,QString);

    QString getNom();
    QString getType();
    QString getEtat();
    QString getDateAjout();
    QString getDateDebut();
    int getID();

    void setNom(QString n);
    void setEtat(QString e);
    void setCategorie(QString t);
    void setDateAjout(QString d);
    void setDateDebut(QString de);
    void setID(int id);

    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * planning();
    bool supprimer(int);
    bool modifier(int);
};

#endif // SPORT_H
