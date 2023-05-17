//
// Created by user on 08.05.2023.
//

#include "Location.h"
#include "../level/Level.h"

QPolygon Location::getBorder() {
    return border;
}

QVector<NPC> Location::getNpc() {
    return npcList;
}

void Location::readInformationFromJson(int level) {
    QString path = "level" + QString::number(level);
    Level newLevel(path);
    border = newLevel.getBorder();
    npcList = newLevel.getNPC();
    itemList = newLevel.getItems();
    font = newLevel.getFont();
}

QVector<Item> Location::getItem() {
    return itemList;
}

QPixmap Location::getFont() {
    return font;
}
