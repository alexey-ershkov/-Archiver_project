//
// Created by alexandr on 11/24/19.
//

#ifndef PROTOTIPE_INPUT_H
#define PROTOTIPE_INPUT_H

#include <fstream>
#include "IInputStream.h"
#include <iostream>



typedef unsigned char byte;

class Input : public IInputStream {
private:
    std::string filepath;
    std::ifstream fin;
    size_t count;
public:

    Input(const Input &input);
    Input(const std::string _filepath);
    ~Input();
    bool isFileOpenedSuccesful;
    bool isFileEmpty();
    void RemoveFile();
    size_t GetFileSize();
    bool Read(byte& value);


};


#endif //PROTOTIPE_INPUT_H
