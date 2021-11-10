
#ifndef ETUDIANT_H
#define ETUDIANT_H


#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class SPORTIF
{
private:
    QString NOM, PRENOM,TESTD,FORFAIT,DISCIPLINE;
    int ID;

public:
    SPORTIF(){}
    SPORTIF(int,QString,QString,QString,QString,QString);
    QString getnom(){return NOM;}
    QString getprenom(){return PRENOM;}
    QString gettestd(){return TESTD;}
    QString getforfait(){return FORFAIT;}
    QString getdiscipline(){return DISCIPLINE;}
    int getid(){return ID;}


    void setnom(QString n){NOM=n;}
    void settestd(QString d){TESTD=d;}
    void setforfait(QString f){FORFAIT=f;}
    void setdiscipline(QString dp){DISCIPLINE=dp;}
    void setprenom(QString p){PRENOM=p;}
    void setid(int id){this->ID=id;};


    bool ajouter();
    QSqlQueryModel*afficher();
    bool supprimer(int );
    bool modifier(int);


};
#endif // ETUDIANT_H
