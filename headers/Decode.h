//
// Created by Алексей on 2019-11-17.
//

#ifndef ARCHIVER_DECODE_H
#define ARCHIVER_DECODE_H


#include "IHandler.h"

class Decode : public IHandler {
public:
    void handle(Request) override;
    bool can_handle(Request) override;
};


#endif //ARCHIVER_DECODE_H
