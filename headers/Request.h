//
// Created by Алексей on 2019-11-17.
//

#ifndef ARCHIVER_REQUEST_H
#define ARCHIVER_REQUEST_H

#include <iostream>
#include <vector>
#include <string>

struct Request {
    enum request_type {encode,decode,add_files, type_check, archive, dearchive};
    FILE *file;
    std::vector<FILE*> to_archive;
    std::string file_type;
    request_type type;
};

#endif //ARCHIVER_REQUEST_H
