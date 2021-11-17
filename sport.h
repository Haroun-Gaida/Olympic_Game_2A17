#ifndef SPORT_H
#define SPORT_H
#include <string>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QSqlDatabase>

class Sport
{
    QString nom, type,etat,dateAjout;
    int id;
public:
    Sport();
    Sport(int,QString,QString,QString,QString);

    QString getNom();
    QString getType();
    QString getEtat();
    QString getDateAjout();
    int getID();

    void setNom(QString n);
    void setEtat(QString e);
    void setCategorie(QString t);
    void setDateAjout(QString d);
    void setID(int id);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
};

#endif // SPORT_H
