//
// Created by Алексей on 2019-11-07.
//

#ifndef ARCHIVER_PRESENTER_H
#define ARCHIVER_PRESENTER_H


#include "IHandler.h"
#include "Encode.h"
#include "Decode.h"
#include "Archive.h"
#include "Dearchive.h"
#include "TypeCheck.h"

// TODO добавить сюда массив с обработчиками и проходиться по нему вместо того, чтобы сеттить следующего
class View;

class Presenter {
private:
    std::vector<IHandler*> handlers;
    View *view;
public:
    void send_request(Request);
    Presenter (View *input) : view(input) {
        auto encode  = new Encode;
        auto decode = new Decode;
        auto archive = new Archive;
        auto dearchive = new Dearchive;
        auto type_check = new TypeCheck;
        handlers.push_back(encode);
        handlers.push_back(decode);
        handlers.push_back(archive);
        handlers.push_back(dearchive);
        handlers.push_back(type_check);
    };

};




#endif //ARCHIVER_PRESENTER_H
