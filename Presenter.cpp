//
// Created by Алексей on 2019-11-07.
//

#include <Message.h>
#include "headers/Presenter.h"


void Presenter::send_request(Request request, std::ostream& output) {
    for (auto it : handlers) {
        if (it->can_handle(request)) {
            ModelResponse<> response =  it->handle(request);
            if (response.state == ModelResponse<>::ok) {
                Message message;
                message.type = Message::ok;
                message.message_text = response.info;
                view_sender(message, output);
                if (!response.data.empty())
                    view_sender(response.data, output);
                return;
            }
        }
    }
    ////В случае нового вида возврата данных дописать здесь
    /// проход по вектору соответственных IHandle
    /// Request  - универсален и может обрабатыватьлся любым типом IHandle
}




