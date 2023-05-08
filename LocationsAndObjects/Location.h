#ifndef UNTITLED2_LOCATION_H
#define UNTITLED2_LOCATION_H

#include <QVector>
#include "../Entity/NPC.h"
#include "Block.h"

class Location {
private:
    QVector<NPC> npcList;
    QVector<QVector<Block>> blocks;
public:
    Location() = default;

    QVector<QVector<Block>> getBlocks();

    QVector<NPC> getNpc();

    void readInformationFromJson(const QString&); //ToDo

};


#endif //UNTITLED2_LOCATION_H
