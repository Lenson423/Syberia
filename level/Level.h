#ifndef UNTITLED2_LEVEL_H
#define UNTITLED2_LEVEL_H

#include "../Entity/NPC.h"
#include "../LocationsAndObjects/Item.h"
#include "../LocationsAndObjects/Portal.h"

#include <QFile>
#include <QUrl>
#include <QDebug>
#include <QPointF>
#include <QVector>
#include <QPolygon>

class Level {
private:
    QString path;

public:
    Level() = default;

    ~Level() = default;

    Level(const QString &);

    QPointF getPersonLocation();

    QVector<NPC> getNPC();

    QVector<Portal> getPortals();

    QPolygonF getBorder();

    QVector<Item> getItems();

    QPixmap getFont();
};


#endif //UNTITLED2_LEVEL_H
