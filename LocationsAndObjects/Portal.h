#ifndef UNTITLED2_PORTAL_H
#define UNTITLED2_PORTAL_H

#include <QRect>

class Portal {
public:
    explicit Portal(int, QRect);
    int getNextLocationId();
    QRect getPortalBorder();
private:
    int nextLocationId;
    QRect portalBorder;
};


#endif //UNTITLED2_PORTAL_H
