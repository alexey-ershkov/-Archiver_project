//
// Created by Алексей on 2019-11-17.
//

#include "Show.h"

ModelResponse<> Show::handle(Request request) {
    std::cout << "Show handle" << std::endl;
    // вызов функции сжатия здесь
}

bool Show::can_handle(Request request) {
    return request.type == Request::show;
}
