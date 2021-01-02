//
// Created by Алексей on 2019-11-17.
//



#include "Archive.h"

ModelResponse<> Archive::handle(Request request) {
    ModelResponse<> response;
    response.module = ModelResponse<>::archive;
    try {
        std::map <std::string, std::string> files_to_archive;
        for (auto it : request.filenames) {
            Selection selection(TypeIdentifier::SignatureDetect(it));
            selection.Compress(it, new_name(it));
            files_to_archive.insert(std::make_pair(it, new_name(it)));
        }
        Archiver archiver(request.archive_path);
        archiver.Pack(files_to_archive, request.archive_path, request.archive_name);
        for (auto it : request.filenames) {
            Input input(new_name(it));
            input.RemoveFile();
        }
    }
    catch (std::invalid_argument& exept) {
        response.state = ModelResponse<>::error;
        response.info = exept.what();
        return response;
    }
    catch(...) {
        response.state = ModelResponse<>::error;
        response.info = "Невозможно заархивировать файлы";
        return response;
    }

    response.state  = ModelResponse<>::ok;
    response.info = "Файлы успешно заархивированы";
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
