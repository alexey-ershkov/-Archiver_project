//
// Created by Алексей on 2019-11-17.
//

#ifndef ARCHIVER_ENCODE_H
#define ARCHIVER_ENCODE_H


#include "IHandler.h"

class Encode : public IHandler {
public:
    void handle(Request) override;
    bool can_handle(Request) override;
};


#endif //ARCHIVER_ENCODE_H
