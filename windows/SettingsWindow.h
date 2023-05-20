#ifndef UNTITLED2_SETTINGSWINDOW_H
#define UNTITLED2_SETTINGSWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SettingsWindow; }
QT_END_NAMESPACE

class SettingsWindow : public QMainWindow {
Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = nullptr);

    ~SettingsWindow() override;

private:
    Ui::SettingsWindow* ui;

};

#endif
