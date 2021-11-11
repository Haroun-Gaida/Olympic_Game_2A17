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
 terrains_de_jeux(QString,QString);
  QString getnom();
  QString getcoordonnee();
  void setnom(QString);
  void setcoordonnee(QString);
  bool ajouter();
  QSqlQueryModel* afficher();
  bool supprimer(QString);

  private:
  QString nom,coordonnee;

};

#endif // TERRAINS_DE_JEUX_H
