//
// Created by Алексей on 2019-11-07.
//

#ifndef ARCHIVER_PRESENTER_H
#define ARCHIVER_PRESENTER_H


#include "IHandler.h"
#include "Show.h"
#include "Archive.h"
#include "Dearchive.h"
#include "Message.h"


class View;

class Presenter {
private:
    std::vector<IHandler*> handlers;
    View *view;
public:

    Presenter (View *input) : view(input) {
        auto show  = new Show;
        auto archive = new Archive;
        auto dearchive = new Dearchive;
        handlers.push_back(archive);
        handlers.push_back(dearchive);
        handlers.push_back(show);
    };
    void send_request(Request);
    void view_sender(Message message);
    void view_sender(std::vector<std::string>);
};




#endif //ARCHIVER_PRESENTER_H
