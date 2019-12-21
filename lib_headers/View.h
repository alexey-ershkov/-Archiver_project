//
// Created by Алексей on 21/12/2019.
//

#ifndef ARCHIVER_VIEW_H
#define ARCHIVER_VIEW_H

#include <iostream>
#include "Message.h"

class View {
    virtual bool send_message (Message message, std::ostream&) = 0;
    virtual bool show_files (std::vector<std::string>, std::ostream&) = 0;
};

#endif //ARCHIVER_VIEW_H
