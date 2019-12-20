//
// Created by Алексей on 2019-11-17.
//

#ifndef ARCHIVER_SHOW_H
#define ARCHIVER_SHOW_H


#include "IHandler.h"
#include "Archiver.hpp"
#include <stdexcept>

class Show : public IHandler<> {
public:
    ModelResponse<> handle(Request) override;
    bool can_handle(Request) override;
    virtual ~Show() {};
};


#endif //ARCHIVER_SHOW_H
