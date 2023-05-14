#ifndef UNTITLED2_ANOTHERWINDOW_H
#define UNTITLED2_ANOTHERWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QPainter>
#include <QTimer>
#include <QKeyEvent>

#include "../workDirrectory/Controller.h"

namespace Ui {
    class AnotherWindow;
}

class AnotherWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit AnotherWindow(QWidget *parent = nullptr);
    ~AnotherWindow() override;

protected:

    void paintEvent(QPaintEvent *event) override;

private:
    Ui::AnotherWindow *ui;

    QTimer timer;

    Controller controller;

    int currentLevel = 1;

private
    slots:

    void updatePicture();
    void keyPressEvent(QKeyEvent *) override;
};

#endif //UNTITLED2_ANOTHERWINDOW_H
