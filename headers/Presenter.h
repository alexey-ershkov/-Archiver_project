//
// Created by Алексей on 2019-11-07.
//

#ifndef ARCHIVER_PRESENTER_H
#define ARCHIVER_PRESENTER_H


#include "IHandler.h"
#include "Show.h"
#include "Archive.h"
#include "Dearchive.h"


class View;

class Presenter {
private:
    std::vector<IHandler*> handlers;
    View *view;
public:
    void send_request(Request);
    Presenter (View *input) : view(input) {
        auto show  = new Show;
        auto archive = new Archive;
        auto dearchive = new Dearchive;
        handlers.push_back(archive);
        handlers.push_back(dearchive);
        handlers.push_back(show);
    };

};




#endif //ARCHIVER_PRESENTER_H
