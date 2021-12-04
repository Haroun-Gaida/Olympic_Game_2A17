
#ifndef ETUDIANT_H
#define ETUDIANT_H


#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class SPORTIF
{
private:
    QString NOM, PRENOM,TESTD,FORFAIT,DISCIPLINE,EMAIL,NATIONALITE;
    int ID,SCORE;

public:
    SPORTIF(){}
    SPORTIF(int,int,QString,QString,QString,QString,QString,QString,QString);
    QString getnom(){return NOM;}
    QString getprenom(){return PRENOM;}
    QString gettestd(){return TESTD;}
    QString getforfait(){return FORFAIT;}
    QString getdiscipline(){return DISCIPLINE;}
    QString getemail(){return EMAIL;}
    QString getnationalite(){return NATIONALITE;}

    int getid(){return ID;}
    int getscore(){return SCORE;}


    void setnom(QString n){NOM=n;}
    void settestd(QString d){TESTD=d;}
    void setforfait(QString f){FORFAIT=f;}
    void setdiscipline(QString dp){DISCIPLINE=dp;}
    void setprenom(QString p){PRENOM=p;}
    void setemail(QString em){EMAIL=em;}
    void setnationalite(QString na){NATIONALITE=na;}
    void setid(int id){this->ID=id;}
    void setscore(int sc){this->SCORE=sc;}


    bool ajouter();
    QSqlQueryModel*afficher();
    bool supprimer(int );
    bool modifier(int);
    QSqlQueryModel * statistic();
    QSqlQueryModel* tri();



};
#endif // ETUDIANT_H
