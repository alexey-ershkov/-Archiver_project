//
// Created by Алексей on 2019-11-17.
//


#include "Dearchive.h"
ModelResponse<> Dearchive::handle(Request request) {
    ModelResponse<> response;
    response.module = ModelResponse<>::dearchive;
    try {

    }
    catch (std::invalid_argument& exept) {
        response.state = ModelResponse<>::error;
        response.info = exept.what();
        return response;
    }
    catch(...) {
        response.state = ModelResponse<>::error;
        response.info = "Can't dearchive files";
        return response;
    }

    response.state  = ModelResponse<>::ok;
    response.info = "File(s) successfully dearchived";
    return response;
}

bool Dearchive::can_handle(Request request) {
    return request.type == Request::dearchive;
}