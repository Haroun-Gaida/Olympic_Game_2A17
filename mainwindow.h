#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "sport.h"
#include "equipe.h"
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
    void on_confirmer_clicked();

    void on_supprimer_clicked();

    void on_modifier_pushutton_clicked();

    void on_confirmer_equipe_clicked();

    void on_supprimer_Equipe_clicked();

    void on_modifier_equipe_clicked();

    void on_tab_classement_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    Sport S;
    Equipe E;
};

#endif // MAINWINDOW_H
