#include <QMediaPlayer>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    auto* player = new QMediaPlayer;
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    player->setSource(QUrl("/music/grenada-grenada.mp3"));
    player->play();
}

MainWindow::~MainWindow() {
    delete ui;
}


