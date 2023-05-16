#include "Dialog.h"
#include <utility>

Dialog::Dialog(QVector<QString> newDialog) {
    replics = std::move(newDialog);
}

void Dialog::addReplic(const QString &replic) {
    replics.push_back(replic);
}

QVector<QString> Dialog::getReplics() {
    return replics;
}

int Dialog::getCurrentStep() {
    return currentStep;
}

void Dialog::inkCurrentStep() {
    currentStep +=  1;
}

void Dialog::eraseCurrentStep() {
    currentStep = 0;
}
