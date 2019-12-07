#ifndef PROTOTIPE_SELECTION_H
#define PROTOTIPE_SELECTION_H

#include "Huffman.h"
#include "LZW.h"
#include "Algorithm.h"



class Selection {
public:
    Selection(std::string _typeFile);
    ~Selection() = default;
    double Compress(std::string input_filepath, std::string output_filepath);
    void Decompress(std::string input_filepath, std::string output_filepath);
    std::string GetTypeFile();
    double GetCompressionRatio();
    std::string GetNameAlgorithm();

private:
    std::string name;
    std::shared_ptr<Algorithm> algo;
    std::string typeFile;
    std::string nameFileWithoutExtension;
    std::string comressedFileName;
    bool IsOrigLessCompr(double size_compressed_f, double size_origin_f);
    void Add(std::shared_ptr<Algorithm> chosen_alg);
    void ChooseAlgorithm();
    void SetDefaultAlg();
    // цепочка ответственности
    std::vector<std::shared_ptr<Algorithm>> arrayAlgos;
};


#endif //PROTOTIPE_SELECTION_H
