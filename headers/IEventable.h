//
// Created by Алексей on 2019-11-07.
//

#ifndef ARCHIVER_IEVENTABLE_H
#define ARCHIVER_IEVENTABLE_H

#include "Event.h"

class IEventable {
public:
    virtual void takeEvent(Event) = 0;

    virtual ~IEventable() = default;
};


#endif //ARCHIVER_IEVENTABLE_H
