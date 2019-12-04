//
// Created by Алексей on 04/12/2019.
//

#ifndef ARCHIVER_MESSAGE_H
#define ARCHIVER_MESSAGE_H

#include <string>

struct Message {
    enum message_type {success, warning, error};
    message_type type;
    std::string message_text;
};
typedef struct Message Message;
#endif //ARCHIVER_MESSAGE_H
