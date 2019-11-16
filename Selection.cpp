#include "Selection.h"

bool Selection::IsCompressionDataLessOriginal(DataIn data_for_compression, DataOut data_already_compressed){

    return true;
}

std::string Selection::GetAlgorithm(DataIn data_for_compression){
    std::string str = "Huffman";
    return str;
}

DataOut Selection::GetCompressedData(DataIn data_for_compression, std::string algorithm){
    DataOut some_data;
    return some_data;
}
DataOut Selection::GetDecompressed_data(DataIn data_for_compression, std::string algorithm){
    DataOut some_data;
    return some_data;
}
