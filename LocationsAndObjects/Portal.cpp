#include "Portal.h"

Portal::Portal(int id, QRect rect) {
    nextLocationId = id;
    portalBorder = rect;
}

int Portal::getNextLocationId() {
    return nextLocationId;
}

QRect Portal::getPortalBorder() {
    return portalBorder;
}
