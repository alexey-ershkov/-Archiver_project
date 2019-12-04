//
// Created by Алексей on 2019-11-07.
//

#include <Message.h>
#include "headers/Presenter.h"


void Presenter::send_request(Request request) {
    for (auto it : handlers) {
        if (it->can_handle(request)) {
            it->handle(request);
            //TODO реализовать общение между presenter и модулями (может есть смысл писать на try catch)
            //TODO расширить IHandle, что-то вроде функции response
        }
    }
}




