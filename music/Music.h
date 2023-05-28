#ifndef UNTITLED2_MUSIC_H
#define UNTITLED2_MUSIC_H

#include <QProcess>
#include <QFileInfo>

class Music {
private:
    QProcess *_shell;
public:
    Music();

    void play(const QFileInfo &file);
};

#endif //UNTITLED2_MUSIC_H
