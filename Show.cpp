//
// Created by Алексей on 2019-11-17.
//


#include "Show.h"

ModelResponse<> Show::handle(Request request) {
    ModelResponse<> response;
    response.module = ModelResponse<>::show;
    std::vector<std::string> filenames;
    try {
        Archiver archiver(request.archive_path
        );
        auto files = archiver.Read();
        for (auto file : files) {
            filenames.emplace_back(file.name);
        }
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
    response.data = filenames;
    return response;
}

bool Show::can_handle(Request request) {
    return request.type == Request::show;
}
