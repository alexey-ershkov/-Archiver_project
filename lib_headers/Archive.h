//
// Created by Алексей on 2019-11-17.
//

#ifndef ARCHIVER_ARCHIVE_H
#define ARCHIVER_ARCHIVE_H


#include "IHandler.h"
#include "Selection.h"
#include <stdexcept>
#include "TypeIdentifier.hpp"

#include "Archiver.hpp"


class Archive : public IHandler<> {
public:
    ModelResponse<> handle(Request) override;
    bool can_handle(Request) override;
    std::string new_name (std::string &);
};


#endif //ARCHIVER_ARCHIVE_H
