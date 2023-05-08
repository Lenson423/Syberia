//
// Created by user on 07.05.2023.
//

#include "NPC.h"

NPC::NPC(QPointF pos, int newId, const QVector<Dialog>& dialog) {
    currentPosition = pos;
    id = newId;
    dialogs = dialog;
}

void NPC::addDialog(const Dialog& newDialog) {
    dialogs.push_back(newDialog);
}

QVector<Dialog> NPC::getDialogs() {
    return dialogs;
}
