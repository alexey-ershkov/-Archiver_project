//
// Created by alexandr on 11/24/19.
//

#ifndef PROTOTIPE_OUTPUT_H
#define PROTOTIPE_OUTPUT_H


#include <iostream>
#include <fstream>
#include "IOutputStream.h"
#include "IGetFileSize.h"

typedef unsigned char byte;

class Output : public  IOutputStream, IGetFileSize {
private:
    std::string filepath;
    std::ofstream fout;
    size_t size = 0;
public:
    void RemoveFile();
    explicit Output(std::string _filepath);
    ~Output();
    void Write(byte value) override;
    size_t GetFileSize() override;

};


#endif //PROTOTIPE_OUTPUT_H
