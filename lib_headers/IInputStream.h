//
// Created by alexandr on 11/24/19.
//

#ifndef PROTOTIPE_IINPUTSTREAM_H
#define PROTOTIPE_IINPUTSTREAM_H
typedef unsigned char byte;

class IInputStream {
public:
    virtual bool Read(byte& value) = 0;
};


#endif //PROTOTIPE_IINPUTSTREAM_H
