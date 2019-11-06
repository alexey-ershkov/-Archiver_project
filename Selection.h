#ifndef PROTOTIPE_SELECTION_H
#define PROTOTIPE_SELECTION_H

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
    Data_out GetCompressedData(DataIn data_for_compression, std::string algorithm);
    Data_out GetDecompressed_data(DataIn data_for_compression, std::string algorithm);

private:

    std::string name_of_algorithm;
};


#endif //PROTOTIPE_SELECTION_H
