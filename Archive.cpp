//
// Created by Алексей on 2019-11-17.
//


#include "Archive.h"

ModelResponse<> Archive::handle(Request request) {
    ModelResponse<> response;
    response.module = ModelResponse<>::archive;
    try {
        for (auto it : request.filenames) {
            Selection selection("text");
            selection.Compress(it, new_name(it));
        }
    }
    catch (std::invalid_argument& exept) {
        response.state = ModelResponse<>::error;
        response.info = exept.what();
        return response;
    }
    catch(...) {
        response.state = ModelResponse<>::error;
        response.info = "Can't archive files";
        return response;
    }

    response.state  = ModelResponse<>::ok;
    response.info = "File(s) successfully archived";
    return response;
}

bool Archive::can_handle(Request request) {
    return request.type == Request::archive;
}

std::string Archive::new_name(std::string &CompressedFileName) {

    std::string TypeFile;
    std::string NameFileWithoutExtension;

    bool flag = false;
    for(auto it = CompressedFileName.end(); it >= CompressedFileName.begin(); it--){
        if(*it == '.' and !flag){
            flag = true;
            continue;
        }

        if(!flag){
            TypeFile.append(1, *it);
        }

        if(flag){
            NameFileWithoutExtension.append(1, *it);
        }
    }

    std::reverse(TypeFile.begin(), TypeFile.end());
    std::reverse(NameFileWithoutExtension.begin(), NameFileWithoutExtension.end());


    std::string out =  NameFileWithoutExtension + ".bin";

    return out;
}
