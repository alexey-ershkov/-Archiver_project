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
public:
    Input(const Input &input);
    Input(const std::string _filepath);
    ~Input();
    std::string GetFilePath() override;
    std::ifstream fin;
    bool isFileOpenedSuccesful;
    bool isFileEmpty();
    void RemoveFile();
    size_t GetFileSize() override ;
    bool Read(byte& value);
    size_t GetCount() const;

private:
    std::string filepath;

    size_t count;
};


#endif //PROTOTIPE_INPUT_H
