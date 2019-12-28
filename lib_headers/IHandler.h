//
// Created by Алексей on 2019-11-07.
//

#ifndef ARCHIVER_IHANDLER_H
#define ARCHIVER_IHANDLER_H

#include "ModelResponse.h"
#include "Request.h"



template <typename T = std::vector<std::string>>
class IHandler {
public:
    virtual ModelResponse<T> handle(Request) = 0;
    virtual bool can_handle(Request) = 0;
    virtual ~IHandler() = default;
};




#endif //ARCHIVER_IHANDLER_H
