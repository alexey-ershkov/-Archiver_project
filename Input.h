//
// Created by alexandr on 11/24/19.
//

#ifndef PROTOTIPE_INPUT_H
#define PROTOTIPE_INPUT_H

#include <iostream>
#include <fstream>
#include "IInputStream.h"
#include "IGetFileSize.h"

typedef unsigned char byte;

class Input : public IInputStream, IGetFileSize {
private:
    std::string filepath;
    std::ifstream fin;
    size_t count;
public:
    Input(const std::string filepath);
    ~Input();
    void RemoveFile();
    size_t GetFileSize();
    bool Read(byte& value);


};


#endif //PROTOTIPE_INPUT_H
