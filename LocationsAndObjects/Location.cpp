//
// Created by user on 08.05.2023.
//

#include "Location.h"

QPolygonF Location::getBorder() {
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
    portals = newLevel.getPortals();
}

QHash<int, Item> Location::getItem() {
    QHash<int, Item> result;
    for(const auto& elem : itemList){
        result.insert(elem.getId(), elem);
    }
    return result;
}

QPixmap Location::getFont() {
    return font;
}

QVector<Portal> Location::getPortals() {
    return portals;
}
