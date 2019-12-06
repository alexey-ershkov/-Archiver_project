//
// Created by Алексей on 2019-11-08.
//

#ifndef ARCHIVER_VIEW_H
#define ARCHIVER_VIEW_H




#include "Request.h"
#include "Message.h"
#include <zconf.h>
#include <algorithm>
#include <memory>

class Presenter;

enum update_action {SHOW, ARCHIVE, DEARCHIVE, CLOSE, DEFAULT};

class View  {
private:
    std::shared_ptr<Presenter> presenter;
    std::vector<std::string> read_files ();
    bool file_exists(const char *filename)
    {
        return access(filename, 0) != -1;
    }
    std::string read_file();
    size_t get_int();
    Message selection_error;
public:
    virtual void send_message (Message message);
    virtual void show_files (std::vector<std::string>);
    View();

    update_action update(enum update_action);

    virtual update_action main_screen();
    virtual update_action show_screen();
    virtual update_action archive_screen();
    virtual update_action dearchive_screen();

};


#endif //ARCHIVER_VIEW_H
