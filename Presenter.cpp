//
// Created by Алексей on 2019-11-07.
//

#include <Message.h>
#include "headers/Presenter.h"


void Presenter::send_request(Request request) {
    for (auto it : handlers) {
        if (it->can_handle(request)) {
            it->handle(request);
            std::vector<std::string> out;
            out.push_back("First");
            out.push_back("Second");
            view_sender(out);
        }
    }
}




