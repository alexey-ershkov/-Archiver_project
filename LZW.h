#ifndef PROTOTIPE_LZW_H
#define PROTOTIPE_LZW_H


class LZW {
public:
    LZW();
    ~LZW();
    std::vector<char> Compress(const std::vector<char>& data);
    std::vector<char> Decompress(const std::vector<char>& data);
private:
    std::vector<int> encode(const std::vector<char>& data);
    std::string decode(const std::vector<int>& data);

};


#endif //PROTOTIPE_LZW_H
