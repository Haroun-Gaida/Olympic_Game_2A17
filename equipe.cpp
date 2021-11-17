#include "equipe.h"
#include "sport.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>

Equipe::Equipe()
{
    idE=0;
    nomE=" ";
    typeE=" ";
    pays=" ";
    sportE=" ";
}

Equipe::Equipe(int idE,QString nomE,QString sportE,QString typeE,QString pays)
{
    this->idE=idE;
    this->nomE=nomE;
    this->typeE=typeE;
    this->pays=pays;
    this->sportE=sportE;
}

int Equipe::getIDE(){return idE;}
QString Equipe::getNom(){return nomE;}
QString Equipe::getType(){return typeE;}
QString Equipe::getPays(){return pays;}
QString Equipe::getSport(){return sportE;}

void Equipe::setIDE(int idE){this->idE=idE;}
void Equipe::setNom(QString ne){nomE=ne;};
void Equipe::setType(QString te){typeE=te;}
void Equipe::setSport(QString se){sportE=se;}
void Equipe::setPays(QString pe){pays=pe;}

bool Equipe::ajouter()
{
    QSqlQuery query;
    QString idE_string=QString::number(idE);
          query.prepare("INSERT INTO EQUIPE (ID, NOM, SPORT, TYPE, PAYS)""values (:idE, :nomE, :sportE, :typeE, :pays)");
          query.bindValue(":idE", idE_string);
          query.bindValue(":nomE", nomE);
          query.bindValue(":sportE", sportE);
          query.bindValue(":typeE", typeE);
          query.bindValue(":pays", pays);

    return query.exec();
}

QSqlQueryModel * Equipe::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel() ;

    model->setQuery("SELECT* FROM EQUIPE");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("SPORT"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("TYPE"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("PAYS"));

    return model;
}

bool Equipe::supprimer(int idE)
{
    QSqlQuery query;

          query.prepare("Delete from EQUIPE where idE=:idE");
          query.bindValue(0, idE);

    return query.exec();
}

bool Equipe::modifier(int idE)
{
   QSqlQuery query;
   QString E1=QString::number(idE);

   query.prepare("UPDATE EQUIPE SET ID=:idE, NOM=:nomE, SPORT=:sportE, TYPE=:typeE, PAYS=:pays WHERE ID=:idE");
   query.bindValue(":idE", E1);
   query.bindValue(1, nomE);
   query.bindValue(2, sportE);
   query.bindValue(3, typeE);
   query.bindValue(4, pays);

return query.exec();

}
