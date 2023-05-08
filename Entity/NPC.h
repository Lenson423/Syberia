#ifndef UNTITLED2_NPC_H
#define UNTITLED2_NPC_H

#include "Entity.h"
#include "../Dialog.h"

class NPC : public Entity {
private:
    QVector<Dialog> dialogs;
public:
    NPC(QPointF, int, const QVector<Dialog>&);

    void addDialog(const Dialog&);

    QVector<Dialog> getDialogs();
};


#endif //UNTITLED2_NPC_H
