#include "Inventory.h"

void Inventory::addItem(const Item& newItem) {
    items.insert(newItem.getId(), newItem);
}

void Inventory::deleteItemWithId(int idToFind) {
    items.remove(idToFind);
}

bool Inventory::findItemWithId(int idToFind) {
    return items.contains(idToFind);
}
