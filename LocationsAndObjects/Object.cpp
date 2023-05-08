//
// Created by user on 08.05.2023.
//

#include "Object.h"

void Object::setImage(const QString& filePath) {
    image = QPixmap(filePath);
}

int Object::getId() const {
    return id;
}
