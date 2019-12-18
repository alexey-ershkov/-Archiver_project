//
// Created by Алексей on 2019-11-17.
//

#include "Dearchive.h"
ModelResponse<> Dearchive::handle(Request request) {
    ModelResponse<> response;
    response.module = ModelResponse<>::dearchive;
    std::string filename = "../media/UML.bin";
    try {
        Selection selection("png");
        selection.Decompress(filename, name_without_extention(filename)+"."+"png");

        ////Вызов алгоритмов деархивации
        /// и расжатия
    }
    catch (std::invalid_argument& exept) {
        response.state = ModelResponse<>::error;
        response.info = exept.what();
        return response;
    }
    catch(...) {
        response.state = ModelResponse<>::error;
        response.info = "Can't dearchive files";
        return response;
    }

    response.state  = ModelResponse<>::ok;
    response.info = "File(s) successfully dearchived";
    return response;
}

bool Dearchive::can_handle(Request request) {
    return request.type == Request::dearchive;
}

std::string Dearchive::name_without_extention(std::string CompressedFileName) {
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


    std::string out =  NameFileWithoutExtension;

    return out;
}
