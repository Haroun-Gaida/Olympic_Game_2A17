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
    etat=" ";
}

 Sport::Sport(int id,QString nom,QString type,QString etat,QString dateAjout)
 {
    this->id=id;
    this->nom=nom;
    this->type=type;
    this->etat=etat;
    this->dateAjout=dateAjout;
 }
 QString Sport::getDateAjout(){return dateAjout;}
 QString Sport::getNom(){return nom;}
 QString Sport::getType(){return type;}
 QString Sport::getEtat(){return etat;}
 int Sport::getID(){return id;}

 void Sport::setNom(QString n){nom=n;}
 void Sport::setEtat(QString e){etat=e;}
 void Sport::setCategorie(QString t){type=t;}
 void Sport::setID(int id){this->id=id;}
 void Sport::setDateAjout(QString d){nom=d;}
bool Sport::ajouter()
{
    QSqlQuery query;
    QString id_string=QString::number(id);
          query.prepare("INSERT INTO SPORT (ID, NOM, TYPE, ETAT, DATEAJOUT)""values (:id, :nom, :type, :etat, :dateAjout)");
          query.bindValue(":id", id_string);
          query.bindValue(":nom", nom);
          query.bindValue(":type", type);
          query.bindValue(":etat", etat);
          query.bindValue(":dateAjout", dateAjout);

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

   query.prepare("UPDATE SPORT SET ID=:id, NOM=:nom, TYPE=:type, ETAT=:etat, DATEAJOUT=:dateAjout WHERE ID=:id");
   query.bindValue(":id",S1);
   query.bindValue(1, nom);
   query.bindValue(2, type);
   query.bindValue(3, etat);
   query.bindValue(4, dateAjout);

return query.exec();

}
