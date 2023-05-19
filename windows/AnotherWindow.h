#ifndef UNTITLED2_ANOTHERWINDOW_H
#define UNTITLED2_ANOTHERWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
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
    bool checkNpcPosition(NPC&);

protected:

    void mousePressEvent(QMouseEvent *) override;

    void paintEvent(QPaintEvent *event) override;

private:
    Ui::AnotherWindow *ui;

    QTimer timer;

    Controller controller;

    enum Mode{
        Game = 0,
        Inventory,
        Dialog
    };

    int currentLevel = 1;

    Mode mode = Game;

    class Dialog currDialog;
    QPixmap screen;
private
    slots:

    void updatePicture();
    void keyPressEvent(QKeyEvent *) override;
    void loadCurrnetDialog();
};

#endif //UNTITLED2_ANOTHERWINDOW_H
