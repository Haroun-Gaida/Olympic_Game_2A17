#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"ui_dialog.h"

#include"dialog_email.h"
#include"performance.h"
#include"etudiant.h"
#include"connection.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QPrinter>
#include <QPrinterInfo>
#include <QPrintDialog>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include <QTextDocument>
#include <QDialog>
#include <QSystemTrayIcon>
#include <QFile>
#include <QFileDialog>
#include"statj.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Etmp.afficher());
    ui->tableView2->setModel(Etmp2.afficher());


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    int ID=ui->le_id->text().toInt();
    int SCORE=ui->lescore->text().toInt();//hh

    QString NOM=ui->le_nom->text();
    QString PRENOM=ui->le_prenom->text();
    QString DICIPLINE=ui->le1->text();
    QString FORFAIT=ui->le2->text();
    QString TESTD=ui->le3->text();
    QString EMAIL=ui->leem->text();
    QString NATIONALITE=ui->lena->text();

    histo.save("id:"+ui->le_id->text(),"dicipline :"+ui->le1->text());


    SPORTIF s(ID,SCORE,NOM,PRENOM,DICIPLINE,FORFAIT,TESTD,EMAIL,NATIONALITE);
    bool test=s.ajouter();
    if(test)
    {
        ui->tableView->setModel(Etmp.afficher());

        QMessageBox::information(nullptr,QObject::tr("database is open "),QObject::tr("create successful.\n"
                                                                                      "click cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("data is not open"),QObject::tr("create failed.\n"
                                                                                  "click cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_clicked()
{
int ID=ui->lineEdit_4->text().toInt();
bool test=Etmp.supprimer(ID);
if(test)
{
    ui->tableView->setModel(Etmp.afficher());


    QMessageBox::information(nullptr,QObject::tr("database is open "),QObject::tr("delete successful.\n"
                                                                                  "click cancel to exit."),QMessageBox::Cancel);
}
else
    QMessageBox::critical(nullptr,QObject::tr("data is not open"),QObject::tr("delete failed.\n"
                                                                              "click cancel to exit."),QMessageBox::Cancel);
}





void MainWindow::on_pushButton_4_clicked()
{

    {

        QSqlDatabase db;
                    QTableView table_facture;
                    QSqlQueryModel * Modal=new  QSqlQueryModel();

                    QSqlQuery qry;
                    // qry.prepare("SELECT * FROM SPORTIF ");
                    qry.prepare("SELECT ID,NOM,PRENOM,DISCIPLINE,FORFAIT,NATIONALITÉ FROM SPORTIF ");

                    qry.exec();
                     Modal->setQuery(qry);
                     table_facture.setModel(Modal);

                     db.close();

                     QString strStream;
                     QTextStream out(&strStream);

                     const int rowCount = table_facture.model()->rowCount();
                     const int columnCount =  table_facture.model()->columnCount();

                     const QString strTitle ="Document";


                     out <<  "<html>\n"
                             "<img src='C:/Users/ASUS/Documents/kiosqueK/logocin.ng' height='120' width='120'/>"
                         "<head>\n"
                             "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg(strTitle)
                         <<  "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"
                        << QString("<h3 style=\" font-size: 50px; font-family: Arial, Helvetica, sans-serif; color: #e80e32; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des sportifs")
                        <<"<br>"

                        <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";
                     out << "<thead><tr bgcolor=#f0f0f0>";
                     for (int column = 0; column < columnCount; column++)
                         if (!table_facture.isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(table_facture.model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!table_facture.isColumnHidden(column)) {
                                 QString data = table_facture.model()->data(table_facture.model()->index(row, column)).toString().simplified();
                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                             }
                         }
                         out << "</tr>\n";
                     }
                     out <<  "</table>\n"
                             "<br><br>"
                             <<"<br>"
                             <<"<table border=1 cellspacing=0 cellpadding=2>\n";


                         out << "<thead><tr bgcolor=#f0f0f0>";

                             out <<  "</table>\n"

                         "</body>\n"
                         "</html>\n";

                     QTextDocument *document = new QTextDocument();
                     document->setHtml(strStream);

                     QPrinter printer;
                     QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                     if (dialog->exec() == QDialog::Accepted) {

                         document->print(&printer);
                     }

                     printer.setOutputFormat(QPrinter::PdfFormat);
                     printer.setPaperSize(QPrinter::A4);
                     printer.setOutputFileName("/tmp/facture.pdf");
                     printer.setPageMargins(QMarginsF(15, 15, 15, 15));

                     delete document;
    }
}

void MainWindow::on_pushButton_5_clicked()
{

    ui->tableView->setModel(Etmp.tri());
    }


void MainWindow::on_pushButton_6_clicked()
{
    dialog_email = new Dialog_email(this);
    dialog_email->show();

}

void MainWindow::on_ajouter0_clicked()
{
    int ID=ui->leid0->text().toInt();
    int SCORE=ui->lesc0->text().toInt();

    QString NOM=ui->lenom0->text();
    QString PRENOM=ui->lepre0->text();
    PERFORMANCE x(ID,SCORE,NOM,PRENOM);
    bool test=x.ajouter();
    if(test)
    {
        ui->tableView2->setModel(Etmp2.afficher());

        QMessageBox::information(nullptr,QObject::tr("database is open "),QObject::tr("create successful.\n"
                                                                                      "click cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("data is not open"),QObject::tr("create failed.\n"
                                                                                  "click cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_modifier0_clicked()
{
    int ID=ui->leid01->text().toInt();
    int SCORE=ui->lesc01->text().toInt();

    QString NOM=ui->lenom01->text();
    QString PRENOM=ui->lepre01->text();
    PERFORMANCE z(ID,SCORE,NOM,PRENOM);
    bool test=z.modifier(ID);
    if(test)
    {
        ui->tableView2->setModel(Etmp2.afficher());

        QMessageBox::information(nullptr,QObject::tr("database is open "),QObject::tr("create successful.\n"
                                                                                      "click cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("data is not open"),QObject::tr("create failed.\n"
                                                                                  "click cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_excel_clicked()
{
    QTableView *table;
               table = ui->tableView2;

               QString filters("CSV files (.csv);;All files (.*)");
               QString defaultFilter("CSV files (*.csv)");
               QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                  filters, &defaultFilter);
               QFile file(fileName);

               QAbstractItemModel *model =  table->model();
               if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                   QTextStream data(&file);
                   QStringList strList;
                   for (int i = 0; i < model->columnCount(); i++) {
                       if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                           strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                       else
                           strList.append("");
                   }
                   data << strList.join(";") << "\n";
                   for (int i = 0; i < model->rowCount(); i++) {
                       strList.clear();
                       for (int j = 0; j < model->columnCount(); j++) {

                           if (model->data(model->index(i, j)).toString().length() > 0)
                               strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                           else
                               strList.append("");
                       }
                       data << strList.join(";") + "\n";
                   }
                   file.close();
                   QMessageBox::information(nullptr, QObject::tr("Export excel"),
                                             QObject::tr("Export avec succes .\n"
                                                         "Click OK to exit."), QMessageBox::Ok);
               }
}




void MainWindow::on_pushButton_7_clicked()
{
    stat_j=new statj(this);
    stat_j->show();
}

void MainWindow::on_pushButton_13_clicked()
{
    int ID=ui->le_id->text().toInt();
    int SCORE=ui->lescore->text().toInt();

    QString NOM=ui->le_nom->text();
    QString PRENOM=ui->le_prenom->text();
    QString DICIPLINE=ui->le1->text();
    QString FORFAIT=ui->le2->text();
    QString TESTD=ui->le3->text();
    QString EMAIL=ui->leem->text();
    QString NATIONALITE=ui->lena->text();



    SPORTIF a(ID,SCORE,NOM,PRENOM,DICIPLINE,FORFAIT,TESTD,EMAIL,NATIONALITE);

     bool test=a.modifier(ID);
     if(test)
     {
         ui->tableView->setModel(Etmp.afficher());



         QMessageBox::information(nullptr,QObject::tr("database is open "),QObject::tr("modification successful.\n"
                                                                                       "click cancel to exit."),QMessageBox::Cancel);
     }
     else
         QMessageBox::critical(nullptr,QObject::tr("data is not open"),QObject::tr("modification failed.\n"
                                                                                   "click cancel to exit."),QMessageBox::Cancel);
}
