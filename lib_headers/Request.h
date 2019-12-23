//
// Created by Алексей on 2019-11-17.
//

#ifndef ARCHIVER_REQUEST_H
#define ARCHIVER_REQUEST_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
struct Request {
    enum request_type {archive, dearchive, show};
    request_type type;
    std::vector<std::string> filenames;
    std::unordered_multimap <std::string, std::string> types;
    std::string archive_name;
    std::string archive_path;
};

typedef struct Request Request;

#endif //ARCHIVER_REQUEST_H
