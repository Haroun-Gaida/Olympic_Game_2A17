 #include "etudiant.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QObject>
#include <QDate>
Etudiant::Etudiant()
{
score=0; equipe1="" ;equipe2="";  discpline="" ;nummatch=0 ;temps=""; e1=0; e2=0; egalite=0; player="";nummatch2=0;
}


bool Etudiant::ajouter()
{
            QSqlQuery query;
QString res=QString::number(score);
QString res2=QString::number(nummatch);

                  query.prepare("INSERT INTO GMATCHS (EQUIPE1,EQUIPE2,SCORE,DISCPLINE,NUMMATCH,TEMPS,DATEM) "
                                "VALUES (:forename, :surname,:score,:discpline,:nummatch,:temps,:date)");

                  query.bindValue(0,equipe1);
                  query.bindValue(1,equipe2);
                  query.bindValue(2,res);
                  query.bindValue(3,discpline);
                  query.bindValue(4,res2);
                  query.bindValue(5,temps);
                  query.bindValue(6,date);
                 return query.exec();

}
bool Etudiant::supprimer(int nummatch )
{
 QSqlQuery query;
 QString res2=QString::number(nummatch);
 query.prepare("DELETE FROM GMATCHS WHERE NUMMATCH= :nummatch");
 query.bindValue(":nummatch",res2);
 return query.exec();
}
QSqlQueryModel * Etudiant::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel;
          model->setQuery("SELECT * from GMATCHS ");
          model->setHeaderData(0, Qt::Horizontal,QObject::tr("EQUIPE1"));
          model->setHeaderData(1, Qt::Horizontal,QObject:: tr("EQUIPE2"));
          model->setHeaderData(7, Qt::Horizontal,QObject:: tr("SCORE"));
          model->setHeaderData(7, Qt::Horizontal,QObject:: tr("DISCPLINE"));
           model->setHeaderData(7, Qt::Horizontal,QObject:: tr("NUMMATCH"));
           model->setHeaderData(7, Qt::Horizontal,QObject:: tr("TEMPS"));
              model->setHeaderData(7, Qt::Horizontal,QObject:: tr("DATEM"));
 return model;
}

bool Etudiant::editer(){
    QSqlQuery query;
    QString r1=QString::number(score);
    QString r=QString::number(nummatch);
    query.prepare("UPDATE GMATCHS SET EQUIPE1=:forename,EQUIPE2=:surname,SCORE=:score,DISCPLINE=:discpline,NUMMATCH=:nummatch,TEMPS=:temps,DATEM=:date WHERE NUMMATCH=:nummatch");
    query.bindValue(0,equipe1);
    query.bindValue(1,equipe2);
    query.bindValue(":score",r1);
    query.bindValue(3,discpline);
    query.bindValue(":nummatch",r);
    query.bindValue(5,temps);
    query.bindValue(6,date);

    return query.exec();
}
QSqlQueryModel* Etudiant::tri()
{
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT* FROM GMATCHS ORDER BY DATEM");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("EQUIPE1"));
    model->setHeaderData(1, Qt::Horizontal,QObject:: tr("EQUIPE2"));
    model->setHeaderData(7, Qt::Horizontal,QObject:: tr("SCORE"));
    model->setHeaderData(7, Qt::Horizontal,QObject:: tr("DISCPLINE"));
    model->setHeaderData(7, Qt::Horizontal,QObject:: tr("NUMMATCH"));
    model->setHeaderData(7, Qt::Horizontal,QObject:: tr("TEMPS"));
    model->setHeaderData(7, Qt::Horizontal,QObject:: tr("DATEM"));

    return model;
}
QSqlQueryModel* Etudiant::tri2()
{
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT* FROM GMATCHS ORDER BY SCORE");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("EQUIPE1"));
    model->setHeaderData(1, Qt::Horizontal,QObject:: tr("EQUIPE2"));
    model->setHeaderData(7, Qt::Horizontal,QObject:: tr("SCORE"));
    model->setHeaderData(7, Qt::Horizontal,QObject:: tr("DISCPLINE"));
    model->setHeaderData(7, Qt::Horizontal,QObject:: tr("NUMMATCH"));
    model->setHeaderData(7, Qt::Horizontal,QObject:: tr("TEMPS"));
    model->setHeaderData(7, Qt::Horizontal,QObject:: tr("DATEM"));

    return model;
}


bool Etudiant::ajouterp()
{
            QSqlQuery query;
QString res3=QString::number(e1);
QString res4=QString::number(e2);
QString res5=QString::number(egalite);
 QString res6=QString::number(nummatch2);
                  query.prepare("INSERT INTO GPARIS (E1_G,E2_G,PLAYER,EGALITE,NUMMATCH) "
                                "VALUES (:e1,:e2,:player,:egalite,:nummatch2)");

                  query.bindValue(0,res3);
                  query.bindValue(1,res4);
                  query.bindValue(2,player);
                  query.bindValue(3,res5);
                  query.bindValue(4,res6);

                 return query.exec();

}

bool Etudiant::supprimerp(int nummatch2 )
{
 QSqlQuery query;
 QString res6=QString::number(nummatch2);
 query.prepare("DELETE FROM GPARIS WHERE NUMMATCH= :nummatch2");
 query.bindValue(":nummatch2",res6);
 return query.exec();
}
QSqlQueryModel * Etudiant::afficherp()
{
    QSqlQueryModel *model = new QSqlQueryModel;
          model->setQuery("SELECT * from GPARIS ");
          model->setHeaderData(0, Qt::Horizontal,QObject::tr("E1_G"));
          model->setHeaderData(1, Qt::Horizontal,QObject:: tr("E2_G"));
          model->setHeaderData(7, Qt::Horizontal,QObject:: tr("PLAYER"));
          model->setHeaderData(7, Qt::Horizontal,QObject:: tr("EGALITE"));
            model->setHeaderData(7, Qt::Horizontal,QObject:: tr("NUMMATCH"));

 return model;
}
bool Etudiant::ajouterb()
{
            QSqlQuery query;
QString a=QString::number(id);
QString b=QString::number(prix);

                  query.prepare("INSERT INTO GBILLET (ID,PRIX) "
                                "VALUES (:id, :prix)");

                  query.bindValue(0,a);
                  query.bindValue(1,b);

                 return query.exec();

}
QSqlQueryModel * Etudiant::afficherb()
{
    QSqlQueryModel *model = new QSqlQueryModel;
          model->setQuery("SELECT * from GBILLET ");
          model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
          model->setHeaderData(1, Qt::Horizontal,QObject:: tr("PRIX"));
 return model;
}



Etudiant::Etudiant(int score, QString equipe1, QString equipe2,QString discpline,int nummatch,QString temps,QDate date)
{this->score=score; this ->equipe1=equipe1; this->equipe2=equipe2; this->discpline=discpline; this->nummatch=nummatch;this->temps=temps;this->date=date;}
int Etudiant::getscore(){return score;}
int Etudiant::getnummatch(){return nummatch;}
QDate Etudiant::getdate(){return date;}
QString Etudiant::gettemps(){return temps;}
QString Etudiant::getequipe1(){return equipe1;}
QString Etudiant::getequipe2(){return equipe2;}
QString Etudiant::getdiscpline(){return discpline;}
void Etudiant::setdate(QDate date){this->date=date;}
void Etudiant::setscore(int score){this->score=score;}
void Etudiant::setnummatch(int nummatch){this->nummatch=nummatch;}
void Etudiant::settemps(QString temps){this->temps=temps;}
void Etudiant::setequipe1(QString equipe1){this->equipe1=equipe1;}
void Etudiant::setequipe2(QString equipe2){this->equipe2=equipe2;}
void Etudiant::setdiscpline(QString discpline){this->discpline=discpline;}

Etudiant::Etudiant(int e1,int e2,QString player,int egalite,int nummatch2)
{this->e1=e1; this->e2=e2; this->player=player; this->egalite=egalite;this->nummatch2=nummatch2;}
int Etudiant::gete1(){return e1;}
int Etudiant::gete2(){return e2;}
int Etudiant::getnummatch2(){return nummatch2;}
QString Etudiant::getplayer(){return player;}
int Etudiant::getegalite(){return egalite;}
void Etudiant::sete1(int e1){this->e1=e1;}
void Etudiant::sete2(int e2){this->e2=e2;}
void Etudiant::setnummatch2(int nummatch2){this->nummatch2=nummatch2;}
void Etudiant::setplayer(QString player){this->player=player;}
void Etudiant::setegalite(int egalite){this->egalite=egalite;}


Etudiant::Etudiant(int id,float prix)
{this->id=id; this->prix=prix;}
int Etudiant::getid(){return id;}
float Etudiant::getprix(){return prix;}
void Etudiant::setid(int id){this->id=id;}
void Etudiant::setprix(float prix){this->prix=prix;}
