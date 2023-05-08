//
// Created by user on 08.05.2023.
//

#include "Location.h"

QVector<QVector<Block>> Location::getBlocks() {
    return blocks;
}

QVector<NPC> Location::getNpc() {
    return npcList;
}

void Location::readInformationFromJson(const QString&) {

}
