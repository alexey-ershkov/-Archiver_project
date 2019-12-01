#include "OutBitStream.h"

OutBitStream::OutBitStream(): bitsCount(0) {

}

void OutBitStream::WriteBit(unsigned char bit) {
    if(bitsCount + 1 > buffer.size() * 8)
        buffer.push_back(0);

    if(bit != 0){
        buffer[bitsCount / 8] = buffer[bitsCount / 8] | 1 << (bitsCount % 8);   // типа +=
    }

    ++bitsCount;
}



void OutBitStream::WriteByte(unsigned char byte) {
    if(bitsCount % 8 == 0){
        buffer.push_back(byte);
    } else{
        int offset = bitsCount % 8; // сколько занято
        buffer[bitsCount / 8] = buffer[bitsCount / 8] | byte << offset;
        buffer.push_back(byte >> (8 - offset));
    }
    bitsCount += 8;
}

const unsigned char *OutBitStream::GetBuffer() const {
    return nullptr;
}