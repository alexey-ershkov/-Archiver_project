#include "LZW.h"

using namespace std;

LZW::LZW(std::vector<std::string> should_choose_formats){
    Formats = {"png", "tiff", "jpg", "gif", "bmp"};
    for(auto &it : should_choose_formats ){
        Formats.push_back(it);
    }
}

void LZW::Encode(IInputStream &original, IOutputStream &compressed) {
    CopyStream(original, compressed);
}

void LZW::Decode(IInputStream &compressed, IOutputStream &original) {
    CopyStream(compressed, original);
}

bool LZW::ShouldChoose(string type_file) {
    auto it = find(Formats.begin(), Formats.end(), type_file);
    if(it != Formats.end()) {
        return true;
    }
    else {
        return false;
    }
}

string LZW::GetName() {
    return "LZW";
}

void LZW::CopyStream(IInputStream& input, IOutputStream& output){
    unsigned char value;
    while (input.Read(value))
    {
        output.Write(value);
    }
}


