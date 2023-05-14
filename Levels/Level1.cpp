#include "Level1.h"

QPointF Level1::getPersonLocation() {
    return {200, 300};
}

QVector<NPC> Level1::getNPC() {
    QVector<NPC> npc;
    QVector<QString> tmpDialog;
    tmpDialog.push_back(QString("Hello, Mr. Peterson"));
    tmpDialog.push_back(QString("Good morning..."));
    npc.push_back(NPC(QPointF{300, 300}, 0, QList<Dialog>{Dialog(tmpDialog)}, ":/sources/old_man.png"));
    return npc;
}

QPolygon Level1::getBorder() {
    return QPolygon(QList<QPoint>{{0,   131},
                                  {806, 131},
                                  {806,   496},
                                  {0, 496}});
}

QVector<Item> Level1::getItems() {
    return QVector<Item>{Item(0, QPixmap(":/sources/fance.png"), Item::ForQuests)};
}

QPixmap Level1::getFont() {
    return {":/sources/base.png"};
}
