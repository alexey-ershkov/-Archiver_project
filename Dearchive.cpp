//
// Created by Алексей on 2019-11-17.
//

#include "Dearchive.h"
void Dearchive::handle(Request request) {
std::cout << "Dearchive handle" << std::endl;
// вызов функции деархивации здесь
}

bool Dearchive::can_handle(Request request) {
    return request.type == Request::dearchive;
}