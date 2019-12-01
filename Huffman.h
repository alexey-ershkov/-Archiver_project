#ifndef PROTOTIPE_HUFFMAN_H
#define PROTOTIPE_HUFFMAN_H
#include <vector>

class Huffman {
public:
    Huffman() = default;
    ~Huffman() = default;
    std::vector<char> Compress(const std::vector<char>& data);
    std::vector<char> Decompress(const std::vector<char>& data);
private:
    std::vector<int> encode(const std::vector<char>& data);
    std::string decode(const std::vector<int>& data);
    int dictSize;
    char emptyBits;
    std::vector<char> SaveDict();
/*PMPL*/
};


#endif //PROTOTIPE_HUFFMAN_H
