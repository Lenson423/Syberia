//
// Created by user on 30.05.2023.
//

#include "Event.h"

void Event::itemInfluentsOnNpc(int id, NPC& npc) {
    if(itemsAndDialogs.contains(id)){
        if(itemsAndDialogs[id].contains(npc.getId())){
            QList<QString> tmp = itemsAndDialogs[id][npc.getId()];
            tmp.pop_front();
            npc.addDialog(std::pair<Dialog, QString>(Dialog(tmp), itemsAndDialogs[id][npc.getId()][0]));
        }
    }
}

Event::Event() {
    QFile file(":/level/itemInfluentsOnNpc");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    in.readLine();
    while(!in.atEnd()){
        QString line = in.readLine();
        QList<QString> tmpList = line.split("$");
        QMap<int, QList<QString>> tmpMap;
        for(int i = 1; i < tmpList.size();i += 2){
            tmpMap.insert(tmpList[i].toInt(), tmpList[i + 1].split("|"));
        }
        itemsAndDialogs.insert(tmpList[0].toInt(), tmpMap);
    }
    file.close();

    file.setFileName(":/level/npcInfluentsOnItem");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    in.setDevice(&file);
    in.readLine();
    while(!in.atEnd()){
        QString line = in.readLine();
        QList<QString> tmpList = line.split("$");
        QMap<int, QVector<int>> tmpMap;
        QVector<int> tmpVector;
        for(int i = 2; i < tmpList.size(); ++i){
            tmpVector.push_back(tmpList[i].toInt());
        }
        tmpMap.insert(tmpList[1].toInt(), tmpVector);
        npcAndItems.insert(tmpList[0].toInt(), tmpMap);
    }
    file.close();
}

void Event::npcInfluentsOnItem(int npcId, int dialogId, Controller &inventory) {
    if(npcAndItems.contains(npcId)){
        if(npcAndItems[npcId].contains(dialogId)){
            for(auto itemsId : npcAndItems[npcId][dialogId]){
                if(inventory.getInventory().findItemWithId(itemsId)){
                    inventory.deleteItemToInventory(itemsId);
                }
            }
        }
    }
}
