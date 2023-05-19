#include "Controller.h"
#include "../level/Level.h"

void Controller::addItemToInventory(const Item &item) {
    inventory.addItem(item);
}

void Controller::deleteItemToInventory(int id) {
    inventory.deleteItemWithId(id);
}

void Controller::loadNewLocation(int path) {
    Location location;
    location.readInformationFromJson(path);
    currentLocation = location;
    QString newPath = "level" + QString::number(path);
    Level level(newPath);
    person.setPosition(level.getPersonLocation());

}

Location Controller::getLocation() {
    return currentLocation;
}

Person &Controller::getPerson() {
    return person;
}

Inventory Controller::getInventory() {
    return inventory;
}

void Controller::addButtonForDialog(QRect rect) {
    buttonsForDialog.push_back(rect);
}

void Controller::clearButtonForDialog() {
    buttonsForDialog.clear();
}

QVector<QRect> Controller::getButtonsForDialog() {
    return buttonsForDialog;
}

void Controller::setDialogActivity(bool isActive) {
    dialogIsActive = isActive;
}

bool Controller::dialIsActive() {
    return dialogIsActive;
}

void Controller::setCurrentDialogNum(int num) {
    currentDialog = num;
}

int Controller::getDialogNum() {
    return currentDialog;
}

void Controller::setCurrentNpc(const NPC &npc) {
    currentNPC = npc;
}

NPC *Controller::getNpc() {
    return &currentNPC;
}
