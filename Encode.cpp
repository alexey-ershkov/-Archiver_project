//
// Created by Алексей on 2019-11-17.
//

#include "Encode.h"

void Encode::handle(Request request) {
    std::cout << "Encode handle" << std::endl;
    // вызов функции сжатия здесь
}

bool Encode::can_handle(Request request) {
    return request.type == Request::encode;
}
