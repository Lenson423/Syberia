#ifndef UNTITLED2_CONTROLLER_H
#define UNTITLED2_CONTROLLER_H

#include "../Inventory.h"
#include "../Entity/Person.h"
#include "../LocationsAndObjects/Location.h"

class Controller {
private:
    Inventory inventory;
    Person person{QPointF(0, 0), 0, 1, 1};
    Location curentLocation;

public:
    void addItemToInventory(Item);
    void deleteItemToInventory(int);

public:

};


#endif //UNTITLED2_CONTROLLER_H
