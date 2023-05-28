//
// Created by user on 07.05.2023.
//

#include "NPC.h"

NPC::NPC(QPointF pos, int newId, const QVector <std::pair<Dialog, QString>> &dialog, const QString &file) {
    currentPosition = pos;
    id = newId;
    dialogs = dialog;
    sprite = QPixmap(file);
}

void NPC::addDialog(const std::pair <Dialog, QString> &newDialog) {
    dialogs.push_back(newDialog);
}

QVector <std::pair<Dialog, QString>> NPC::getDialogs() {
    return dialogs;
}

QPixmap NPC::getSprite() {
    return sprite;
}
