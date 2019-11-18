//
// Created by Алексей on 2019-11-17.
//

#include "Decode.h"

bool Decode::can_handle(Request request) {
    return request.type == Request::decode;
}

void Decode::handle(Request request) {
    std::cout << "Decode handler" << std::endl;
    // вызов класс расжатия здесь
}
