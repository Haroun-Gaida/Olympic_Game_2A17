#include "staff.h"
#include "connexion.h"
#include <QString>
#include <QSqlQuery>
#include <QDateTime>
#include <QDate>
#include <QSqlQueryModel>
#include <vector>
#include <QDebug>

staff::staff()
{

    id_s=0;
    nom="";
    prenom="";
    tel_s=0;
    email_s="";
    specialite_s="";
    adresse_add_s="";

}

staff::staff(int id_s, QString nom, QString prenom, int tel_s, QString email_s, QDateTime date_add_s, QString specialite_s, QString adresse_add_s)
{

    this->id_s=id_s;
    this->nom=nom;
    this->prenom=prenom;
    this->tel_s=tel_s;
    this->email_s=email_s;
    this->date_add_s=date_add_s;
    this->specialite_s=specialite_s;
    this->adresse_add_s=adresse_add_s;

}



bool staff::ajouter_staff()
{
QSqlQuery query;


query.prepare("insert into staffS(id_s,nom,prenom,tel_s,email_s,date_add_s,specialite_s,adresse_add_s) values(:id_s,:nom,:prenom,:tel_s,:email_s,:date_add_s,:specialite_s,:adresse_add_s)");

QString res = QString::number(id_s);
QString ress = QString::number(tel_s);

query.bindValue(":id_s",res);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":tel_s",ress);
query.bindValue(":email_s",email_s);
query.bindValue(":date_add_s",date_add_s);
query.bindValue(":specialite_s",specialite_s);
query.bindValue(":adresse_add_s",adresse_add_s);


return query.exec();

}

QSqlQueryModel * staff::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM staffS");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_s"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("tel_s"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("email_s"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("date_add_s"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("specialite_s"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("adresse_add_s"));
    return model;

}


  bool staff::modifier_staff()
  {
      //qDebug()<<"is working";

      QSqlQuery query;

      query.prepare("update staffS set nom=:nom,tel_s=:tel_s,email_s=:email_s,date_add_s=:date_add_s,specialite_s=:specialite_s,adresse_add_s=:adresse_add_s where id_s=:id_s");

      QString res = QString::number(id_s);
      QString ress = QString::number(tel_s);

      query.bindValue(":id_s",res);
      query.bindValue(":nom",nom);
      query.bindValue(":prenom",prenom);
      query.bindValue(":tel_s",ress);
      query.bindValue(":email_s",email_s);
      query.bindValue(":date_add_s",date_add_s);
      query.bindValue(":specialite_s",specialite_s);
      query.bindValue(":adresse_add_s",adresse_add_s);
      //qDebug()<<"is done";
      //qDebug()<<res+nom+prenom+ress+date_add_s.toString();

      return query.exec();
  }


  bool staff::supp_staff(int id_s)
  {

      QSqlQuery query;
      QString id_s1 = QString::number(id_s);
      query.prepare("Delete from staffS  where id_s=:id_s1");
      query.bindValue(":id_s1",id_s1);
      return query.exec();

  }

  QSqlQueryModel *staff::rechercher(QString rech)
  {
      QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("select * from staffS where upper(id_s) LIKE upper ('%"+rech+"%') or upper(nom) LIKE upper ('%"+rech+"%') or upper(adresse_add_s) LIKE upper ('%"+rech+"%')");


      return model;

  }

  QSqlQueryModel * staff::trier_id()
  {
      QSqlQuery *qry=new QSqlQuery();
      QSqlQueryModel *model=new QSqlQueryModel();
      qry->prepare("select * from staffS order by ID_s ASC");
      qry->exec();
      model->setQuery(*qry);
      return model;
  }
  QSqlQueryModel * staff::trier_nom()
  {
      QSqlQuery *qry=new QSqlQuery();
      QSqlQueryModel *model=new QSqlQueryModel();
      qry->prepare("select * from staffS order by NOM ASC");
      qry->exec();
      model->setQuery(*qry);
      return model;
  }

  QSqlQueryModel * staff::trier_specialite()
  {
      QSqlQuery *qry=new QSqlQuery();
      QSqlQueryModel *model=new QSqlQueryModel();
      qry->prepare("select * from staffS order by SPECIALITE_s ASC");
      qry->exec();
      model->setQuery(*qry);
      return model;
  }
