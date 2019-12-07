#include "LZW.h"

using namespace std;

LZW::LZW(){

}

void LZW::Encode(IInputStream &original, IOutputStream &compressed) {
    CopyStream(original, compressed);
}

void LZW::Decode(IInputStream &compressed, IOutputStream &original) {
    CopyStream(compressed, original);
}

bool LZW::ShouldChoose(string type_file) {
    vector<string> Formats = {"png", "tiff", "jpg", "gif", "bmp"};
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


