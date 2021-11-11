#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "logement.h"

#include <QMainWindow>

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
  void on_bouajouter_clicked();

  void on_pb_supprimer_clicked();

  void on_pushButtonmodifier_clicked();

private:
    Ui::MainWindow *ui;
    logement l;

};

#endif // MAINWINDOW_H
