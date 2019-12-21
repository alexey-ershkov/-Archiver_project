//
// Created by Алексей on 2019-11-08.
// Можно добавить библотеку ncurses для более приветливого отображения интерфейса
//

#ifndef ARCHIVER_CONSOLEVIEW_H
#define ARCHIVER_CONSOLEVIEW_H

#include <algorithm>
#include <cstdlib>
#include <memory>
#include "Message.h"
#include "Request.h"
#include <sys/ioctl.h>
#include "View.h"
#include <zconf.h>





class Presenter;

enum update_action {SHOW, ARCHIVE, DEARCHIVE, CLOSE, DEFAULT};

class ConsoleView : public View  {
private:
    bool is_term = false;
    struct winsize w;
    std::shared_ptr<Presenter> presenter;
    std::vector<std::string> read_files (std::istream& , std::ostream&);
    ///Проверка на существование введенного файла
    ///Функция вернет -1 в случае если его нет
    bool file_exists(const char *filename)
    {
        return access(filename, 0) != -1;
    }
    std::string read_file(std::istream& , std::ostream&);
    size_t get_int(std::istream&, std::ostream&);
    Message selection_error;
public:
    void system_clear();
    void system_pause();
    std::string set_center(std::ostream&);


    virtual bool send_message (Message message, std::ostream&) override ;
    virtual bool show_files (std::vector<std::string>, std::ostream&) override;
    ConsoleView();
    ConsoleView(bool);

    update_action update(enum update_action, std::istream&, std::ostream&);

    update_action main_screen(std::istream& , std::ostream&);
    update_action show_screen(std::istream& , std::ostream&);
    update_action archive_screen(std::istream& ,std::ostream&);
    update_action dearchive_screen(std::istream& , std::ostream&);

};


#endif //ARCHIVER_CONSOLEVIEW_H
