#include "Level.h"

QPointF Level::getPersonLocation() {
    QString tmp1 = QString(":/level/") + path + QString("/") + path + QString("PersLoc");
    QFile file(tmp1);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QList<QString> tmp = in.readAll().split(" ");
    return {tmp[0].toDouble(), tmp[1].toDouble()};
}

QVector<NPC> Level::getNPC() {
    QVector<NPC> npc;
    QString tmp1 = QString(":/level/") + path + QString("/") + path + QString("NPC");
    QFile file(tmp1);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream input(&file);
    QList<QString> tmp = input.readAll().split("%");
    for (auto elem: tmp) {
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
            for (int i = 1; i < replics.size(); ++i) {
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

QPolygon Level::getBorder() {
    QString tmp1 = QString(":/level/") + path + QString("/") + path + QString("Border");
    QFile file(tmp1);
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

QVector<Item> Level::getItems() {
    return QVector<Item>{Item(0, QPixmap(":/sources/fance.png"), Item::ForQuests)};
}

QPixmap Level::getFont() {
    QString tmp1 = QString(":/level/") + path + QString("/") + path + QString("Font");
    QFile file(tmp1);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    return {in.readLine()};
}

Level::Level(const QString &newPath) {
    path = newPath;
}

QVector<Portal> Level::getPortals() {
    QVector<Portal> result;
    QString tmp1 = QString(":/level/") + path + QString("/") + path + QString("Portal");
    QFile file(tmp1);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        int nextLevel = line.toInt();
        in.flush();
        line = in.readLine();
        QList<QString> tmp = line.split(" ");
        result.push_back(Portal(nextLevel, QRect(tmp[0].toInt(), tmp[1].toInt(),
                                                 tmp[2].toInt(),tmp[3].toInt())));
    }
    return result;
}
