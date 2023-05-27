//
// Created by user on 08.05.2023.
//

#include "Item.h"

[[maybe_unused]] void Item::setClass(Item::ItemClass item) {
    iClass = item;
}

[[maybe_unused]] Item::ItemClass Item::getClass() {
    return iClass;
}

Item::Item(int newId, const QPixmap& newImage, Item::ItemClass item, int x, int y) {
    id = newId;
    image = newImage;
    iClass = item;
    point.setX(x);
    point.setY(y);
}

QPoint Item::getPoint() {
    return point;
}
