//
// Created by Алексей on 2019-11-20.
//

#include "Huffman.h"

void EncodeInput (std::string input_filepath, std::string output_filepath) {
    Input input(input_filepath);
    Output output(output_filepath);
    Encode(input, output);
    std::cout << std::fixed;
    std::cout.precision(3);
    std::cout << (double)output.GetFileSize()/(double)input.GetFileSize() << std::endl;
}

void DecodeInput (std::string input_filepath, std::string output_filepath) {
    Input input(input_filepath);
    Output output(output_filepath);
    Decode(input, output);
}

int main () {
    EncodeInput("../files_to_encode/text.txt", "../files_to_encode/text.bin");
    DecodeInput("../files_to_encode/text.bin", "../decoded_files/text.txt");
    EncodeInput("../files_to_encode/street.jpg", "../files_to_encode/street.bin");
    DecodeInput("../files_to_encode/street.bin", "../decoded_files/decode.jpg");
    return 0;
}