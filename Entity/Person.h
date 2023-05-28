#ifndef UNTITLED2_PERSON_H
#define UNTITLED2_PERSON_H

#include "Entity.h"

class Person : public Entity {
private:
    int speedX = 0;
    int speedY = 0;
public:
    Person(QPointF, int, int, int);

    void setNewSpeed(int, int);

    std::pair<int, int> getSpeed();
};


#endif //UNTITLED2_PERSON_H
