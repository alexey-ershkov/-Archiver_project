//
// Created by Алексей on 2019-11-17.
//

#include "Archive.h"

ModelResponse<> Archive::handle(Request request) {
    ModelResponse<> response;
    response.module = ModelResponse<>::archive;
    try {
        ////Вызов алгоритмов на проверку типа данных
        /// Сжатия
        /// И Архивации
    }
    catch (std::invalid_argument& exept) {
        response.state = ModelResponse<>::error;
        response.info = exept.what();
        return response;
    }
    catch(...) {
        response.state = ModelResponse<>::error;
        response.info = "Can't archive files";
        return response;
    }

    response.state  = ModelResponse<>::ok;
    response.info = "File(s) successfully archived";
    return response;
}

bool Archive::can_handle(Request request) {
    return request.type == Request::archive;
}