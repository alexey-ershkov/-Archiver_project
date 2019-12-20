//
// Created by Алексей on 2019-11-17.
//


#include "Show.h"

ModelResponse<> Show::handle(Request request) {
    ModelResponse<> response;
    response.module = ModelResponse<>::show;
    std::vector<std::string> out;

    Archiver archiver;
     auto filenames = archiver.Read(request.archive_name);

     for (auto file : filenames) {
         auto size = file.end - file.start;
         out.emplace_back(file.name + "   " + std::to_string(size));
     }
    //Заглушка для списка файлов
    std::vector<std::string> fake_filenames = {"File1", "File2", "File3", "File4", "File5"};
    try {
        ////Вызов функции показа файлов
    }
    catch (std::invalid_argument& exept) {
        response.state = ModelResponse<>::error;
        response.info = exept.what();
        return response;
    }
    catch(...) {
        response.state = ModelResponse<>::error;
        response.info = "Can't show files";
        return response;
    }

    response.state  = ModelResponse<>::ok;
    response.info = "File(s) successfully showed";
    response.data = fake_filenames;
    return response;
}

bool Show::can_handle(Request request) {
    return request.type == Request::show;
}
