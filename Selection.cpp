#include <algorithm>
#include <memory>
#include "Selection.h"

Selection::Selection(string _TypeFile) : TypeFile(_TypeFile) {

    unique_ptr<Huffman> huffman_alg(new Huffman);
    Add(std::move(huffman_alg));
    unique_ptr<LZW> lzw_alg(new LZW);
    Add(std::move(lzw_alg));

    ChooseAlgorithm();
}


void Selection::Compress(string input_filepath, string output_filepath){
    Algo->Compress(input_filepath, output_filepath);

}

void Selection::Decompress(string input_filepath, string output_filepath){
    Algo->Decompress(input_filepath, output_filepath);

}

double Selection::GetCompressionRatio() {
    return Algo->CompressionRatio;
}


void Selection::Add(unique_ptr<Algorithm> chosen_alg) {
    ArrayAlgos.push_back(std::move(chosen_alg));
}

void Selection::SetDefaultAlg() {
    static unique_ptr<Huffman> huffman_algo(new Huffman);
    Algo = std::move(huffman_algo.get());
}


void Selection::ChooseAlgorithm() {
    for (auto &it : ArrayAlgos){
        if(it->ShouldChoose(TypeFile)){
            Algo = it.get(); // it имеет тип unique_ptr
            return;
        }
    }
     /* Если ни один из алгоритмов не подходит под файл попробуем сжать по хаффману, т.к. он относительно универсальный */
     SetDefaultAlg();

}

string Selection::GetNameAlgorithm(){
   return Algo->GetName();
}

string Selection::GetTypeFile() {
    return TypeFile;
}


