#ifndef UNTITLED2_PERSON_H
#define UNTITLED2_PERSON_H

#include "Entity.h"

class Person : public Entity {
private:
    int speedX;
    int speedY;
public:
    Person(QPointF , int, int, int);
    void setNewSpeed(int, int);
};


#endif //UNTITLED2_PERSON_H
