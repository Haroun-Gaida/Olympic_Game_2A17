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
  { QSqlQuery q ;
    q.exec("SELECT * FROM logement");
    while(q.next())
    {
        if (q.value(0) == nom)
        {
    QSqlQuery query;

    query.prepare("Delete from logement where nom=:nom");
    query.bindValue(0,nom);


    return query.exec();}}
    return false;


  }
  bool logement::modifier(int a, QString val)
  {QSqlQuery q ;
    q.exec("SELECT * FROM logement");
    while(q.next())
    {
        if (q.value(0) == nom)
        {
    QSqlQuery query;

    query.prepare("UPDATE logement where nom=:nom");
            query.bindValue(":nom", val);
            query.bindValue(":row",a);


    return query.exec();}}
    return false;


  }


QSqlQueryModel* logement::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();

        model->setQuery("SELECT*  FROM logement");

        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("coordonnee"));

  return model;
}
QSqlQueryModel * logement::recherche(QString nom)
{
    QSqlQueryModel *mqy=new::QSqlQueryModel;
               mqy->setQuery("select * from  logement where nom like '%"+nom+"%'");
               return mqy;
}
QSqlQueryModel * logement::recherche1(QString coordonnee)
{
    QSqlQueryModel *mqy=new::QSqlQueryModel;
               mqy->setQuery("select * from  logement where coordonnee like '%"+coordonnee+"%'");
               return mqy;
}
QSqlQueryModel *logement::tri()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT*  FROM logement order by nom");
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("coordonnee"));
    return model;

}

