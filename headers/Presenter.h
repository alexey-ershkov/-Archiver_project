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
#include "ModelResponse.h"
#include <map>


class View;

class Presenter {
private:
    ////для обработки IHandle с другим типом данных просто добавляем новый вектор
    /// и определяем поведение в send_request
    /// в данной реализации хватает работы с ветором строк
    std::vector<IHandler<>*> handlers;
    View *view; //TODO добавить умный указатели в проект
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
