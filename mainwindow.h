#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QSqlTableModel>
#include <QFileDialog>
#include <QDir>
#include <QTextStream>
#include <QWidget>
#include "staff.h"
#include "connexion.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = QMainWindow);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_suppr_f_clicked();

    void on_pushButton_trier_fournisseur_clicked();

    void on_sendEmail_2_clicked();

    void on_rech_bouton_returnPressed();

    void on_rech_bouton_2_returnPressed();

private:
    Ui::MainWindow *ui;
    staff s;
    QSqlTableModel *model;
    staff tmpstaff;
    forfait tmpforfait;
};
#endif // MAINWINDOW_H
