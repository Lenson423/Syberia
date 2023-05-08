//
// Created by user on 07.05.2023.
//

#include "Person.h"

Person::Person(QPointF newCurrentPosition, int newId, int newSpeedX, int newSpeedY) {
    currentPosition = newCurrentPosition;
    id = newId;
    speedX = newSpeedX;
    speedY = newSpeedY;
}

void Person::setNewSpeed(int newSpeedX, int newSpeedY) {
    speedX = newSpeedX;
    speedY = newSpeedY;
}
