#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <QString>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QDate>
class Etudiant
{
public:
    Etudiant();
    Etudiant(int,QString,QString,QString,int,QString,QDate);
    Etudiant(int,int,QString,int,int);
    Etudiant(int,float);
    int getid();
    float getprix();
    int gete1();
    int gete2();
    int getegalite();
    int getscore();
    int getnummatch();
     int getnummatch2();
    QString getplayer();
    QString getequipe1();
    QString getequipe2();
    QString getdiscpline();
    QString gettemps();
    QDate getdate();
    void set(QString);
    void setid(int);
    void setprix(float);
    void setscore(int);
    void setnummatch(int);
    void setnummatch2(int);
     void sete1(int);
      void sete2(int);
      void setegalite(int);
      void setplayer(QString);
    void setequipe1(QString);
    void setequipe2(QString);
    void setdiscpline(QString);
    void settemps(QString);
    void setdate(QDate);
    bool ajouter();
    bool ajouterp();
    bool ajouterb();
    bool supprimer(int);
     bool supprimerp(int);
    bool editer();
    QSqlQueryModel* afficher();
    QSqlQueryModel * afficherp();
      QSqlQueryModel * afficherb();
       QSqlQueryModel* tri();
       QSqlQueryModel* tri2();
private :
   int score,nummatch,e1,e2,egalite,nummatch2,id;
   QString equipe1,equipe2,discpline,temps,player;
   QDate date;
   float prix;

   
};

#endif // ETUDIANT_H
