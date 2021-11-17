#include "connection.h"
#include <QSqlDatabase>

Connection::Connection()
{

}

bool Connection::createconnection()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("database test");
db.setUserName("killian");//inserer nom de l'utilisateur
db.setPassword("killian");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}

void Connection::closeConnection(){db.close();}
