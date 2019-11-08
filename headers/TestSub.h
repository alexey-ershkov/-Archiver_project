//
// Created by Алексей on 2019-11-08.
//

#ifndef ARCHIVER_TESTSUB_H
#define ARCHIVER_TESTSUB_H


#include "IEventable.h"
#include <stdexcept>

class TestSub : public IEventable {
public:
    void takeEvent(Event event){
        throw std::invalid_argument{"that's okay"};
    };
};


#endif //ARCHIVER_TESTSUB_H
