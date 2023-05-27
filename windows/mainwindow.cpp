#include <QGridLayout>
#include <QFileDialog>
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

    newGameButton = new QPushButton(view);
    newGameButton->setGeometry(50, 150, 255, 30);
    connect(newGameButton, SIGNAL(clicked()), this, SLOT(onNewGameButtonClicked()));

    loadGameButton = new QPushButton(view);
    loadGameButton->setGeometry(50, 200, 255, 30);
    connect(loadGameButton, SIGNAL(clicked()), this, SLOT(onLoadGameButtonClicked()));

    settingsButton = new QPushButton(view);
    settingsButton->setGeometry(50, 250, 255, 30);
    connect(settingsButton, SIGNAL(clicked()), this, SLOT(settingsButtonClicked()));

    exitButton = new QPushButton(view);
    exitButton->setGeometry(50, 300, 255, 30);
    connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));
    view->show();
    repaint();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPixmap map(":/sources/menu_background.png");
    scene->setBackgroundBrush(QBrush(map));

    newGameButton->setStyleSheet("background-image: url(:/sources/new_game_button.png); ");
    loadGameButton->setStyleSheet("background-image: url(:/sources/load_game_button.png); ");
    settingsButton->setStyleSheet("background-image: url(:/sources/settings_button.png); ");
    exitButton->setStyleSheet("background-image: url(:/sources/exit_button.png); ");
}

void MainWindow::onNewGameButtonClicked() {
    gameWindow = new AnotherWindow();
    gameWindow->setFixedSize(845, 575);
    gameWindow->show();
    this->close();
}

void MainWindow::onLoadGameButtonClicked() {
    gameWindow = new AnotherWindow();
    gameWindow->setFixedSize(845, 575);
    QString filename = QFileDialog::getOpenFileName(
            this,
            tr("Sensor data"),
            "C//",
            "All Files (*.syb)"
    );
    gameWindow->loadFile(filename);
    gameWindow->show();
    this->close();
}

void MainWindow::settingsButtonClicked() {
    settingsWindow = new SettingsWindow();
    settingsWindow->setFixedSize(400, 300);
    settingsWindow->show();
}
