#include <algorithm>
#include <memory>
#include "Selection.h"
using namespace std;

Selection::Selection(string _typeFile) : typeFile(_typeFile), compressionRatio(0) {


    Add(shared_ptr<Huffman>(new Huffman));
    Add(shared_ptr<LZW>(new LZW));

    ChooseAlgorithm(); // getActive
}


double Selection::Compress(string input_filepath, string output_filepath){
    Input input(input_filepath);
    Output output(output_filepath);

    algo->Compress(input, output); //getAlgo
    compressionRatio = algo->compressionRatio;

    if(IsOrigLessCompr((double)output.GetFileSize(), (double)input.GetFileSize())){
        output.RemoveFile();
        compressionRatio = 1;
    }
    cout << compressionRatio << endl;
    return compressionRatio;
}

void Selection::Decompress(string input_filepath, string output_filepath){
    Input input(input_filepath);
    Output output(output_filepath);
    algo->Decompress(input, output);

}


void Selection::Add(shared_ptr<Algorithm> chosen_alg) {
    arrayAlgos.push_back(chosen_alg);
}

void Selection::SetDefaultAlg() {
    static shared_ptr<Huffman> huffman_algo(new Huffman);
    algo = huffman_algo;
}


void Selection::ChooseAlgorithm() {
    for (auto &it : arrayAlgos){
        if(it->ShouldChoose(typeFile)){
            algo = it;
            return;
        }
    }
     SetDefaultAlg();

}

string Selection::GetNameAlgorithm(){
   return algo->GetName();
}

string Selection::GetTypeFile() {
    return typeFile;
}

bool Selection::IsOrigLessCompr(double size_compressed_f, double size_origin_f) {
    return (size_origin_f < size_compressed_f);
}

