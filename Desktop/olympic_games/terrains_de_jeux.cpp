#include "terrains_de_jeux.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>

terrains_de_jeux::terrains_de_jeux()
{
  nom=" "; coordonnee=" ";etat="";

}
terrains_de_jeux::terrains_de_jeux(QString nom,QString coordonnee,QString etat)
{this->nom=nom; this->coordonnee=coordonnee;this->etat=etat;}
QString terrains_de_jeux::getnom(){return nom;}
QString terrains_de_jeux::getcoordonnee(){return coordonnee;};
QString terrains_de_jeux::getetat(){return etat;};

void terrains_de_jeux::setnom(QString nom){this->nom=nom;};
void terrains_de_jeux::setcoordonnee(QString coordonnee){this->coordonnee=coordonnee;};
void terrains_de_jeux::setetat(QString etat){this->etat=etat;};
bool terrains_de_jeux::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO terrain_de_jeux (nom, coordonnee, etat) "
                  "VALUES (:forename, :surname, :etat)");

    query.bindValue(":forename", nom);
    query.bindValue(":surname", coordonnee);
    query.bindValue(":etat",etat);

    return query.exec();
  }

    bool terrains_de_jeux::supprimer(QString nom)
    {
      QSqlQuery q ;
      q.exec("SELECT * FROM terrain_de_jeux");
      while(q.next())
      {
          if (q.value(0) == nom)
          {
      QSqlQuery query;

      query.prepare("Delete from terrain_de_jeux where nom=:nom");
      query.bindValue(0,nom);


      return query.exec();}

}
      return false;
    }

    bool terrains_de_jeux::modifier(int a, QString val)
    {
      QSqlQuery query;

      query.prepare("UPDATE terrains_de_jeux set nom =:nom where  =:row");
              query.bindValue(":nom", val);
              query.bindValue(":row",a);


      return query.exec();


    }


  QSqlQueryModel* terrains_de_jeux::afficher()
  {
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT*  FROM terrain_de_jeux");

          model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("coordonnee"));
          model->setHeaderData(2,Qt::Horizontal, QObject::tr("etat"));
    return model;
  }
  QSqlQueryModel * terrains_de_jeux::recherche3(QString etat)
  {
      QSqlQueryModel *mqy=new::QSqlQueryModel;
                 mqy->setQuery("select * from  terrain_de_jeux where etat like '%"+etat+"%'");
                 return mqy;
  }
