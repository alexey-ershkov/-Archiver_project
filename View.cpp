//
// Created by Алексей on 2019-11-08.
//

#include "View.h"
#include "Presenter.h"

#define line std::cout << "\n==========================================\n\n"



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
            return update_action::CLOSE;
    }
}

update_action View::show_screen() {
    std::cout << "\nChoose action: \n"
                 "1) Choose archive file \n"
                 "2) Back \n" << std::endl;
    int select;
    std::cin >> select;
    //константы выбора
    while (select < 1 || select > 2)
    {
        send_message(selection_error);
        std::cin >> select;
    }
    if (select == 1) {
        auto archive_file = read_file();
        if (archive_file == "exit")
            return update_action::DEFAULT;
        else {
            Request request;
            request.type = Request::show;
            request.archive_name = archive_file;
            presenter->send_request(request);
        }
    }
    return update_action::DEFAULT;
}

update_action View::archive_screen() {
    std::cout << "\nChoose action: \n"
                 "1) Choose files to archive \n"
                 "2) Back \n" << std::endl;
    int select;
    std::cin >> select;
    //константы выбора
    while (select < 1 || select > 2)
    {
        send_message(selection_error);
        std::cin >> select;
    }
    if (select == 1) {
        std::vector<std::string> files = read_files();
        if (files [0] == "exit")
            return update_action::DEFAULT;
        ////Заполнение запроса
        Request request;
        request.type = Request::archive;
        request.filenames = files;
        presenter->send_request(request);
    }
    return update_action::DEFAULT;
}

update_action View::dearchive_screen() {
    std::cout << "\nChoose action: \n"
                 "1) Choose archive file \n"
                 "2) Back \n" << std::endl;
    int select;
    std::cin >> select;
    //константы выбора
    while (select < 1 || select > 2)
    {
        send_message(selection_error);
        std::cin >> select;
    }
    if (select == 1) {
        auto archive_file = read_file();
        if (archive_file == "exit")
            return update_action::DEFAULT;
        else {
            Request request;
            request.type = Request::dearchive;
            request.archive_name = archive_file;
            presenter->send_request(request);
        }
    }
    return update_action::DEFAULT;
}

update_action View::main_screen() {
    std::cout << "\nChoose action: \n"
                 "1) Show files in archive \n"
                 "2) Archive files \n"
                 "3) Dearchive files \n"
                 "4) Exit \n" << std::endl;
    int select;
    std::cin >> select;
    //константы выбора
    while (select < 1 || select > 4) {
        send_message(selection_error);
        std::cin >> select;
    }
    return (update_action)(select-1);
}

//// Фунции обработки ввода пользователя

std::vector<std::string> View::read_files() {
    std::cout << "Please write number of files:" << std::endl;
    size_t n = get_int();
    std::string buffer;
    std::vector<std::string> out;
    std::cout << "Please write path to files or \"exit\" to go back:" << std::endl;
    for (size_t i = 0; i < n; i++ ) {
      std::cin >> buffer;
      if (buffer  == "exit") {
          if (out.empty())
              out.push_back(buffer);
          else
              out[0] = buffer;
          return out;
      }
      Message message;
      message.type = Message::error;
      if (file_exists(buffer.c_str())) {
          out.push_back(buffer);
      } else {
          message.message_text = "File \"" + buffer + "\" doesn't exist and can't be\nadded to archive\n"
                                 + "input right path or \"exit\" to go back";
          send_message(message);
          n++;
      }
    }
    return out;
}

std::string View::read_file() {
    Message message;
    message.type = Message::error;
    message.message_text = "Write correct path to file or \"exit\" to go back";
    std::cout << "Please write path to file:" << std::endl;
    std::string out;
    std::cin>>out;
    while (!file_exists(out.c_str())) {
        send_message(message);
        std::cin >> out;
        if (out == "exit")
            return out;
    }
    return out;
}



//// Отбражение сообщений Presenter
void View::send_message(Message message) {
    line;
    switch (message.type) {
        case Message::ok:
            std::cout << "Success: " << message.message_text << std::endl;
            break;
        case Message::warning:
            std::cout << "Warning: " << message.message_text << std::endl;
            break;
        case Message::error:
            std::cout << "Error: " << message.message_text << std::endl;
            break;
    }
    line;
}

void View::show_files(std::vector<std::string> files) {
    int numeration = 1;
    line;
    std::cout << "These files are in archive:" <<  std::endl;
    for (auto file : files)
        std::cout << numeration++ <<") " << file << std::endl;
    line;
}

size_t View::get_int() {
    Message message;
    message.type = Message::error;
    message.message_text = "Input integer";
    size_t input;
    std::cin >> input;
    while (std::cin.fail()) {
        send_message(message);
        std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
        std::cin.ignore(32767,'\n'); //
        std::cin >> input;
    }
    return input;
}

View::View() {
        presenter = std::make_shared<Presenter>(this);
        selection_error.type = Message::error;
        selection_error.message_text = "Wrong selection. Please try again";
}

////Облочка над функциями для работы презентера, чтобы разрешить конфликт incomplete type

void Presenter::view_sender(Message message) {
    view->send_message(message);
}

void Presenter::view_sender(std::vector<std::string> input) {
    view->show_files(input);
}

