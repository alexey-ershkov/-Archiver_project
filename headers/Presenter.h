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
#include <memory>


class View;

class Presenter {
private:
    ////для обработки IHandle с другим типом данных просто добавляем новый вектор
    /// и определяем поведение в send_request
    /// в данной реализации хватает работы с ветором строк
    std::vector<std::shared_ptr<IHandler<>>> handlers;
    //не смог разрешить циклическую ссылку через shared_ptr и weak_ptr, т.к.
    // view удалаяется до обращения к нему по weak_ptr
    View *view;
public:

    Presenter (View *input) : view(input) {
        auto show  = std::make_shared<Show>();
        auto archive = std::make_shared<Archive>();
        auto dearchive = std::make_shared<Dearchive>();
        handlers.push_back(archive);
        handlers.push_back(dearchive);
        handlers.push_back(show);
    };
    void send_request(Request, std::ostream&);
    void view_sender(Message message, std::ostream&);
    void view_sender(std::vector<std::string>, std::ostream&);
};




#endif //ARCHIVER_PRESENTER_H
