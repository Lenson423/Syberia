//
// Created by user on 07.05.2023.
//

#include "Entity.h"

QPointF Entity::getPosition() {
    return currentPosition;
}

void Entity::setPosition(QPointF pos) {
    currentPosition = pos;
}

int Entity::getId() {
    return id;
}
