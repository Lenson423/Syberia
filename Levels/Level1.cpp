#include "Level1.h"

QPointF Level1::getPersonLocation() {
    QFile file(":/level/level1/level1PersLoc.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QList<QString> tmp = in.readAll().split(" ");
    return {tmp[0].toDouble(), tmp[1].toDouble()};
}

QVector<NPC> Level1::getNPC() {
    QVector<NPC> npc;
    QFile file(":/level/level1/level1NPC");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream input(&file);
    QList<QString> tmp = input.readAll().split("%");
    for(auto elem : tmp){
        QTextStream in(&elem);

        QString image = in.readLine();
        in.flush();

        QString coordinates = in.readLine();
        in.flush();

        int id = in.readLine().toInt();
        in.flush();

        QList<std::pair<Dialog, QString>> pairs;
        while (!in.atEnd()) {
            QString line = in.readLine();
            QVector<QString> replic;
            QList<QString> replics = line.split("|");
            QString title = replics[0];
            for(int i = 1; i < replics.size(); ++i){
                replic << replics[i];
            }
            pairs.push_back(std::pair<Dialog, QString>{Dialog(replic), title});
            in.flush();
        }
        npc.push_back(NPC(QPointF(coordinates.split(" ")[0].toDouble(),
                                  coordinates.split(" ")[1].toDouble()), id, pairs, image));
    }

    return npc;
}

QPolygon Level1::getBorder() {
    QFile file(":/level/level1/level1Border");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QList<QPoint> vertex;
    while (!in.atEnd()) {
        QString line = in.readLine();
        vertex.push_back(QPoint(line.split(" ")[0].toInt(), line.split(" ")[1].toInt()));
        in.flush();
    }
    return QPolygon(vertex);
}

QVector<Item> Level1::getItems() {
    return QVector<Item>{Item(0, QPixmap(":/sources/fance.png"), Item::ForQuests)};
}

QPixmap Level1::getFont() {
    QFile file(":/level/level1/level1Font");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    return {in.readLine()};
}
