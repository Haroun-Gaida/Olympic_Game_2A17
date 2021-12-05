#include "sport.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>

 Sport::Sport()
{
    id=0;
    nom=" ";
    type=" ";
    dateAjout=" ";
    dateDebut=" ";
    etat=" ";
}

 Sport::Sport(int id,QString nom,QString type,QString etat,QString dateAjout,QString dateDebut)
 {
    this->id=id;
    this->nom=nom;
    this->type=type;
    this->etat=etat;
    this->dateAjout=dateAjout;
    this->dateDebut=dateDebut;
 }
 QString Sport::getDateAjout(){return dateAjout;}
 QString Sport::getDateDebut(){return dateDebut;}
 QString Sport::getNom(){return nom;}
 QString Sport::getType(){return type;}
 QString Sport::getEtat(){return etat;}
 int Sport::getID(){return id;}

 void Sport::setNom(QString n){nom=n;}
 void Sport::setEtat(QString e){etat=e;}
 void Sport::setCategorie(QString t){type=t;}
 void Sport::setID(int id){this->id=id;}
 void Sport::setDateAjout(QString d){nom=d;}
 void Sport::setDateDebut(QString de){nom=de;}
bool Sport::ajouter()
{
    QSqlQuery query;
    QString id_string=QString::number(id);
          query.prepare("INSERT INTO SPORT (ID, NOM, TYPE, ETAT, DATEAJOUT,DATEDEBUT)""values (:id, :nom, :type, :etat, :dateAjout, :dateDebut)");
          query.bindValue(":id", id_string);
          query.bindValue(":nom", nom);
          query.bindValue(":type", type);
          query.bindValue(":etat", etat);
          query.bindValue(":dateAjout", dateAjout);
          query.bindValue(":dateDebut", dateDebut);

    return query.exec();
}

QSqlQueryModel * Sport::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel() ;

    model->setQuery("SELECT* FROM SPORT");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("Etat"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("Date d'ajout"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("Date debut"));
    return model;
}

QSqlQueryModel * Sport::planning()
{
    QSqlQueryModel * model=new QSqlQueryModel() ;

    model->setQuery("SELECT nom, dateDebut FROM SPORT ORDER BY DATEDEBUT");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("Nom"));
    //model->setHeaderData(1, Qt::Horizontal,QObject::tr("Identifiant"));
    //model->setHeaderData(2, Qt::Horizontal,QObject::tr("Type"));
    //model->setHeaderData(3, Qt::Horizontal,QObject::tr("Etat"));
    //model->setHeaderData(4, Qt::Horizontal,QObject::tr("Date d'ajout"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("Sports avenir"));
    return model;
}

bool Sport::supprimer(int id)
{
    QSqlQuery query;

          query.prepare("Delete from SPORT where id=:id");
          query.bindValue(0, id);

    return query.exec();
}

bool Sport::modifier(int id)
{
   QSqlQuery query;
   QString S1=QString::number(id);

   query.prepare("UPDATE SPORT SET ID=:id, NOM=:nom, TYPE=:type, ETAT=:etat, DATEAJOUT=:dateAjout, DATEDEBUT=:dateDebut WHERE ID=:id");
   query.bindValue(":id",S1);
   query.bindValue(1, nom);
   query.bindValue(2, type);
   query.bindValue(3, etat);
   query.bindValue(4, dateAjout);
   query.bindValue(5, dateDebut);
return query.exec();

}
