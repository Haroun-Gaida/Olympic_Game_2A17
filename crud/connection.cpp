#include "connection.h"
//cnx
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("THA_2022");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("projet");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
