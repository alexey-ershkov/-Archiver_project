#ifndef PROTOTIPE_SELECTION_H
#define PROTOTIPE_SELECTION_H

#include "Huffman.h"
#include "LZW.h"
#include "Algorithm.h"



class Selection {
public:
    Selection(string _TypeFile);
    ~Selection() = default;
    void Compress(string input_filepath, string output_filepath);
    void Decompress(string input_filepath, string output_filepath);
    string GetTypeFile();
    double GetCompressionRatio();
    string GetNameAlgorithm();

private:
    string Name;
    Algorithm *Algo;
    string TypeFile;
    string NameFileWithoutExtension;
    string ComressedFileName;
    void Add(unique_ptr<Algorithm> chosen_alg);
    void ChooseAlgorithm();
    void SetDefaultAlg();
    // цепочка ответственности
    vector<unique_ptr<Algorithm>> ArrayAlgos;
};


#endif //PROTOTIPE_SELECTION_H
