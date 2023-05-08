#ifndef UNTITLED2_DIALOG_H
#define UNTITLED2_DIALOG_H

#include <QVector>
#include <QString>

class Dialog {
private:
    QVector<QString> replics;
public:
    explicit Dialog(QVector<QString>);

    void addReplic(const QString &);

    QVector<QString> getReplics();
};


#endif //UNTITLED2_DIALOG_H
