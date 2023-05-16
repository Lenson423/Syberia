#ifndef UNTITLED2_LEVEL1_H
#define UNTITLED2_LEVEL1_H

#include "../Entity/NPC.h"
#include "../LocationsAndObjects/Item.h"

#include <QFile>
#include <QUrl>
#include <QDebug>
#include <QPointF>
#include <QVector>
#include <QPolygon>

class Level1 {
public:
    static QPointF getPersonLocation();

    static QVector<NPC> getNPC();

    static QPolygon getBorder();

    static QVector<Item> getItems();

    static QPixmap getFont();
};


#endif //UNTITLED2_LEVEL1_H
