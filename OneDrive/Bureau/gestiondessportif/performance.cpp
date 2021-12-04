#include "performance.h"

PERFORMANCE::PERFORMANCE(int id,int score,QString nom, QString prenom)
{


        this->ID=id;
        this->SCORE=score;

        this->NOM=nom;
        this->PRENOM=prenom;



}
bool PERFORMANCE::ajouter()
{
QSqlQuery query;
QString res= QString::number(ID);
query.prepare("INSERT INTO PERFORMANCE(ID,NOM,PRENOM,SCORE)""VALUES(:id,:n,:P,:sc)");
query.bindValue(0,res);
query.bindValue(1,NOM);
query.bindValue(2,PRENOM);
query.bindValue(3,SCORE);
return query.exec();

}
QSqlQueryModel*PERFORMANCE::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from PERFORMANCE");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));//hh
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("SCORE"));
return model;

}
bool PERFORMANCE::modifier(int id)
{
     QSqlQuery query;
     QString r1= QString::number(id);

    query.prepare("UPDATE PERFORMANCE SET ID=:id ,NOM=:n,PRENOM=:P,SCORE=:sc WHERE ID=:id");
    query.bindValue(":id",r1);
    query.bindValue(1,NOM);
    query.bindValue(2,PRENOM);
    query.bindValue(3,SCORE);
    return query.exec();
}
