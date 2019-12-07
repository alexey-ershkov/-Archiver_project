//
// Created by Алексей on 2019-11-17.
//

#ifndef ARCHIVER_DEARCHIVE_H
#define ARCHIVER_DEARCHIVE_H


#include "IHandler.h"
#include <stdexcept>


class Dearchive : public IHandler<> {
public:
    ModelResponse<> handle(Request) override;
    bool can_handle(Request) override;
    virtual ~Dearchive() {};
};


#endif //ARCHIVER_DEARCHIVE_H
