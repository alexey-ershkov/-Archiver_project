//
// Created by Алексей on 2019-11-07.
//

#ifndef ARCHIVER_IHANDLER_H
#define ARCHIVER_IHANDLER_H

#include "Request.h"

class IHandler {
public:
    virtual void handle(Request) = 0;
    virtual bool can_handle(Request) = 0;
    virtual ~IHandler() = default;
};


#endif //ARCHIVER_IHANDLER_H
