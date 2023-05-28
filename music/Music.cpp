//
// Created by user on 23.05.2023.
//

#include "Music.h"

Music::Music() {
    this->_shell = new QProcess();
    this->_shell->setProgram("powershell");
    this->_shell->start();
}

void Music::play(const QFileInfo &file) {
    this->_shell->write(
            QString("(New-Object Media.SoundPlayer '" + file.absoluteFilePath() + "').Play()\r\n").toUtf8());
}
