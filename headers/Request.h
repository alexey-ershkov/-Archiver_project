//
// Created by Алексей on 2019-11-17.
//

#ifndef ARCHIVER_REQUEST_H
#define ARCHIVER_REQUEST_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

struct Request {
    enum request_type {show, archive, dearchive};
    request_type type;
    std::vector<std::string> filenames;
    std::unordered_multimap <std::string, std::string> types;
    std::string archive_name;
};

typedef struct Request Request;

#endif //ARCHIVER_REQUEST_H
