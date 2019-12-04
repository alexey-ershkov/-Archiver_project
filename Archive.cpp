//
// Created by Алексей on 2019-11-17.
//

#include "Archive.h"

ModelResponse<> Archive::handle(Request request) {
    std::cout << "Archive handle" << std::endl;
    ModelResponse<> response;
    response.state  = ModelResponse<>::ok;
    response.data.emplace_back("It can handle it");
    return response;
}

bool Archive::can_handle(Request request) {
    return request.type == Request::archive;
}