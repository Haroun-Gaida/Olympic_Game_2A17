#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>

class connection
{
    QSqlDatabase db;
public:
    connection();//hh
    bool createconnection();
    void closeconnection();

};
#endif // CONNECTION_H
