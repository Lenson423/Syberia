#ifndef UNTITLED2_CONTROLLER_H
#define UNTITLED2_CONTROLLER_H

#include <QVector>
#include <QRect>
#include "../Inventory.h"
#include "../Entity/Person.h"
#include "../LocationsAndObjects/Location.h"

class Controller {
private:
    Inventory inventory;
    Person person{QPointF(0, 0), 0, 1, 1};
    Location curentLocation;

    QVector<QRect> buttonsForDialog;
    bool dialogIsActive = false;
    int currentDialog = 0;
    NPC currentNPC;

public:
    void setCurrentNpc(const NPC&);
    NPC* getNpc();
    void addItemToInventory(const Item&);
    void deleteItemToInventory(int);
    void loadNewLocation(int);
    void addButtonForDialog(QRect);
    void clearButtonForDialog();
    void setDialogActivity(bool);
    void setCurrentDialogNum(int);

    QVector<QRect> getButtonsForDialog();
    Location getLocation();
    Person& getPerson();
    Inventory getInventory();
    bool dialIsActive();
    int getDialogNum();

public:

};


#endif //UNTITLED2_CONTROLLER_H
