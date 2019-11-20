//
// Created by Алексей on 2019-11-20.
//

#ifndef HAFFMAN_HUFFMAN_H
#define HAFFMAN_HUFFMAN_H

#include <fstream>
#include <string>
#include <iostream>

typedef unsigned char byte;


class IInputStream {
public:
    virtual bool Read(byte& value) = 0;
};

class IOutputStream {
public:
    virtual void Write(byte value) = 0;
};

class IGetFileSize {
    virtual size_t GetFileSize() = 0;
};

class Input : public IInputStream, IGetFileSize {
private:
    std::ifstream fin;
    size_t count;
public:
    Input(const std::string filepath ) : count(0) {
        fin.open(filepath,std::ios::binary);
        if (!fin.is_open()) {
            std::cout << "file " << filepath << " cant be open" << std::endl;
            fin.close();
        }
    }
    ~Input() {
        fin.close();
    }

    size_t GetFileSize() {
        return count;
    }

    bool Read(byte& value) {
        char buff;
        if (fin.read(&buff, sizeof(char))) {
            value = (unsigned char)buff;
            count++;
            return true;
        } else {
            return false;
        }
    }


};

class Output : public  IOutputStream, IGetFileSize {
private:
    std::ofstream fout;
    size_t size = 0;
public:
    Output(std::string filepath) {
        fout.open(filepath, std::ios::binary);
        if (!fout.is_open()) {
            std::cout << "can't open or create file" << filepath << std::endl;
            fout.close();
        }
    }
    void Write(byte value) {
        char buff = (char)value;
        fout.write(&buff, sizeof(char));
        size++;
    }

    size_t GetFileSize() {
        return size;
    }

    ~Output() {
        fout.close();
    }
};

void Encode(IInputStream& original, IOutputStream& compressed);

void Decode(IInputStream& compressed, IOutputStream& original);

#endif //HAFFMAN_HUFFMAN_H
