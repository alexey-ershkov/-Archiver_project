//
// Created by Алексей on 2019-11-17.
//

#include "Archive.h"

void Archive::handle(Request request) {
    std::cout << "Archive handle" << std::endl;
    // вызов функции архивации здесь
}

bool Archive::can_handle(Request request) {
    return request.type == Request::archive;
}