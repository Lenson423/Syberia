#ifndef UNTITLED2_INVENTORY_H
#define UNTITLED2_INVENTORY_H

#include "LocationsAndObjects/Item.h"

#include <QVector>

class Inventory {
private:
    QVector<Item> items;
public:
    Inventory() = default;

    void addItem(const Item &);

    void deleteItemWithId(int);

};


#endif //UNTITLED2_INVENTORY_H
