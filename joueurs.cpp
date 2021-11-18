#include "joueurs.h"
#include "connexion.h"
#include <QString>
#include <QSqlQuery>
#include <QDateTime>
#include <QDate>
#include <QSqlQueryModel>
#include <vector>
#include <QDebug>

joueurs::joueurs()
{

   id_f=0;
    nom_f="";
    prenom_f="";
    age_f=0;
    genre_f="";
    date_de_naissance_add_f="";
    sport_f=";"

}

joueurs::joueurs(int id_f, QString nom_f, int prenom_f, QString age_f, QDateTime date_de_naissance_add_f, QString genre_f, QString sport_f)
{

    this->id_f=id_f;
    this->nom_f=nom_f;
    this->prenom_f=prenom_f;
    this->age_f=age_f;
    this->date_de_naissance_add_f=date_de_naissance_add_f;
    this->genre_f=genre_f;
    this->sport_f=sport_f;

}



bool joueurs::ajouter_joueurs()
{
QSqlQuery query;


query.prepare("insert into joueursS(id_f,nom_f,prenom_f,age_f,date_de_naissance_add_f,genre_f,sport_f) values(:id_f,:nom_f,:prenom_f,:age_f,:date_de_naissance_add_f,:genre_f,:sport_f)");

QString res = QString::number(id_f);
QString ress = QString::number(prenom_f);

query.bindValue(":id_f",res);
query.bindValue(":nom_f",nom_f);
query.bindValue(":prenom_f",ress);
query.bindValue(":age_f",age_f);
query.bindValue(":date_de_naissance_add_f",date_de_naissance_add_f);
query.bindValue(":genre_f",genre_f);
query.bindValue(":sport_f",sport_f);


return query.exec();

}

QSqlQueryModel * joueurs::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM joueursS");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_f"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_f"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom_f"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("age_f"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_de_naissance_add_f"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("genre_f"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("sport_f"));
    return model;

}


  bool joueurs::modifier_joueurs()
  {
      //qDebug()<<"is working";

      QSqlQuery query;

      query.prepare("update joueursS set nom_f=:nom_f,prenom_f=:prenom_f,age_f=:age_f,date_de_naissance_add_f=:date_de_naissance_add_f,genre_f=:genre_f,sport_f=:sport_f where id_f=:id_f");

      QString res = QString::number(id_f);
      QString ress = QString::number(prenom_f);

      query.bindValue(":id_f",res);
      query.bindValue(":nom_f",nom_f);
      query.bindValue(":prenom_f",ress);
      query.bindValue(":age_f",age_f);
      query.bindValue(":date_de_naissance_add_f",date_de_naissance_add_f);
      query.bindValue(":genre_f",genre_f);
      query.bindValue(":sport_f",sport_f);
      //qDebug()<<"is done";
      //qDebug()<<res+nom_f+ress+date_de_naissance_add_f.toString();

      return query.exec();
  }


  bool joueurs::supp_joueurs(int id_f)
  {

      QSqlQuery query;
      QString id_f1 = QString::number(id_f);
      query.prepare("Delete from joueursS  where id_f=:id_f1");
      query.bindValue(":id_f1",id_f1);
      return query.exec();

  }

  QSqlQueryModel *joueurs::rechercher(QString rech)
  {
      QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("select * from joueursS where upper(id_f) LIKE upper ('%"+rech+"%') or upper(nom_f) LIKE upper ('%"+rech+"%') or upper(sport_f) LIKE upper ('%"+rech+"%')");


      return model;

  }

  QSqlQueryModel * joueurs::trier_id()
  {
      QSqlQuery *qry=new QSqlQuery();
      QSqlQueryModel *model=new QSqlQueryModel();
      qry->prepare("select * from joueursS order by ID_F ASC");
      qry->exec();
      model->setQuery(*qry);
      return model;
  }
  QSqlQueryModel * joueurs::trier_nom_f()
  {
      QSqlQuery *qry=new QSqlQuery();
      QSqlQueryModel *model=new QSqlQueryModel();
      qry->prepare("select * from joueursS order by nom_f ASC");
      qry->exec();
      model->setQuery(*qry);
      return model;
  }

  QSqlQueryModel * joueurs::trier_specialite()
  {
      QSqlQuery *qry=new QSqlQuery();
      QSqlQueryModel *model=new QSqlQueryModel();
      qry->prepare("select * from joueursS order by genre_f ASC");
      qry->exec();
      model->setQuery(*qry);
      return model;
  }
