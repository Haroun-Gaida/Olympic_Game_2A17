#include "logement.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>


logement::logement()
{
nom=" "; coordonnee=" ";

}

logement::logement(QString nom,QString coordonnee)
{this->nom=nom; this->coordonnee=coordonnee;}
QString logement::getnom(){return nom;}
QString logement::getcoordonnee(){return coordonnee;};
void logement::setnom(QString nom){this->nom=nom;};
void logement::setcoordonnee(QString coordonnee){this->coordonnee=coordonnee;};

bool logement::ajouter()
{

  QSqlQuery query;

  query.prepare("INSERT INTO logement (nom, coordonnee) "
                "VALUES (:forename, :surname)");

  query.bindValue(":forename", nom);
  query.bindValue(":surname", coordonnee);

  return query.exec();
}

  bool logement::supprimer(QString nom)
  {
    QSqlQuery query;

    query.prepare("Delete from logement where nom=:nom");
    query.bindValue(0,nom);


    return query.exec();


  }
  bool logement::modifier(int a, QString val)
  {
    QSqlQuery query;

    query.prepare("UPDATE logement set nom =:nom where ROWID =:row");
            query.bindValue(":nom", val);
            query.bindValue(":row",a);


    return query.exec();





  }


QSqlQueryModel* logement::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();

        model->setQuery("SELECT*  FROM logement");

        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("coordonnee"));

  return model;
}

