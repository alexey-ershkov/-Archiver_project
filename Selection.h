#ifndef PROTOTIPE_SELECTION_H
#define PROTOTIPE_SELECTION_H

#include "Huffman.h"
#include "LZW.h"

struct DataIn{
    FILE *file;
    std::string type;
};

struct DataOut{
    FILE *file;
    std::string type;
};

class Selection{
public:

    std::string GetAlgorithm(DataIn data_for_compression);
    bool IsCompressionDataLessOriginal(DataIn data_for_compression, DataOut data_already_compressed);
    DataOut GetCompressedData(DataIn data_for_compression, std::string algorithm);
    DataOut GetDecompressed_data(DataIn data_for_compression, std::string algorithm);

private:
    // цепочка ответственности
    std::string name_of_algorithm;
};


#endif //PROTOTIPE_SELECTION_H
