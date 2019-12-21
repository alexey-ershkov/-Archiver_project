//
// Created by Алексей on 2019-11-07.
//

#include <Message.h>
#include "Presenter.h"


void Presenter::send_request(Request request, std::ostream& output) {
    for (auto it : handlers) {
        if (it->can_handle(request)) {
            ModelResponse<> response =  it->handle(request);
            Message message;
            if (response.state == ModelResponse<>::ok) {
                message.type = Message::ok;
                message.message_text = response.info;
                view_sender(message, output);
                if (!response.data.empty())
                    view_sender(response.data, output);
            } else {
                message.type = Message::error;
                message.message_text = response.info;
                view_sender(message, output);
                if (!response.data.empty())
                    view_sender(response.data, output);
            }
        }
    }
    ////В случае нового вида handlers (в данной реализации один вид) данных дописать здесь
    /// проход по вектору соответственных IHandle
    /// Request  - универсален и может обрабатыватьлся любым типом IHandle
}


bool Presenter::add_handler(std::shared_ptr<IHandler<>> input) {
    try {
        handlers.push_back(input);
    }
    catch (...) {
        return false;
    }
    return true;
}

