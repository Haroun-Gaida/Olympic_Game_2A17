#ifndef LOGEMENT_H
#define LOGEMENT_H
#include <QString>
#include <ctime>
#include <qsqlquerymodel.h>
#include <QSqlQueryModel>

class logement
{
public:
  logement();
  logement(QString,QString);
  QString getnom();
  QString getcoordonnee();
  void setnom(QString);
  void setcoordonnee(QString);
  bool ajouter();
  QSqlQueryModel* afficher();
  bool supprimer(QString);
 bool modifier(int,QString);


private:
  QString nom,coordonnee;



};

#endif // LOGEMENT_H
