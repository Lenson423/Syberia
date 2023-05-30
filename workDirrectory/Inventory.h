#ifndef UNTITLED2_INVENTORY_H
#define UNTITLED2_INVENTORY_H

#include "../LocationsAndObjects/Item.h"

#include <QHash>

class Inventory {
private:
    QHash<int, Item> items;
public:
    Inventory() = default;
    ~Inventory() = default;

    QHash<int, Item>  getItems();
    void addItem(const Item &);
    bool findItemWithId(int);
    void deleteItemWithId(int);

};


#endif //UNTITLED2_INVENTORY_H
