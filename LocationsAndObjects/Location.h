#ifndef UNTITLED2_LOCATION_H
#define UNTITLED2_LOCATION_H

#include <QVector>
#include "../Entity/NPC.h"
#include "../level/Level.h"
#include "Block.h"
#include "Item.h"

class Location {
private:
    QVector<NPC> npcList;
    QVector<Item> itemList;
    QPolygonF border;
    QPixmap font;
    QVector<Portal> portals;
public:
    Location() = default;

    QPolygonF getBorder();

    QVector<NPC> getNpc();

    QHash<int, Item> getItem();

    QVector<Portal> getPortals();

    QPixmap getFont();

    void readInformationFromJson(int);

};


#endif //UNTITLED2_LOCATION_H
