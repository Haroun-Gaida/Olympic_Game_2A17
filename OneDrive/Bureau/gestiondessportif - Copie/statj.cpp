#include "statj.h"
#include "ui_statj.h"

statj::statj(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statj)
{
    ui->setupUi(this);
}

statj::~statj()
{
    delete ui;
}
