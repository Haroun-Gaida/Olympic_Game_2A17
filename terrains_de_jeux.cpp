#include "terrains_de_jeux.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>

terrains_de_jeux::terrains_de_jeux()
{
  nom=" "; coordonnee=" ";

}
terrains_de_jeux::terrains_de_jeux(QString nom,QString coordonnee)
{this->nom=nom; this->coordonnee=coordonnee;}
QString terrains_de_jeux::getnom(){return nom;}
QString terrains_de_jeux::getcoordonnee(){return coordonnee;};
void terrains_de_jeux::setnom(QString nom){this->nom=nom;};
void terrains_de_jeux::setcoordonnee(QString coordonnee){this->coordonnee=coordonnee;};
bool terrains_de_jeux::ajouter()
{


    QSqlQuery query;

    query.prepare("INSERT INTO terrain_de_jeux (nom, coordonnee) "
                  "VALUES (:forename, :surname)");

    query.bindValue(":forename", nom);
    query.bindValue(":surname", coordonnee);

    return query.exec();
  }

    bool terrains_de_jeux::supprimer(QString nom)
    {
      QSqlQuery query;

      query.prepare("Delete from terrain_de_jeux where nom=:nom");
      query.bindValue(0,nom);


      return query.exec();


    }


  QSqlQueryModel* terrains_de_jeux::afficher()
  {
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT*  FROM terrain_de_jeux");

          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("coordonnee"));

    return model;
  }

