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
    QPolygon border;
    QPixmap font;
    QVector<Portal> portals;
public:
    Location() = default;

    QPolygon getBorder();

    QVector<NPC> getNpc();

    QVector<Item> getItem();

    QVector<Portal> getPortals();

    QPixmap getFont();

    void readInformationFromJson(int);

};


#endif //UNTITLED2_LOCATION_H
