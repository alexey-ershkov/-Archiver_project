#ifndef PROTOTIPE_OUTBITSTREAM_H
#define PROTOTIPE_OUTBITSTREAM_H


class OutBitStream {
public:
    OutBitStream() = default;
    void WriteBit(unsigned char bit);
    void WriteByte(unsigned char byte);

    const unsigned char* GetBuffer() const;
    uint64_t GetBitsCount() const;
private:
    vector<unsigned  char> buffer;
    int bitsCount; /* Сколько бит записали уже */
};



#endif //PROTOTIPE_OUTBITSTREAM_H
