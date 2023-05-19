#include "Portal.h"

Portal::Portal(int id) {
    nextLocationId = id;
}

int Portal::getNextLocationId() {
    return nextLocationId;
}
