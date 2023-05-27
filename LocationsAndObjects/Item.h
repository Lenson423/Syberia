#ifndef UNTITLED2_ITEM_H
#define UNTITLED2_ITEM_H

#include "Object.h"

class Item : public Object {
public:
    enum ItemClass {
        Newspaper = 1,
        ForQuests = 2
    };

    [[maybe_unused]] void setClass(ItemClass);
    QPoint getPoint();

    [[maybe_unused]] ItemClass getClass();
    Item() = default;
    ~Item() = default;
    Item(int, const QPixmap&, ItemClass, int, int);
private:
    ItemClass iClass;
    QPoint point;
};


#endif //UNTITLED2_ITEM_H
