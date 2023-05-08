//
// Created by user on 08.05.2023.
//

#include "Item.h"

void Item::setClass(Item::ItemClass item) {
    iClass = item;
}

Item::ItemClass Item::getClass() {
    return iClass;
}

Item::Item(int newId, const QPixmap& newImage, Item::ItemClass item) {
    id = newId;
    image = newImage;
    iClass = item;
}
