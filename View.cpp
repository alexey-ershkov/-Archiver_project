//
// Created by Алексей on 2019-11-08.
//

#include "View.h"
#include "Presenter.h"

#define line "\n====================================================================================\n\n"



update_action View::update(enum update_action action, std::istream& input, std::ostream& output) {
    switch (action) {
        case SHOW:
            return show_screen(input, output);
        case ARCHIVE:
            return archive_screen(input, output);
        case DEARCHIVE:
            return dearchive_screen(input, output);
        case DEFAULT:
            return main_screen(input, output);
        default:
            return update_action::CLOSE;
    }
}

update_action View::show_screen(std::istream& input, std::ostream& output) {
    output << "\nChoose action: \n"
                 "1) Choose archive file \n"
                 "2) Back \n" << std::endl;
    int select;
    input >> select;
    //константы выбора
    while (select < 1 || select > 2)
    {
        send_message(selection_error, output);
        input >> select;
    }
    if (select == 1) {
        auto archive_file = read_file(input, output);
        if (archive_file == "exit")
            return update_action::DEFAULT;
        else {
            Request request;
            request.type = Request::show;
            request.archive_name = archive_file;
            presenter->send_request(request,output);
        }
    }
    return update_action::DEFAULT;
}

update_action View::archive_screen(std::istream& input, std::ostream& output) {
    output << "\nChoose action: \n"
                 "1) Choose files to archive \n"
                 "2) Back \n" << std::endl;
    int select;
    input >> select;
    //константы выбора
    while (select < 1 || select > 2)
    {
        send_message(selection_error, output);
        input >> select;
    }
    if (select == 1) {
        std::vector<std::string> files = read_files(input, output);
        if (files [0] == "exit")
            return update_action::DEFAULT;
        ////Заполнение запроса
        Request request;
        request.type = Request::archive;
        request.filenames = files;
        presenter->send_request(request, output);
    }
    return update_action::DEFAULT;
}

update_action View::dearchive_screen(std::istream& input, std::ostream& output) {
    output << "\nChoose action: \n"
                 "1) Choose archive file \n"
                 "2) Back \n" << std::endl;
    int select;
    input >> select;
    //константы выбора
    while (select < 1 || select > 2)
    {
        send_message(selection_error, output);
        input >> select;
    }
    if (select == 1) {
        auto archive_file = read_file(input, output);
        if (archive_file == "exit")
            return update_action::DEFAULT;
        else {
            Request request;
            request.type = Request::dearchive;
            request.archive_name = archive_file;
            presenter->send_request(request, output);
        }
    }
    return update_action::DEFAULT;
}

update_action View::main_screen(std::istream& input, std::ostream& output) {
    output << "\nChoose action: \n"
                 "1) Show files in archive \n"
                 "2) Archive files \n"
                 "3) Dearchive files \n"
                 "4) Exit \n" << std::endl;
    int select;
    input >> select;
    //константы выбора
    while (select < 1 || select > 4) {
        send_message(selection_error, output);
        input >> select;
    }
    return (update_action)(select-1);
}

//// Фунции обработки ввода пользователя

std::vector<std::string> View::read_files(std::istream& input, std::ostream& output) {
    output << "Please write number of files:" << std::endl;
    size_t n = get_int(input, output);
    std::string buffer;
    std::vector<std::string> out;
    output << "Please write path to files or \"exit\" to go back:" << std::endl;
    for (size_t i = 0; i < n; i++ ) {
      input >> buffer;
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
          message.message_text = "File \"" + buffer + "\" doesn't exist and can't be added to archive"
                                 + "input right path or \"exit\" to go back";
          send_message(message, output);
          n++;
      }
    }
    return out;
}

std::string View::read_file(std::istream& input, std::ostream& output) {
    Message message;
    message.type = Message::error;
    message.message_text = "Write correct path to file or \"exit\" to go back";
    output << "Please write path to file or \"exit\" to go back:" << std::endl;
    std::string out;
    input>>out;
    while (!file_exists(out.c_str())) {
        if (out == "exit")
            return out;
        send_message(message, output);
        input >> out;
    }
    return out;
}



//// Отбражение сообщений Presenter
bool View::send_message(Message message, std::ostream& output) {
    output << line;
    switch (message.type) {
        case Message::ok:
            output << "Success: " << message.message_text << std::endl;
            output << line;
            return true;
        case Message::warning:
            output << "Warning: " << message.message_text << std::endl;
            output << line;
            return false;
        case Message::error:
            output << "Error: " << message.message_text << std::endl;
            output << line;
            return false;
    }
}

bool View::show_files(std::vector<std::string> files, std::ostream& output) {
    int numeration = 1;
    if (files.empty()) {
        Message message;
        message.type = Message::warning;
        message.message_text = "There are no files in archive";
        send_message(message, output);
        return false;
    }
    output << line;
    output << "These files are in archive:" <<  std::endl;
    for (auto file : files)
        output << numeration++ <<") " << file << std::endl;
    output << line;
    return true;
}

size_t View::get_int(std::istream& input, std::ostream& output) {
    Message message;
    message.type = Message::error;
    message.message_text = "Input integer";
    size_t int_input;
    input >> int_input;
    while (input.fail()) {
        send_message(message, output);
        input.clear(); // то возвращаем cin в 'обычный' режим работы
        input.ignore(32767,'\n'); //
        input >> int_input;
    }
    return int_input;
}

View::View() {
        presenter = std::make_shared<Presenter>(this);
        selection_error.type = Message::error;
        selection_error.message_text = "Wrong selection. Please try again";
}

////Облочка над функциями для работы презентера, чтобы разрешить конфликт incomplete type

void Presenter::view_sender(Message message, std::ostream& output) {
    view->send_message(message, output);
}

void Presenter::view_sender(std::vector<std::string> input, std::ostream& output) {
    view->show_files(input, output);
}

