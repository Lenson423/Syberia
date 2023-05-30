#ifndef UNTITLED_EVENT_H
#define UNTITLED_EVENT_H

#include <QFile>
#include <QTextStream>
#include <QMap>
#include <QList>
#include <QDebug>

#include "Entity/NPC.h"
#include "workDirrectory/Inventory.h"
#include "workDirrectory/Controller.h"


class Event {
public:
    Event();
    void itemInfluentsOnNpc(int, NPC& npc);
    void npcInfluentsOnItem(int, int, Controller& inventory);
private:
    QMap<int, QMap<int, QList<QString>>> itemsAndDialogs;
    QMap<int, QMap<int, QVector<int>>> npcAndItems;
};

#endif //UNTITLED_EVENT_H
