#include"connection.h"


connection::connection(){}

 bool connection::createconnection()
 {

     QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("source_projet2A");
db.setUserName("hamdi");
db.setPassword("hamdi04");

if(db.open())test=true;
return test;
 }
 void connection::closeconnection(){db.close();}




