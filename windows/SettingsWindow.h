#ifndef UNTITLED2_SETTINGSWINDOW_H
#define UNTITLED2_SETTINGSWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QMouseEvent>

#define ORGANIZATION_NAME "SYBERIA"
#define ORGANIZATION_DOMAIN "www.syberia.org"
#define APPLICATION_NAME "QSettings Program"

QT_BEGIN_NAMESPACE
namespace Ui { class SettingsWindow; }
QT_END_NAMESPACE

class SettingsWindow : public QMainWindow {
Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = nullptr);

    ~SettingsWindow() override;

private:
    Ui::SettingsWindow *ui;

    void paintEvent(QPaintEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;
};

#endif
