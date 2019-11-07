//
// Created by Алексей on 2019-11-07.
//

#ifndef ARCHIVER_PRESENTOR_H
#define ARCHIVER_PRESENTOR_H


#include "IEventable.h"
#include "Event.h"
#include "IView.h"


class Presentor : IEventable {
private:
    std::set <IEventable*> archiver;
    std::set <IEventable*> compressor;
    std::set <IEventable*> filecheck;

    IView *view;

public:
    void TakeEvent(Event);

    Presentor(IView *input) : view(input) {};


    void Subscribe(IEventable* sub, Event::EventType type);
    void Unsubscribe(IEventable* sub, Event::EventType type);
    void SendEvent(const Event& event);

};


#endif //ARCHIVER_PRESENTOR_H
