//
// Created by Алексей on 2019-11-17.
//

#include "TypeCheck.h"

void TypeCheck::handle(Request request) {
    std::cout << "TypeCheck handle" << std::endl;
    // вызов функции проверки типа здесь
}

bool TypeCheck::can_handle(Request request) {
    return request.type == Request::type_check;
}
