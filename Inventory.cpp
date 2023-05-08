#include "Inventory.h"

void Inventory::addItem(const Item& newItem) {
    items.push_back(newItem);
}

void Inventory::deleteItemWithId(int idToFind) {
    for(auto it = items.begin(); it < items.end(); ++it){
        if ((*it).getId() == idToFind){
            items.erase(it);
        }
    }
}
