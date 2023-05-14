#ifndef UNTITLED2_NPC_H
#define UNTITLED2_NPC_H

#include <QPixmap>
#include "Entity.h"
#include "../Dialog.h"

class NPC : public Entity {
private:
    QVector<Dialog> dialogs;
    QPixmap sprite;
public:
    NPC(QPointF, int, const QVector<Dialog>&, const QString&);

    void addDialog(const Dialog&);

    QVector<Dialog> getDialogs();

    QPixmap getSprite();
};


#endif //UNTITLED2_NPC_H
