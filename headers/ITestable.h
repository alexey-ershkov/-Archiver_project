//
// Created by Алексей on 2019-11-08.
//

#ifndef ARCHIVER_ITESTABLE_H
#define ARCHIVER_ITESTABLE_H

class ITestable {
public:
    virtual void testThrow() = 0;

    virtual ~ITestable() = default;
};

#endif //ARCHIVER_ITESTABLE_H
