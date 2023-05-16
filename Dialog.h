#ifndef UNTITLED2_DIALOG_H
#define UNTITLED2_DIALOG_H

#include <QVector>
#include <QString>

class Dialog {
private:
    QVector<QString> replics;

    int currentStep = 0;
public:
    Dialog() = default;
    ~Dialog() = default;
    explicit Dialog(QVector<QString>);

    void addReplic(const QString &);

    QVector<QString> getReplics();

    int getCurrentStep();

    void inkCurrentStep();

    void eraseCurrentStep();
};


#endif //UNTITLED2_DIALOG_H
