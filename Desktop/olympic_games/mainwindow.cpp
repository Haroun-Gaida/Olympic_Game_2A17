#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matchs.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QDate>
#include <QDateEdit>
#include <QDateTimeEdit>
#include"sportifs.h"
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
#include "logement.h"
#include <QMessageBox>
#include "terrains_de_jeux.h"
#include<QObject>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_etudiant->setModel(Etmp0.afficher());
    ui->tabmatch->setModel(Etmp0.tri());
    ui->le_score->setValidator(new QIntValidator(0,999999,this));
     ui->le_num->setValidator(new QIntValidator(0,999999,this));
     QDate date = QDate::currentDate();
      ui->dateEdit->setDate(date);
      ui->tableView_4->setModel(Etmp.afficher());
      ui->tableView2->setModel(Etmp2.afficher());
      ui->tab_logement->setModel(l.afficher());


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int score=ui->le_score->text().toInt();
    QString equipe1=ui->le_nom->text();
    QString equipe2=ui->le_prenom->text();
    QString discpline=ui->le_discpline->text();
    int nummatch=ui->le_num->text().toInt();
    QString temps=ui->le_temps->text();
    QDate date=ui->dateEdit->date();



    Etudiant E(score,equipe1,equipe2,discpline,nummatch,temps,date);
    bool test=E.ajouter();
        if(test)
        {
              ui->tab_etudiant->setModel(Etmp0.afficher());
               ui->tabmatch->setModel(Etmp0.tri());
               ui->tableView_2->setModel(Etmp0.tri2());
            QMessageBox::information(nullptr,QObject::tr("ok"),
                    QObject::tr("ajout effectué\n""click concel to exit."),QMessageBox::Cancel);
        }
            else
                QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                      QObject::tr("ajout non effectué.\n""click cancel to exit."),QMessageBox::Cancel);

}

void MainWindow::on_pushButton_2_clicked()
{
      ui->tab_etudiant->setModel(Etmp0.afficher());
       ui->tabmatch->setModel(Etmp0.tri());
 int nummatch=ui->lineEdit->text().toInt();
 bool test= Etmp0.supprimer(nummatch);
 if(test)
 {
       ui->tab_etudiant->setModel(Etmp0.afficher());
        ui->tabmatch->setModel(Etmp0.tri());
     QMessageBox::information(nullptr,QObject::tr("ok"),
             QObject::tr("supp effectué\n""click concel to exit."),QMessageBox::Cancel);
 }
     else
         QMessageBox::critical(nullptr,QObject::tr("not ok"),
                               QObject::tr("supp non effectué.\n""click cancel to exit."),QMessageBox::Cancel);

}





void MainWindow::on_pushButton_6_clicked()
{

    int score=ui->le_score_2->text().toInt();
    QString equipe1=ui->le_nom_2->text();
    QString equipe2=ui->le_prenom_2->text();
    QString discpline=ui->le_discpline_2->text();
    int nummatch=ui->le_num_2->text().toInt();
    QString temps=ui->le_temps_2->text();
    QDate date=ui->dateEdit->date();

    Etudiant E(score,equipe1,equipe2,discpline,nummatch,temps,date);
    bool test=E.editer();
    if(test)
    {
          ui->tab_etudiant->setModel(Etmp0.afficher());
           ui->tabmatch->setModel(Etmp0.tri());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("ajout effectué\n""click concel to exit."),QMessageBox::Cancel);
    }
        else
            QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                  QObject::tr("ajout non effectué.\n""click cancel to exit."),QMessageBox::Cancel);

}



void MainWindow::on_dateEdit_userDateChanged(const QDate &date)
{

     ui->dateEdit->setDate(date);
}


void MainWindow::on_pushButton_3_clicked()
{

            int e1=ui->le_e1->text().toInt();
            int e2=ui->le_e2->text().toInt();
             QString player=ui->le_player->text();
            int egalite=ui->le_e3->text().toInt();
            int nummatch2=ui->le_num_3->text().toInt();
        Etudiant E1(e1,e2,player,egalite,nummatch2);
        bool test=E1.ajouterp();
        if(test)
        {
ui->tableView->setModel(Etmp0.afficherp());

            QMessageBox::information(nullptr,QObject::tr("ok"),
                    QObject::tr("paris effectué\n""click concel to exit."),QMessageBox::Cancel);
        }
            else
                QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                      QObject::tr("paris non effectué.\n""click cancel to exit."),QMessageBox::Cancel);



}

void MainWindow::on_pushButton_4_clicked()
{

 int nummatch2=ui->le_num_3->text().toInt();
bool test= Etmp0.supprimerp(nummatch2);
if(test)
{
ui->tableView->setModel(Etmp0.afficherp());

    QMessageBox::information(nullptr,QObject::tr("ok"),
            QObject::tr("supp effectué\n""click concel to exit."),QMessageBox::Cancel);
}
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("supp non effectué.\n""click cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_5_clicked()
{
     int id=ui->le_id->text().toInt();
     float prix=ui->le_prix->text().toFloat();
     Etudiant E(id,prix);
      bool test=E.ajouterb();
      if(test)
      {
      ui->tableView_3->setModel(Etmp0.afficherb());

          QMessageBox::information(nullptr,QObject::tr("ok"),
                  QObject::tr("ajout effectué\n""click concel to exit."),QMessageBox::Cancel);
      }
          else
              QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                    QObject::tr("ajout non effectué.\n""click cancel to exit."),QMessageBox::Cancel);
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








void MainWindow::on_pushButtonstats_clicked()
{
    stat_j=new statj(this);
    stat_j->show();
}

void MainWindow::on_pushButtonpdf_clicked()
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

void MainWindow::on_pushButtontri_clicked()
{
    ui->tableView_4->setModel(Etmp.tri());

}

void MainWindow::on_pushButtonajouter_clicked()
{

    int ID=ui->le_id_2->text().toInt();
    int SCORE=ui->lescore->text().toInt();

    QString NOM=ui->le_nom_3->text();
    QString PRENOM=ui->le_prenom_3->text();
    QString DICIPLINE=ui->le1->text();
    QString FORFAIT=ui->le2->text();
    QString TESTD=ui->le3->text();
    QString EMAIL=ui->leem->text();
    QString NATIONALITE=ui->lena->text();



    SPORTIF s(ID,SCORE,NOM,PRENOM,DICIPLINE,FORFAIT,TESTD,EMAIL,NATIONALITE);
    bool test=s.ajouter();
    if(test)
    {
        ui->tableView_4->setModel(Etmp.afficher());

        QMessageBox::information(nullptr,QObject::tr("database is open "),QObject::tr("create successful.\n"
                                                                                      "click cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("data is not open"),QObject::tr("create failed.\n"
                                                                                  "click cancel to exit."),QMessageBox::Cancel);
}



void MainWindow::on_pushButtonsupp_clicked()
{
    int ID=ui->lineEdit_4->text().toInt();
    bool test=Etmp.supprimer(ID);
    if(test)
    {
        ui->tableView_4->setModel(Etmp.afficher());


        QMessageBox::information(nullptr,QObject::tr("database is open "),QObject::tr("delete successful.\n"
                                                                                      "click cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("data is not open"),QObject::tr("delete failed.\n"
                                                                                  "click cancel to exit."),QMessageBox::Cancel);
}
void MainWindow::on_bouajouter_clicked()
{
QString nom=ui->le_nom->text();
QString coordonnee=ui->la_coordonnee->text();



    logement l(nom,coordonnee);
    bool test = l.ajouter();

        if(test)
        {   ui->tab_logement->setModel(l.afficher());

            QMessageBox::information(nullptr, QObject::tr("OK"),
                        QObject::tr("Ajout effectué.\n"
                                    "Click Ok to exit."), QMessageBox::Ok);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("Ajout non effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
    logement l1; l1.setnom(ui->l2nomsuppr->text());
    bool test=l1.supprimer(l1.getnom());
    QMessageBox msgBox;
    if(test)
      { msgBox.setText("suppression avec succes.");
        ui->tab_logement->setModel(l.afficher());
         }
    else
             msgBox.setText("Echec de suppression!");
       msgBox.exec();}


void MainWindow::on_pushButtonmodifier_clicked()
{
 logement l;
 bool test=l.modifier(1,ui->editnom->text());
 QMessageBox msgBox;
     if(test)
     {
        ui->tab_logement->setModel(l.afficher());
         msgBox.setText("Modification avec succes!");
     }
     else
     {
         msgBox.setText("Echec de modification");

     }
     msgBox.exec();
 }









void MainWindow::on_tabWidget_2_currentChanged(int index)
{
  ui->tab_terrain->setModel(t.afficher());}

  void MainWindow::on_aj_terrain_clicked()
  {QString nom=ui->le_nom_terrain->text();
    QString coordonnee=ui->le_coo->text();
    QString etat=ui->lineEtat->text();




        terrains_de_jeux t(nom,coordonnee,etat);
        bool test = t.ajouter();

            if(test)
            {   ui->tab_terrain->setModel(t.afficher());

                QMessageBox::information(nullptr, QObject::tr("OK"),
                            QObject::tr("Ajout effectué.\n"
                                        "Click Ok to exit."), QMessageBox::Ok);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                            QObject::tr("Ajout non effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);


    }




void MainWindow::on_pb_supprimer_terrain_clicked()
{ terrains_de_jeux t1; t1.setnom(ui->le_nomsupp->text());
  bool test=t1.supprimer(t1.getnom());
  QMessageBox msgBox;
  if(test)
    { msgBox.setText("suppression avec succes.");
      ui->tab_terrain->setModel(t.afficher());
       }
  else
           msgBox.setText("Echec de suppression!");
     msgBox.exec();}






void MainWindow::on_pushButtonmmodifier_clicked()
{
  terrains_de_jeux t;
  bool test=t.modifier(1,ui->nom_modifi->text());
  QMessageBox msgBox;
      if(test)
      {
         ui->tab_terrain->setModel(t.afficher());
          msgBox.setText("Modification avec succes!");
      }
      else
      {
          msgBox.setText("Echec de modification");

      }
      msgBox.exec();
}






void MainWindow::on_nom_rechercher_textEdited(const QString &text)
{
    ui->tab_logement->setModel(l.recherche(text));
}

void MainWindow::on_coor_rechercher_textEdited(const QString &text)
{
    ui->tab_logement->setModel(l.recherche1(text));
}

void MainWindow::on_lineEdit_textEdited(const QString &text)
{
    ui->tab_terrain->setModel(t.recherche3(text));
}




void MainWindow::on_pushButtonmodifier0_clicked()
{
    int ID=ui->le_id_2->text().toInt();
    int SCORE=ui->lescore->text().toInt();

    QString NOM=ui->le_nom_3->text();
    QString PRENOM=ui->le_prenom_3->text();
    QString DICIPLINE=ui->le1->text();
    QString FORFAIT=ui->le2->text();
    QString TESTD=ui->le3->text();
    QString EMAIL=ui->leem->text();
    QString NATIONALITE=ui->lena->text();



    SPORTIF a(ID,SCORE,NOM,PRENOM,DICIPLINE,FORFAIT,TESTD,EMAIL,NATIONALITE);

     bool test=a.modifier(ID);
     if(test)
     {
         ui->tableView_4->setModel(Etmp.afficher());



         QMessageBox::information(nullptr,QObject::tr("database is open "),QObject::tr("modification successful.\n"
                                                                                       "click cancel to exit."),QMessageBox::Cancel);
     }
     else
         QMessageBox::critical(nullptr,QObject::tr("data is not open"),QObject::tr("modification failed.\n"
                                                                                   "click cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_tridh_clicked()
{
    ui->tab_logement->setModel(l.tri());
}
