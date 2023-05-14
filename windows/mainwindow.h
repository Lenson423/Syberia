#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPushButton>

#include "AnotherWindow.h"
#include "../workDirrectory/Controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QGraphicsScene* scene;

    QGraphicsView* view;

    QPushButton* newGameButton;
    QPushButton* loadGameButton;
    QPushButton* settingsButton;
    QPushButton* exitButton;

    AnotherWindow *gameWindow;
protected:

    void paintEvent(QPaintEvent *event) override;

private slots:
    void onNewGameButtonClicked();
};

#endif // MAINWINDOW_H
