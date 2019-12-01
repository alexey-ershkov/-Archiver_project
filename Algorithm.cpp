//
// Created by alexandr on 11/25/19.
//

#include "Algorithm.h"

Algorithm::Algorithm() : CompressionRatio(0), FlagCompare(false) {

}

void Algorithm::Compress(string input_filepath, string output_filepath){
    Input input(input_filepath);
    Output output(output_filepath);
    Encode(input, output);
    std::cout << std::fixed;
    std::cout.precision(3);

    /* В случае, если сжимать оказалось невыгодно */

    FlagCompare = IsOrigLessCompr((double)output.GetFileSize(), (double)input.GetFileSize());
    if(FlagCompare){
        output.RemoveFile();
        CompressionRatio = 1;
        cout << "The file already takes up a minimum of space" << endl;
        return;
    }


    CompressionRatio = (double)output.GetFileSize()/(double)input.GetFileSize();
    cout << CompressionRatio << endl;
}



bool Algorithm::IsOrigLessCompr(double size_compressed_f, double size_origin_f) {
    return (size_origin_f < size_compressed_f) ? true : false;
}


void Algorithm::Decompress(string input_filepath, string output_filepath){

    Input input(input_filepath);
    Output output(output_filepath);

    Decode(input, output);

    input.RemoveFile();
}


void Algorithm::CopyStream(IInputStream& input, IOutputStream& output){
    unsigned char value;
    while (input.Read(value))
    {
        output.Write(value);
    }
}

double Algorithm::GetCompressionRatio() {
    return CompressionRatio;
}

