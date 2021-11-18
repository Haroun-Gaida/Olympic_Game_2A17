#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "joueurs.h"
#include "QSqlQuery"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tablestaff->setModel(tmpstaff.afficher());
    ui->tableforfait->setModel(tmpforfait.afficher_forfait());
    model=new QSqlTableModel;
    model->select();
    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showtime()));
    timer->start();

    QDate date = QDate ::currentDate();
    QString datee=date.toString();

}
MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_3_clicked()
{
    int i=0,j=0,x=0,n=0,p=0,b=0,c=0,y=0,w=0,h=0,r=0,t=0,k=0,r2=0,t2=0,k2=0,s=0;
        int  c1=0, c2=0, c3=0, c4=0, c5=0, c6=0, c7=0;
        int ajout=0;
        //int point=10;

        bool test;//= f.ajouter_staff();

        int id_s= ui->txt_cin->text().toInt();
        int tel_s=ui->txt_num->text().toInt();
        QString nom = ui->txt_nom->text();
        QString prenom = ui->txt_prenom->text();
        QDateTime date_add_s=ui->dateEdit->dateTime();
        QString email_s = ui->txt_email->text();
        QString specialite_s = ui->txt_spec->text();
        QString adresse_add_s = ui->txt_adresse->text();

        QString id_s2= ui->txt_cin->text();
        QString tel_s2=ui->txt_num->text();
        QString nom2 = ui->txt_nom->text();
        QString prenom2 = ui->txt_prenom->text();
        QString specialite_s2 = ui->txt_spec->text();
        QString adresse_add_s2 = ui->txt_adresse->text();
        QString email_s2 = ui->txt_email->text();
        QString gmail1="gmail";
        QString gmail2="esprit";

        //condition id_s
        if(id_s2!="")
            {
             if(id_s2.length()!=8)
                 c1=1;
            for(i=0;i<id_s2.length();i++)
             {
                if(id_s2[i]=="a"  )
                        c1=1;
                if(id_s2[i]=="b"  )
                        c1=1;
                if(id_s2[i]=="c"  )
                        c1=1;
                if(id_s2[i]=="d"  )
                        c1=1;
                if(id_s2[i]=="e"  )
                        c1=1;
                if(id_s2[i]=="f"  )
                        c1=1;
                if(id_s2[i]=="g"  )
                        c1=1;
                if(id_s2[i]=="h"  )
                        c1=1;
                if(id_s2[i]=="i"  )
                        c1=1;
                if(id_s2[i]=="j"  )
                        c1=1;
                if(id_s2[i]=="k"  )
                        c1=1;
                if(id_s2[i]=="l"  )
                        c1=1;
                if(id_s2[i]=="m"  )
                        c1=1;
                if(id_s2[i]=="n"  )
                        c1=1;
                if(id_s2[i]=="o"  )
                        c1=1;
                if(id_s2[i]=="p"  )
                        c1=1;
                if(id_s2[i]=="r"  )
                        c1=1;
                if(id_s2[i]=="s"  )
                        c1=1;
                if(id_s2[i]=="t"  )
                        c1=1;
                if(id_s2[i]=="u"  )
                        c1=1;
                if(id_s2[i]=="v"  )
                        c1=1;
                if(id_s2[i]=="w"  )
                        c1=1;
                if(id_s2[i]=="x"  )
                        c1=1;
                if(id_s2[i]=="y"  )
                        c1=1;
                if(id_s2[i]=="z"  )
                        c1=1;
             }

            }
            else
            {
                c1=1;
            }

            //condition nom
            if(nom2!="")
            {
            for(i=0;i<nom2.length();i++)
            {
                if(nom2[i]=="0")
                    c2=1;
                if(nom2[i]=="1")
                    c2=1;
                if(nom2[i]=="2")
                    c2=1;
                if(nom2[i]=="3")
                    c2=1;
                if(nom2[i]=="4")
                    c2=1;
                if(nom2[i]=="5")
                    c2=1;
                if(nom2[i]=="6")
                    c2=1;
                if(nom2[i]=="7")
                    c2=1;
                if(nom2[i]=="8")
                    c2=1;
                if(nom2[i]=="9")
                    c2=1;
            }
            }else
               c2=1;
                       //condition prenom
            if(prenom2!="")
            {
            for(i=0;i<nom2.length();i++)
            {
                if(nom2[i]=="0")
                    c3=1;
                if(nom2[i]=="1")
                    c3=1;
                if(nom2[i]=="2")
                    c3=1;
                if(nom2[i]=="3")
                    c3=1;
                if(nom2[i]=="4")
                    c3=1;
                if(nom2[i]=="5")
                    c3=1;
                if(nom2[i]=="6")
                    c3=1;
                if(nom2[i]=="7")
                    c3=1;
                if(nom2[i]=="8")
                    c3=1;
                if(nom2[i]=="9")
                    c3=1;
            }
            }else
               c3=1;

            //condition adresse_s
            if(adresse_add_s2!="")
            {
            for(i=0;i<adresse_add_s2.length();i++)
            {
                if(adresse_add_s2[i]=="0")
                    c4=1;
                if(adresse_add_s2[i]=="1")
                    c4=1;
                if(adresse_add_s2[i]=="2")
                    c4=1;
                if(adresse_add_s2[i]=="3")
                    c4=1;
                if(adresse_add_s2[i]=="4")
                    c4=1;
                if(adresse_add_s2[i]=="5")
                    c4=1;
                if(adresse_add_s2[i]=="6")
                    c4=1;
                if(adresse_add_s2[i]=="7")
                    c4=1;
                if(adresse_add_s2[i]=="8")
                    c4=1;
                if(adresse_add_s2[i]=="9")
                    c4=1;
            }
            }else
               c4=1;

            //condition specialite_s
            if(specialite_s2!="")
            {
            for(i=0;i<specialite_s2.length();i++)
            {
                if(specialite_s2[i]=="0")
                    c7=1;
                if(specialite_s2[i]=="1")
                    c7=1;
                if(specialite_s2[i]=="2")
                    c7=1;
                if(specialite_s2[i]=="3")
                    c7=1;
                if(specialite_s2[i]=="4")
                    c7=1;
                if(specialite_s2[i]=="5")
                    c7=1;
                if(specialite_s2[i]=="6")
                    c7=1;
                if(specialite_s2[i]=="7")
                    c7=1;
                if(specialite_s2[i]=="8")
                    c7=1;
                if(specialite_s2[i]=="9")
                    c7=1;
            }
            }else
               c7=1;

            //condition email_s
            for(i=0;i<email_s2.length();i++)
                {
                    if(email_s2[i]=="a"  )
                        j++;
                    if(email_s2[i]=="b"  )
                        j++;
                    if(email_s2[i]=="c"  )
                        j++;
                    if(email_s2[i]=="d"  )
                        j++;
                    if(email_s2[i]=="e"  )
                        j++;
                    if(email_s2[i]=="f"  )
                        j++;
                    if(email_s2[i]=="g"  )
                        j++;
                    if(email_s2[i]=="h"  )
                        j++;
                    if(email_s2[i]=="i"  )
                        j++;
                    if(email_s2[i]=="j"  )
                        j++;
                    if(email_s2[i]=="k"  )
                        j++;
                    if(email_s2[i]=="l"  )
                        j++;
                    if(email_s2[i]=="m"  )
                        j++;
                    if(email_s2[i]=="n"  )
                        j++;
                    if(email_s2[i]=="o"  )
                        j++;
                    if(email_s2[i]=="p"  )
                        j++;
                    if(email_s2[i]=="r"  )
                        j++;
                    if(email_s2[i]=="s"  )
                        j++;
                    if(email_s2[i]=="t"  )
                        j++;
                    if(email_s2[i]=="u"  )
                        j++;
                    if(email_s2[i]=="v"  )
                        j++;
                    if(email_s2[i]=="w"  )
                        j++;
                    if(email_s2[i]=="x"  )
                        j++;
                    if(email_s2[i]=="y"  )
                        j++;
                    if(email_s2[i]=="z"  )
                        j++;
                    if(email_s2[i]=="0")
                        n++;
                    if(email_s2[i]=="1")
                        n++;
                    if(email_s2[i]=="2")
                        n++;
                    if(email_s2[i]=="3")
                        n++;
                    if(email_s2[i]=="4")
                        n++;
                    if(email_s2[i]=="5")
                        n++;
                    if(email_s2[i]=="6")
                        n++;
                    if(email_s2[i]=="7")
                        n++;
                    if(email_s2[i]=="8")
                        n++;
                    if(email_s2[i]=="9")
                        n++;
                    if(email_s2[i]=="@")
                      {
                        y=i;
                       x++;
                       if(i<9)
                           b=1;
                      }
                    if(email_s2[i]==".")
                    {
                        p++;
                        w=i;
                    }

            }
                for( h=y+1;h<w;h++)
                {
                    if(r!=1)
                    {
                        if(email_s2[h]==gmail1[t])
                        {
                            k++;
                            t++;
                            r=0;
                        }
                        else
                            r==1;
                    }
                    if(r2!=1)
                    {
                        if(email_s2[h]==gmail2[t2])
                        {
                            k2++;
                            t2++;
                            r2=0;
                        }
                        else
                            r2==1;
                    }
                }

                if(k>=4)
                    s=1;
                if(k2>=6)
                    s=1;

                if(w-y<5)
                    c=1;


                //application des conditions
                if(c1==1)
                    ui->c_1->setText("ID invalide");
                    else
                      ui->c_1->setText("");

                    if(j<8 || x==0 || x>1 || n<2 ||p==0||p>1||b==1||c==1||s!=1)
                    ui->c_5->setText("Email invalide");
                    else
                      ui->c_5->setText("");

                    if(c2==1)
                    ui->c_2->setText("Nom invalide");
                     else
                    ui->c_2->setText("");

                    if(c3==1)
                    ui->c_3->setText("Prenom invalide");
                     else
                    ui->c_3->setText("");
                    if(c4==1)
                    ui->c_4->setText("Adresse invalide");
                     else
                    ui->c_4->setText("");

                    if(c7==1)
                    ui->c7->setText("Spécialité invalide");
                     else
                    ui->c7->setText("");

                    if(c6==1)
                    ui->c_6->setText("Date non valide");
                      else
                    ui->c_6->setText("");

                    if(j<8 || x==0 || x>1 || n<2 ||p==0||p>1||b==1||c==1||s!=1||c1==1||c2==1||c3==1||c4==1||c4==1||c6==1||c7==1)
                       {
                          ajout=1;
                       }

                    if(ajout==0)
                    {
                       staff f(id_s, nom, prenom, tel_s, email_s, date_add_s, specialite_s, adresse_add_s);
                       test=f.ajouter_staff();

                       if(test)
                       {

                           ui->tablestaff->setModel(tmpstaff.afficher());

                           ui->txt_cin->setText("");
                           ui->txt_nom->setText("");
                           ui->txt_prenom->setText("");
                           ui->txt_num->setText("");
                           ui->txt_email->setText("");
                           ui->txt_spc->setText("");
                           ui->txt_adresse->setText("");


                           QMessageBox::information(nullptr, QObject::tr("staff ajouté"),
                                       QObject::tr("Ajout réussi\n"
                                                   "Clicker sur OK ."), QMessageBox::Accepted);
                      }






                    else
                           QMessageBox::critical(nullptr, QObject::tr("Pas d'ajout de staff"),
                                   QObject::tr("L'ajout du staff  est refusé.\n"
                                               "Clicker sur Abort ."), QMessageBox::Abort);


                    }

        //staff f(id_s, nom, prenom, tel_s, email_s, date_add_s, specialite_s, adresse_add_s);

       {test=f.ajouter_staff();}

       if(test) {

           ui->tablestaff->setModel(tmpstaff.afficher());

           ui->txt_cin->setText("");
           ui->txt_nom->setText("");
           ui->txt_prenom->setText("");
           ui->txt_num->setText("");
           ui->txt_email->setText("");
           ui->txt_spc->setText("");
           ui->txt_adresse->setText("");

           QMessageBox::information(nullptr, QObject::tr("staff ajouté"),
                       QObject::tr("Ajout réussi\n"
                                   "Clicker sur OK ."), QMessageBox::Accepted);


        }
        else {
           QMessageBox::critical(nullptr, QObject::tr("Pas d'ajout de staff"),
                   QObject::tr("L'ajout du staff  est refusé.\n"
                               "Clicker sur Abort ."), QMessageBox::Abort);
       }

    }


void MainWindow::on_pushButton_2_clicked()
{
    QItemSelectionModel *select = ui->tablestaff->selectionModel();
    int id_s1 =select->selectedRows(0).value(0).data().toInt();

    int id=ui->txt_id->text().toInt();
    QString nom1 = ui->txt_nom->text();
    QString nom1 = ui->txt_prenom->text();
    QDateTime date_add_s1=ui->dateEdit_2->dateTime();
    QString email_s1 = ui->txt_email_s->text();
    QString specialite_s1 = ui->txt_spc->text();
    QString adresse_add_s1 = ui->txt_adresse_s->text();
    staff tmpf(id_s1,nom1,prenom-s1,email_s1,date_add_s1,specialite_s1,adresse_add_s1);


    if(tmpf.modifier_staff())
    {
        ui->tablestaff->setModel(tmpstaff.afficher());
        ui->txt_id->setText("");
        ui->txt_nom->setText("");
        ui->txt_prenom->setText("");
        ui->txt_email_s->setText("");
        ui->txt_spc->setText("");
        ui->txt_adresse_s->setText("");*/

        ui->statusbar->showMessage("staff modifié");
     }
}

void MainWindow::on_pushButton_suppr_s_clicked()
{
    QItemSelectionModel *select = ui->tablestaff->selectionModel();
        int id_s =select->selectedRows(0).value(0).data().toInt();

        if(tmpstaff.supp_staff(id_s))
        {
            ui->tablestaff->setModel(tmpstaff.afficher());
            ui->statusbar->showMessage("staff supprimé");
         }

}

void MainWindow::on_pushButton_trier_staff_clicked()
{
    if(ui->radioButton_id->isChecked())
            {
                ui->tablestaff->setModel(tmpstaff.trier_id());
            }
            else if(ui->radioButton_nom->isChecked())
            {
                ui->tablestaff->setModel(tmpstaff.trier_nom());
            }
            else if(ui->radioButton_spec->isChecked())
            {
               ui->tablestaff->setModel(tmpstaff.trier_specialite());
            }
}

void MainWindow::on_sendEmail_2_clicked()
{
    QString host = ui->host_2->text();
        int port = ui->port_2->value();
        bool ssl = ui->ssl_2->isChecked();
        bool auth = ui->auth_2->isChecked();
        QString user = ui->username_2->text();
        QString password = ui->password_2->text();

        EmailAddress *sender = stringToEmail(ui->sender_2->text());

        QStringList rcptStringList = ui->recipients_2->text().split(';');

        QString subject = ui->subject_2->text();
        QString html = ui->texteditor_2->toHtml();

        SmtpClient smtp (host, port, ssl ? SmtpClient::SslConnection : SmtpClient::TcpConnection);

        MimeMessage message;

        message.setSender(sender);
        message.setSubject(subject);

        for (int i = 0; i < rcptStringList.size(); ++i)
             message.addRecipient(stringToEmail(rcptStringList.at(i)));

        MimeHtml content;
        content.setHtml(html);

        message.addPart(&content);

        for (int i = 0; i < ui->attachment->count(); ++i)
        {
            message.addPart(new MimeAttachment(new QFile(ui->attachment->item(i)->text())));
        }

        if (!smtp.connectToHost())
        {
            errorMessage("Connection Failed");
            return;
        }

        if (auth)
            if (!smtp.login(user, password))
            {
                errorMessage("Authentification Failed");
                return;
            }

        if (!smtp.sendMail(message))
        {
            errorMessage("Mail sending failed");
            return;
        }
        else
        {
            QMessageBox okMessage (this);
            okMessage.setText("The email was succesfully sent.");
            okMessage.exec();
        }

        smtp.quit();
}
void MainWindow::errorMessage(const QString &message)
{
    QErrorMessage err (this);

    err.showMessage(message);

    err.exec();
}
EmailAddress* MainWindow::stringToEmail(const QString &str)
{
    int p1 = str.indexOf("<");
    int p2 = str.indexOf(">");

    if (p1 == -1)
    {
        // no name, only email address
        return new EmailAddress(str);
    }
    else
    {
        return new EmailAddress(str.mid(p1 + 1, p2 - p1 - 1), str.left(p1));
    }

}

void MainWindow::on_rech_bouton_returnPressed()
{
    QString rech =ui->rech_bouton->text();
            ui->tablestaff->setModel(tmpstaff.rechercher(rech));
}

void MainWindow::on_rech_bouton_2_returnPressed()
{
    QString rech =ui->rech_bouton->text();
            ui->tablestaff->setModel(tmpstaff.rechercher(rech));
}
