#ifndef TERRAINS_DE_JEUX_H
#define TERRAINS_DE_JEUX_H


#include <QString>
#include <ctime>
#include <qsqlquerymodel.h>
#include <QSqlQueryModel>

class terrains_de_jeux
{
public:
 terrains_de_jeux();
 terrains_de_jeux(QString,QString,QString);
  QString getnom();
  QString getcoordonnee();
  QString getetat();
  void setnom(QString);
  void setcoordonnee(QString);
  void setetat(QString);
  bool ajouter();
  QSqlQueryModel * recherche3(QString);

  QSqlQueryModel* afficher();
  bool supprimer(QString);
  bool modifier(int,QString);



  private:
  QString nom,coordonnee,etat;

};

#endif // TERRAINS_DE_JEUX_H
