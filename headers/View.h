//
// Created by Алексей on 2019-11-08.
//

#ifndef ARCHIVER_VIEW_H
#define ARCHIVER_VIEW_H


//жесткие и мягкие ссылки
//TODO преообразовать сигналы из вне в понятные презентеру и вызвать нужные методы

//TODO базовая реализация для работы интерфейса с библиотекой без qt

//TODO презентор должен иметь жестку ссылку на view , а view мягкую ссылку на презентер




#include "Presenter.h"

class View  {
private:

public:
    Presenter *presenter;
    View() {
      presenter = new Presenter(this);
    }

};


#endif //ARCHIVER_VIEW_H
