//
// Created by Алексей on 2019-11-07.
//

#ifndef ARCHIVER_IEVENTABLE_H
#define ARCHIVER_IEVENTABLE_H

#include "Event.h"

class IEventable {
    virtual void TakeEvent(Event) = 0;
};


#endif //ARCHIVER_IEVENTABLE_H
