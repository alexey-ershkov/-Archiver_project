#include "LZW.h"

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
    for(auto &it : Formats){
        if(type_file == it){
            return true;
        }
    }
    return false;
}

string LZW::GetName() {
    return "LZW";
}



