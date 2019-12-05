//
// Created by Алексей on 2019-11-07.
//

#include <Message.h>
#include "headers/Presenter.h"


void Presenter::send_request(Request request) {
    for (auto it : handlers) {
        if (it->can_handle(request)) {
            ModelResponse response =  it->handle(request);
            std::cout << response.state << std::endl;
            for (auto it : response.data)
                std::cout << it << std::endl;
        }
    }
    ////В случае нового вида возврата данных дописать здесь
    /// проход по вектору соответственных IHandle
    /// Request  - универсален и может обрабатыватьлся любым типом IHandle
}




