#include "Block.h"

#include <utility>


void Block::setSize(QSize newSize) {
    size = newSize;
}

Block::Block(int newId, QPixmap newImage, QSize newSize) {
    id = newId;
    image = std::move(newImage);
    size = newSize;
}
