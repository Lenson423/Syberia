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
#include <QTemporaryDir>

#include "../music/Music.h"
#include "../workDirrectory/Controller.h"

namespace Ui {
    class AnotherWindow;
}

class AnotherWindow : public QMainWindow {
Q_OBJECT

public:
    explicit AnotherWindow(QWidget *parent = nullptr);

    ~AnotherWindow() override;

    void loadFile(const QString &);

protected:
    bool checkNpcPosition(NPC &);

    bool checkPortalPosition(Portal &);

    bool checkItemPosition(const QRect &);

    void saveFile();

    void mousePressEvent(QMouseEvent *) override;

    void paintEvent(QPaintEvent *event) override;

private:
    Ui::AnotherWindow *ui;
    SettingsWindow *settingsWindow;

    QTimer timer;
    QTimer dialogTimer;
    QTimer musicTimer;

    Controller controller;

    enum Mode {
        Game = 0,
        Inventory,
        Dialog,
        ViewingOfImage
    };

    int currentLevel = 1;
    bool isNeedToReload = false;
    bool inMoovements = false;
    Mode mode = Game;

    class Dialog currDialog;

    QPixmap screen;
    QTemporaryDir tempDir;
    static constexpr int LevelCount = 3;
    Item *tmpItem;
private
    slots:

    void updatePicture();

    void startMusic();

    void keyPressEvent(QKeyEvent *) override;

    void keyReleaseEvent(QKeyEvent *) override;

    void closeEvent(QCloseEvent *event) override;

    void loadCurrnetDialog();

    void startMusicEffect(const QString &);

    void nextDialog();
};

#endif //UNTITLED2_ANOTHERWINDOW_H
