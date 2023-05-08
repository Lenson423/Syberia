#ifndef UNTITLED2_ENTITY_H
#define UNTITLED2_ENTITY_H

#include <QPointF>

class Entity {
protected:
    QPointF currentPosition;
    int id{};

public:
    QPointF getPosition();

    void setPosition(QPointF);

    int getId();
};


#endif
