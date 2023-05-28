#ifndef UNTITLED2_NPC_H
#define UNTITLED2_NPC_H

#include <QPixmap>
#include "Entity.h"
#include "../workDirrectory/Dialog.h"

class NPC : public Entity {
private:
    QVector<std::pair<Dialog, QString>> dialogs;
    QPixmap sprite;
public:
    NPC() = default;
    ~NPC() = default;
    NPC(QPointF, int, const QVector<std::pair<Dialog, QString>>&, const QString&);

    void addDialog(const std::pair<Dialog, QString>&);

    QVector<std::pair<Dialog, QString>> getDialogs();

    QPixmap getSprite();
};


#endif //UNTITLED2_NPC_H
