#ifndef PERFORMANCE_H
#define PERFORMANCE_H


#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class PERFORMANCE
{
private:
    QString NOM, PRENOM;
    int ID,SCORE;

public:
    PERFORMANCE(){}
    PERFORMANCE(int,int,QString,QString);
    QString getnom(){return NOM;}
    QString getprenom(){return PRENOM;}

    int getid(){return ID;}
    int getscore(){return SCORE;}//hh


    void setnom(QString n){NOM=n;}

    void setprenom(QString p){PRENOM=p;}

    void setid(int id){this->ID=id;};
    void setscore(int sc){this->SCORE=sc;};


    bool ajouter();
    QSqlQueryModel*afficher();
    bool modifier(int);
};
#endif // PERFORMANCE_H
