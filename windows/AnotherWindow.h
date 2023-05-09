#ifndef UNTITLED2_ANOTHERWINDOW_H
#define UNTITLED2_ANOTHERWINDOW_H

#include <QMainWindow>

namespace Ui {
    class AnotherWindow;
}

class AnotherWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit AnotherWindow(QWidget *parent = 0);
    ~AnotherWindow();

signals:
    void firstWindow();  // Сигнал для первого окна на открытие

private slots:


private:
    Ui::AnotherWindow *ui;
};

#endif //UNTITLED2_ANOTHERWINDOW_H
