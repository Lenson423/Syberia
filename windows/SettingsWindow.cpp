#include <QPainter>
#include "SettingsWindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::SettingsWindow) {
    ui->setupUi(this);
    repaint();
}

SettingsWindow::~SettingsWindow() {
    delete ui;
}

void SettingsWindow::paintEvent(QPaintEvent *event) {
    QSettings settings(ORGANIZATION_NAME, APPLICATION_NAME);

    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/sources/settings_fone.png"));
    if (settings.value("Language") == "Russian") {
        painter.drawPixmap(35, 95, QPixmap(":/sources/golden_border.png"));
    } else if (settings.value("Language") == "English") {
        painter.drawPixmap(235, 95, QPixmap(":/sources/golden_border.png"));
    }
    painter.drawPixmap(40, 100, QPixmap(":/sources/Russia_flag.png"));
    painter.drawPixmap(240, 100, QPixmap(":/sources/UK_USA_flag.png"));
}

void SettingsWindow::mousePressEvent(QMouseEvent *event) {
    QSettings settings(ORGANIZATION_NAME, APPLICATION_NAME);
    if (QRect(40, 100, 120, 80).contains(event->pos())) {
        settings.setValue("Language", "Russian");
        QLocale::setDefault(QLocale("ru_RU"));
    } else if (QRect(240, 100, 120, 80).contains(event->pos())) {
        settings.setValue("Language", "English");
        QLocale::setDefault(QLocale("en_EN"));
    }
    repaint();
}
