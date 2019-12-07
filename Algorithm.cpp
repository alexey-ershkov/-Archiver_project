#include "Algorithm.h"
using namespace std;

Algorithm::Algorithm() : compressionRatio(0) {

}

double Algorithm::Compress(Input input, Output output){

    Encode(input, output);
    std::cout << std::fixed;
    std::cout.precision(3);


    compressionRatio = (double)output.GetFileSize()/(double)input.GetFileSize();
    return compressionRatio;
}




void Algorithm::Decompress(Input input, Output output){
    Decode(input, output);

    input.RemoveFile();
}



double Algorithm::GetCompressionRatio() {
    return compressionRatio;
}

