//
// Created by Алексей on 2019-11-07.
//

#ifndef ARCHIVER_PRESENTER_H
#define ARCHIVER_PRESENTER_H

#include "Archive.h"
#include "Dearchive.h"
#include "IHandler.h"
#include <map>
#include "Message.h"
#include <memory>
#include "ModelResponse.h"
#include "Show.h"





class View;

class Presenter {
private:
    std::vector<std::shared_ptr<IHandler<>>> handlers;
    View *view;
public:
    Presenter (View *input) : view(input) {
        add_handler(std::make_shared<Dearchive>());
        add_handler(std::make_shared<Archive>());
        add_handler (std::make_shared<Show>());
    };
    ///Добавление handlers снаружи
    bool add_handler (std::shared_ptr<IHandler<>> );
    void send_request(Request, std::ostream&);
    void view_sender(Message message, std::ostream&);
    void view_sender(std::vector<std::string>, std::ostream&);
};




#endif //ARCHIVER_PRESENTER_H
