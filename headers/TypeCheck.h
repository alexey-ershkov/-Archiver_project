//
// Created by Алексей on 2019-11-17.
//

#ifndef ARCHIVER_TYPECHECK_H
#define ARCHIVER_TYPECHECK_H


#include "IHandler.h"

class TypeCheck : public IHandler {
public:
    void handle(Request) override;
    bool can_handle(Request) override;
};


#endif //ARCHIVER_TYPECHECK_H
