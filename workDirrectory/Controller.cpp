#include "Controller.h"

void Controller::addItemToInventory(Item item) {
    inventory.addItem(item);
}

void Controller::deleteItemToInventory(int id) {
    inventory.deleteItemWithId(id);
}
