#include "Controller.h"
#include "../Levels/Level1.h"

void Controller::addItemToInventory(const Item& item) {
    inventory.addItem(item);
}

void Controller::deleteItemToInventory(int id) {
    inventory.deleteItemWithId(id);
}

void Controller::loadNewLocation(int path) {
    Location location;
    location.readInformationFromJson(path);
    curentLocation = location;
    switch(path){
        case 1:
            person.setPosition(Level1::getPersonLocation());
            break;
        default:
            break;
    }
}

Location Controller::getLocation() {
    return curentLocation;
}

Person& Controller::getPerson() {
    return person;
}

Inventory Controller::getInventory() {
    return inventory;
}
