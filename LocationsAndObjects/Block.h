#ifndef UNTITLED2_BLOCK_H
#define UNTITLED2_BLOCK_H

#include <QSize>

#include "Object.h"

class Block : public Object {
public:
    Block(int, QPixmap, QSize);

    void setSize(QSize);

private:
    QSize size;
};


#endif //UNTITLED2_BLOCK_H
