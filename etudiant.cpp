#include "etudiant.h"

SPORTIF::SPORTIF(int id,QString nom, QString prenom,QString discipline,QString forfait,QString testd)
{
    this->ID=id;
    this->NOM=nom;
    this->PRENOM=prenom;
    this->DISCIPLINE=discipline;
    this->FORFAIT=forfait;
    this->TESTD=testd;


}
bool SPORTIF::ajouter()
{
QSqlQuery query;
QString res= QString::number(ID);
query.prepare("INSERT INTO SPORTIF(ID,NOM,PRENOM,DISCIPLINE,TEST_DOPAGE,FORFAIT)""VALUES(:id,:n,:P,:dp,:d,:f)");
query.bindValue(0,res);
query.bindValue(1,NOM);
query.bindValue(2,PRENOM);
query.bindValue(3,DISCIPLINE);
query.bindValue(4,TESTD);
query.bindValue(5,FORFAIT);


return query.exec();
}

bool SPORTIF::supprimer(int id)
{
QSqlQuery query;
QString res=QString::number(id);
query.prepare("delete from SPORTIF where ID= :id");
query.bindValue(":id",res);
return query.exec();
}
QSqlQueryModel*SPORTIF::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from SPORTIF");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("DISCIPLINE"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("TEST_DOPAGE"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("FORFAIT"));
return model;
}
bool SPORTIF::modifier(int id)
{
     QSqlQuery query;
     QString r1= QString::number(id);

    query.prepare("UPDATE SPORTIF SET ID=:id ,NOM=:n,PRENOM=:P,DISCIPLINE=:dp,TEST_DOPAGE=:d,FORFAIT=:f WHERE ID=:id");
    query.bindValue(":id",r1);
    query.bindValue(1,NOM);
    query.bindValue(2,PRENOM);
    query.bindValue(3,DISCIPLINE);
    query.bindValue(4,TESTD);
    query.bindValue(5,FORFAIT);
    return query.exec();

}

