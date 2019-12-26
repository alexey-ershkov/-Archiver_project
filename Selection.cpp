#include <algorithm>
#include <memory>
#include <sstream>
#include "Selection.h"
using namespace std;

Selection::Selection(string _typeFile, vector<shared_ptr<Algorithm>> added_algos) : isActive(false), typeFile(_typeFile), compressionRatio(0), addedAlgos(std::move(added_algos)) {
    fout.open("selection.log");

}

void Selection::GetActive() {
    Add(shared_ptr<Huffman>(new Huffman));
    Add(shared_ptr<LZW>(new LZW));
    for(auto &it : addedAlgos){
        Add(it);
    }
    ChooseAlgorithm();
    isActive = true;
}

double Selection::Compress(string input_filepath, string output_filepath){
    if(!isActive){
        GetActive();
    }

    Input input(input_filepath);
    Output output(output_filepath);

    string Recovery = "Сжимаю файл " + input_filepath + " ...\n" ;
    fout << Recovery;

    algo->Compress(input, output); //getAlgo
    compressionRatio = algo->compressionRatio;

    string Recovering_success = "Сжал исходный файл в: " + output_filepath + "\n";
    fout << Recovering_success;

    if(IsOrigLessCompr((double)output.GetFileSize(), (double)input.GetFileSize())){
        fout << "Сжатый файл оказался больше исходного.\n";
        fout << "Удаляю сжатый файл.\n";
        output.RemoveFile();
        compressionRatio = 1;
    }

    std::ostringstream oss;
    oss << compressionRatio;
    string comprRat = "Коэффициент сжатия " + oss.str();
    fout << comprRat;

    return compressionRatio;
}

void Selection::Decompress(string input_filepath, string output_filepath){
    if(!isActive){
        GetActive();
    }
    string Recovery = "Восстанавливаю сжатый файл " + input_filepath + " ...\n";
    fout << Recovery;

    Input input(input_filepath);
    Output output(output_filepath);
    algo->Decompress(input, output);
    string Recovering_success = "Восстанавил сжатый файл: " + output_filepath + "\n";
    fout << Recovering_success;

}


void Selection::Add(shared_ptr<Algorithm> chosen_alg) {
    arrayAlgos.push_back(chosen_alg);
}

void Selection::SetDefaultAlg() {
    static shared_ptr<Huffman> huffman_algo(new Huffman);
    algo = huffman_algo;
    fout << "Выбрал алгоритм: ";
    fout << algo->GetName();
    fout << "\n";
}


void Selection::ChooseAlgorithm() {
    fout << "Выбираю алгоритм...\n";
    for (auto &it : arrayAlgos){
        if(it->ShouldChoose(typeFile)){
            algo = it;
            fout << "Выбрал алгоритм: ";
            fout << algo->GetName();
            fout << "\n";
            return;
        }
    }

    SetDefaultAlg();

}

string Selection::GetNameAlgorithm(){
    if(!isActive){
        GetActive();
    }
    return algo->GetName();
}

string Selection::GetTypeFile() {
    return typeFile;
}

bool Selection::IsOrigLessCompr(double size_compressed_f, double size_origin_f) {
    return (size_origin_f < size_compressed_f);
}

