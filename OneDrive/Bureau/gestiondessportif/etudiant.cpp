#include "etudiant.h"

SPORTIF::SPORTIF(int id,int score,QString nom, QString prenom,QString discipline,QString forfait,QString testd,QString email,QString nationalite)
{
    this->ID=id;
    this->SCORE=score;

    this->NOM=nom;
    this->PRENOM=prenom;
    this->DISCIPLINE=discipline;
    this->FORFAIT=forfait;
    this->TESTD=testd;
    this->EMAIL=email;
this ->NATIONALITE=nationalite;

}
bool SPORTIF::ajouter()
{
QSqlQuery query;
QString res= QString::number(ID);
query.prepare("INSERT INTO SPORTIF(ID,NOM,PRENOM,DISCIPLINE,TEST_DOPAGE,FORFAIT,EMAIL,SCORE,NATIONALITÉ)""VALUES(:id,:n,:P,:dp,:d,:f,:em,:sc,:na)");
query.bindValue(0,res);
query.bindValue(1,NOM);
query.bindValue(2,PRENOM);
query.bindValue(3,DISCIPLINE);
query.bindValue(4,TESTD);
query.bindValue(5,FORFAIT);
query.bindValue(6,EMAIL);
query.bindValue(7,SCORE);
query.bindValue(8,NATIONALITE);





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
model->setHeaderData(6,Qt::Horizontal,QObject::tr("EMAIL"));
model->setHeaderData(7,Qt::Horizontal,QObject::tr("SCORE"));
model->setHeaderData(8,Qt::Horizontal,QObject::tr("NATIONALITÉ"));


return model;
}
bool SPORTIF::modifier(int id)
{
     QSqlQuery query;
     QString r1= QString::number(id);

    query.prepare("UPDATE SPORTIF SET ID=:id ,NOM=:n,PRENOM=:P,DISCIPLINE=:dp,TEST_DOPAGE=:d,FORFAIT=:f,EMAIL=:em,SCORE=:sc,NATIONALITÉ=:na WHERE ID=:id");
    query.bindValue(":id",r1);
    query.bindValue(1,NOM);
    query.bindValue(2,PRENOM);
    query.bindValue(3,DISCIPLINE);
    query.bindValue(4,TESTD);
    query.bindValue(5,FORFAIT);
    query.bindValue(6,EMAIL);
    query.bindValue(7,SCORE);
    query.bindValue(8,NATIONALITE);



    return query.exec();

}
QSqlQueryModel * SPORTIF::statistic()
{
    QSqlQueryModel * model=new QSqlQueryModel();
       model->setQuery("select NATIONALITÉ,(count(NATIONALITÉ)*100/ (select count(*)from SPORTIF)) as pourcentage from SPORTIF group by NATIONALITÉ");
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("NATIONALITÉ"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("percentage"));

       return model;


}
QSqlQueryModel* SPORTIF::tri()
{
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT* FROM SPORTIF ORDER BY SCORE  ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DISCIPLINE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("TEST_DOPAGE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("FORFAIT"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("EMAIL"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("SCORE"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("NATIONALITÉ"));




    return model;
}


