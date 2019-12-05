//
// Created by Алексей on 2019-11-17.
//

#ifndef ARCHIVER_SHOW_H
#define ARCHIVER_SHOW_H


#include "IHandler.h"

class Show : public IHandler<> {
public:
    ModelResponse<> handle(Request) override;
    bool can_handle(Request) override;
};


#endif //ARCHIVER_SHOW_H
