#ifndef UNTITLED2_ANOTHERWINDOW_H
#define UNTITLED2_ANOTHERWINDOW_H

#include <QMainWindow>
#include "SettingsWindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include <QTimer>
#include <QKeyEvent>
#include <QTime>
#include <QDir>
#include <QIODevice>

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
    void loadFile(const QString&);

protected:
    bool checkNpcPosition(NPC&);
    bool checkPortalPosition(Portal&);
    void saveFile();

    void mousePressEvent(QMouseEvent *) override;

    void paintEvent(QPaintEvent *event) override;

private:
    Ui::AnotherWindow *ui;
    SettingsWindow *settingsWindow;

    QTimer timer;

    Controller controller;

    enum Mode{
        Game = 0,
        Inventory,
        Dialog
    };

    int currentLevel = 1;
    bool isNeedToReload = false;
    bool inMoovements = false;
    Mode mode = Game;

    class Dialog currDialog;
    QPixmap screen;
private
    slots:

    void updatePicture();
    void keyPressEvent(QKeyEvent *) override;
    void keyReleaseEvent(QKeyEvent *) override;
    void loadCurrnetDialog();
};

#endif //UNTITLED2_ANOTHERWINDOW_H
