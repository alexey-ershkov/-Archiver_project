//
// Created by Алексей on 2019-11-07.
//

#ifndef ARCHIVER_IVIEW_H
#define ARCHIVER_IVIEW_H


class IView {
public:
    virtual void update() = 0; // would be using to update QT interface

    virtual ~IView() = default;
};


#endif //ARCHIVER_IVIEW_H
