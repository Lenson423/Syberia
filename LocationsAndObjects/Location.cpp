//
// Created by user on 08.05.2023.
//

#include "Location.h"
#include "../Levels/Level1.h"

QPolygon Location::getBorder() {
    return border;
}

QVector<NPC> Location::getNpc() {
    return npcList;
}

void Location::readInformationFromJson(int level) {
    switch(level){
        case 1:
            border = Level1::getBorder();
            npcList = Level1::getNPC();
            itemList = Level1::getItems();
            font = Level1::getFont();
            break;
        default:
            break;
    }
}

QVector<Item> Location::getItem() {
    return itemList;
}

QPixmap Location::getFont() {
    return font;
}
