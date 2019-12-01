//
// Created by alexandr on 11/24/19.
//
#include <iostream>
#include "Input.h"

Input::Input(const std::string _filepath ) : count(0), filepath(_filepath) {
    fin.open(filepath,std::ios::binary);
    if (!fin.is_open()) {
        std::cout << "file " << filepath << " cant be open" << std::endl;
        fin.close();
    }
}
Input::~Input() {
    fin.close();
}

size_t Input::GetFileSize() {
    return count;
}
void Input::RemoveFile() {
    const char *filep = filepath.c_str();
    std::remove(filep);
}


bool Input::Read(byte& value) {
    char buff;
    if (fin.read(&buff, sizeof(char))) {
        value = (unsigned char)buff;
        count++;
        return true;
    } else {
        return false;
    }
}


