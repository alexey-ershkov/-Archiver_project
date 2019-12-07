//
// Created by alexandr on 11/24/19.
//

#ifndef PROTOTIPE_OUTPUT_H
#define PROTOTIPE_OUTPUT_H


#include <iostream>
#include <fstream>
#include "IOutputStream.h"

typedef unsigned char byte;

class Output : public  IOutputStream {
private:
    std::string filepath;
    std::ofstream fout;
    size_t size = 0;
public:
    void RemoveFile();
    Output(std::string _filepath);
    Output(const Output &input);
    ~Output();
    void Write(byte value);
    size_t GetFileSize();

};


#endif //PROTOTIPE_OUTPUT_H
