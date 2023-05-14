#ifndef UNTITLED2_LOCATION_H
#define UNTITLED2_LOCATION_H

#include <QVector>
#include "../Entity/NPC.h"
#include "Block.h"
#include "Item.h"

class Location {
private:
    QVector<NPC> npcList;
    QVector<Item> itemList;
    QPolygon border;
    QPixmap font;
public:
    Location() = default;

    QPolygon getBorder();

    QVector<NPC> getNpc();

    QVector<Item> getItem();

    QPixmap getFont();

    void readInformationFromJson(int); //ToDo

};


#endif //UNTITLED2_LOCATION_H
