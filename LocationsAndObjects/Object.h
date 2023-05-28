#ifndef UNTITLED2_OBJECT_H
#define UNTITLED2_OBJECT_H

#include <QPixmap>
#include <QString>

class Object {
protected:
    int id;
    QPixmap image;
public:
    void setImage(const QString &);

    QPixmap getImage();

    [[nodiscard]] int getId() const;
};


#endif //UNTITLED2_OBJECT_H
