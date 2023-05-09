#include "AnotherWindow.h"

#include "ui_anotherwindow.h"

AnotherWindow::AnotherWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::AnotherWindow)
{
    ui->setupUi(this);
}

AnotherWindow::~AnotherWindow()
{
    delete ui;
}

