//
// Created by Алексей on 2019-11-17.
//

#ifndef ARCHIVER_ARCHIVE_H
#define ARCHIVER_ARCHIVE_H


#include "IHandler.h"
#include <stdexcept>


class Archive : public IHandler<> {
public:
    ModelResponse<> handle(Request) override;
    bool can_handle(Request) override;
};


#endif //ARCHIVER_ARCHIVE_H
