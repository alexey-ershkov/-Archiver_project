//
// Created by Алексей on 2019-11-07.
//

#include "headers/Presenter.h"

void Presenter::send_request(Request request) {
    for (auto it : handlers) {
        if (it->can_handle(request))
            it->handle(request);
    }
}
