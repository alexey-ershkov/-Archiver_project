#ifndef PROTOTIPE_HUFFMAN_H
#define PROTOTIPE_HUFFMAN_H

#include "Algorithm.h"


struct Node
{
    unsigned char c;
    int freq;
    Node * left;
    Node * right;
    Node() {}
    Node(char c) : c(c), left(0), right(0) {}
    Node (Node * left, Node * right) : c(0), left(left), right(right) {}
    Node(char c, int freq, Node * left = 0, Node * right = 0) : right(right), c(c), left(left), freq(freq) {
    }
    ~Node() {
        delete left;
        delete right;
    }
};

struct nodeComparator
{
    bool operator ()(const Node * left, const Node * right) const
    {
        return left->freq < right->freq;
    }
};

class Huffman : public Algorithm {
public:
    Huffman();
    ~Huffman() = default;
    bool ShouldChoose(string type_file) override;
    string GetName();
private:
    void buildTable(Node * root, vector<bool> & bits, map<char, vector<bool> >  & code);
    void WriteTree(Node * root, IOutputStream& compressed);
    Node * ReadTree(IInputStream& compressed);
    void Encode(IInputStream& original, IOutputStream& compressed);
    void Decode(IInputStream& compressed, IOutputStream& original);
/*PMPL*/
};


#endif //PROTOTIPE_HUFFMAN_H
