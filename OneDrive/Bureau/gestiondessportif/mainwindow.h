#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"etudiant.h"
#include"performance.h"
#include <QMainWindow>
#include <QDialog>
#include <QMainWindow>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QSortFilterProxyModel>
#include <QSqlError>
#include <QSystemTrayIcon>
#include <QDialog>
#include <QFile>
#include "dialog_email.h"





QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_ajouter0_clicked();

    void on_modifier0_clicked();

    void on_excel_clicked();

private:

    Ui::MainWindow *ui;

    SPORTIF Etmp;
    SPORTIF Etmp1;
    PERFORMANCE Etmp2;
    Dialog_email *dialog_email;


};
#endif // MAINWINDOW_H
