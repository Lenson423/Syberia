#ifndef UNTITLED2_ITEM_H
#define UNTITLED2_ITEM_H

#include "Object.h"

class Item : public Object {
public:
    enum ItemClass {
        Newspaper = 1,
        ForQuests
    };

    void setClass(ItemClass);
    ItemClass getClass();
    Item(int, const QPixmap&, ItemClass);
private:
    ItemClass iClass;
};


#endif //UNTITLED2_ITEM_H
