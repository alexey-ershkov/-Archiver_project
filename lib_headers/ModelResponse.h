//
// Created by Алексей on 04/12/2019.
//

#ifndef ARCHIVER_MODELRESPONSE_H
#define ARCHIVER_MODELRESPONSE_H

#include <string>
#include <vector>


template <typename T = std::vector<std::string>>
struct ModelResponse {
    enum module {archive, dearchive, show};
    enum status {ok, warning ,error};
    status state;
    module module;
    std::string info;
    T data;
};


#endif //ARCHIVER_MODELRESPONSE_H
