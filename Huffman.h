#ifndef PROTOTIPE_HUFFMAN_H
#define PROTOTIPE_HUFFMAN_H
#include <vector>

class Huffman {
public:

    std::vector<char> Compress(const std::vector<char>& data);
    std::vector<char> Decompress(const std::vector<char>& data);
};


#endif //PROTOTIPE_HUFFMAN_H
