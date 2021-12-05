#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "matchs.h"
#include"sportifs.h"
#include"performance.h"
#include"statj.h"
#include"ui_statj.h"
#include "logement.h"
#include "terrains_de_jeux.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_6_clicked();

    void on_dateEdit_userDateChanged(const QDate &date);

    void on_calendarWidget_activated(const QDate &date);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_ajouter0_clicked();

    void on_modifier0_clicked();

    void on_excel_clicked();




    void on_pushButtonstats_clicked();

    void on_pushButtonpdf_clicked();

    void on_pushButtontri_clicked();

    void on_pushButtonajouter_clicked();


    void on_pushButtonsupp_clicked();

    void on_pushButtonmodifier0_clicked();
    void on_bouajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pushButtonmodifier_clicked();

    void on_aj_terrain_clicked();

    void on_tabWidget_2_currentChanged(int index);

    void on_pb_supprimer_terrain_clicked();


    void on_pushButtonmmodifier_clicked();



    void on_nom_rechercher_textEdited(const QString &arg1);

    void on_coor_rechercher_textEdited(const QString &arg1);

    void on_lineEdit_textEdited(const QString &arg1);

    void on_tridh_clicked();

private:
    Ui::MainWindow *ui;
    Etudiant Etmp0;
    SPORTIF Etmp;
    SPORTIF Etmp1;
    PERFORMANCE Etmp2;
    statj *stat_j;
    logement l;
    terrains_de_jeux t;


};

#endif // MAINWINDOW_H
