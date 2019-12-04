//
// Created by Алексей on 2019-11-08.
//

#include "headers/View.h"



update_action View::update(enum update_action action) {
    switch (action) {
        case SHOW:
            return show_screen();
        case ARCHIVE:
            return archive_screen();
        case DEARCHIVE:
            return dearchive_screen();
        case DEFAULT:
            return main_screen();
        default:
            std::cout << "error" << std::endl;
            return update_action::CLOSE;
    }
}

update_action View::show_screen() {
    std::cout << "Choose action: \n"
                 "1) Choose archive file \n"
                 "2) Back \n" << std::endl;
    int select;
    std::cin >> select;
    while (select < 1 || select > 2)
    {
        std::cout << "Wrong selection. Please try again" << std::endl;
        std::cin >> select;
    }
    if (select == 1) {
        //TODO сформировать запрос и проверить то, что принимает файл .tprk
    }
    return update_action::DEFAULT;
}

update_action View::archive_screen() {
    std::cout << "Choose action: \n"
                 "1) Choose files to archive \n"
                 "2) Back \n" << std::endl;
    int select;
    std::cin >> select;
    while (select < 1 || select > 2)
    {
        std::cout << "Wrong selection. Please try again" << std::endl;
        std::cin >> select;
    }
    if (select == 1) {
        std::vector<std::string> files = read_files();
        ////Заполнение запроса
        Request request;
        request.type = Request::archive;
        request.filenames = files;
        presenter->send_request(request);
        //TODO дописать формиррование запроса
    }
    return update_action::DEFAULT;
}

update_action View::dearchive_screen() {
    std::cout << "Choose action: \n"
                 "1) Choose archive file \n"
                 "2) Back \n" << std::endl;
    int select;
    std::cin >> select;
    while (select < 1 || select > 2)
    {
        std::cout << "Wrong selection. Please try again" << std::endl;
        std::cin >> select;
    }
    if (select == 1) {
        auto archive_file = read_file();
        if (archive_file == "exit")
            return update_action::DEFAULT;
        else {
            //TODO сформировать запрос и провреить, что .tprk
        }
    }
    return update_action::DEFAULT;
}

update_action View::main_screen() {
    std::cout << "Choose action: \n"
                 "1) Show files in archive \n"
                 "2) Archive files \n"
                 "3) Dearchive files \n"
                 "4) Exit \n" << std::endl;
    int select;
    std::cin >> select;
    while (select < 1 || select > 4) {
        std::cout << "Wrong selection. Please try again" << std::endl;
        std::cin >> select;
    }
    return (update_action)(select-1);
}

std::vector<std::string> View::read_files() {
    std::cout << "Please write number of files:" << std::endl;
    size_t n;
    std::cin >> n;
    std::string buffer;
    std::vector<std::string> out;
    std::cout << "Please write path to files:" << std::endl;
    for (size_t i = 0; i < n; i++ ) {
        std::cin >> buffer;
      if (file_exists(buffer.c_str())) {
          out.push_back(buffer);
      } else {
          std::cout << "file " << buffer << " doesn't exist and can't be added to archive" << std::endl;
          n++;
      }
    }
    return out;
}

std::string View::read_file() {
    std::cout << "Please write path to files:" << std::endl;
    std::string out;
    std::cin>>out;
    while (!file_exists(out.c_str())) {
        std::cout << "Write correct path to file or write \"exit\" to go back" << std::endl;
        std::cin >> out;
        if (out == "exit")
            return out;
    }
    return out;
}

void View::send_message(Message message) {
    switch (message.type) {
        case Message::success:
            std::cout << "Success: " << message.message_text << std::endl;
            break;
        case Message::warning:
            std::cout << "Warning: " << message.message_text << std::endl;
            break;
        case Message::error:
            std::cout << "Error: " << message.message_text << std::endl;
            break;
    }
}

void View::show_files(std::vector<std::string> files) {
    int numeration = 1;
    std::cout << "\n============================\n";
    std::cout << "These files are in archive:" <<  std::endl;
    for (auto file : files)
        std::cout << numeration++ <<") " << file << std::endl;
    std::cout << "============================\n\n";
}

////Облочка над функциями для работы презентера, чтобы разрешить конфликт incomplete type

void Presenter::view_sender(Message message) {
    view->send_message(message);
}

void Presenter::view_sender(std::vector<std::string> input) {
    view->show_files(input);
}

