//
// Created by Алексей on 2019-11-07.
//

#ifndef ARCHIVER_PRESENTOR_H
#define ARCHIVER_PRESENTOR_H


#include "IEventable.h"
#include "Event.h"
#include "IView.h"
#include "ITestable.h"


class Presentor : public IEventable, ITestable {
private:
    std::set <IEventable*> archiver;
    std::set <IEventable*> compressor;
    std::set <IEventable*> filecheck;
    std::set <IEventable*> test;

    IView *view;

public:
    void takeEvent(Event);
    void testThrow();

    Presentor(IView *input) : view(input) {};



    void Subscribe(const IEventable* sub, Event::eventType type);
    void Unsubscribe(const IEventable* sub, Event::eventType type);
    void SendEvent(const Event& event);

};


#endif //ARCHIVER_PRESENTOR_H
