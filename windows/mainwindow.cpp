#include <QGridLayout>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    scene = new QGraphicsScene();
    view = new QGraphicsView(this);
    view->setScene(scene);
    scene->setSceneRect(0, 0, 900, 600);
    view->setGeometry(0, 0, 900, 600);
    QPixmap map(":/sources/menu_background.png");
    scene->setBackgroundBrush(QBrush(map));

    newGameButton = new QPushButton(view);
    newGameButton->setGeometry(50, 150, 255, 30);
    newGameButton->setStyleSheet("background-image: url(:/sources/new_game_button.png); ");
    connect(newGameButton, SIGNAL(clicked()), this, SLOT(onNewGameButtonClicked()));

    loadGameButton = new QPushButton(view);
    loadGameButton->setGeometry(50, 200, 255, 30);
    loadGameButton->setStyleSheet("background-image: url(:/sources/load_game_button.png); ");

    settingsButton = new QPushButton(view);
    settingsButton->setGeometry(50, 250, 255, 30);
    settingsButton->setStyleSheet("background-image: url(:/sources/settings_button.png); ");

    exitButton = new QPushButton(view);
    exitButton->setGeometry(50, 300, 255, 30);
    exitButton->setStyleSheet("background-image: url(:/sources/exit_button.png); ");
    connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));
    view->show();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event) {

}

void MainWindow::onNewGameButtonClicked() {
    gameWindow = new AnotherWindow();
    gameWindow->setFixedSize(845, 575);
    gameWindow->show();
    this->close();
}
