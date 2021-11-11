#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
  db = QSqlDatabase::addDatabase("QODBC");

  bool test=false;

db.setDatabaseName("data");
db.setUserName("dhia");//inserer nom de l'utilisateur
db.setPassword("dhia");//inserer mot de passe de cet utilisateur

if (db.open()) test=true;

    return  test;
}
