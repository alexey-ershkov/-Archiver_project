//
// Created by Алексей on 2019-11-08.
//

#ifndef ARCHIVER_VIEW_H
#define ARCHIVER_VIEW_H




#include "Request.h"
#include "Presenter.h"
#include "Message.h"
#include <zconf.h>
#include <algorithm>


enum update_action {SHOW, ARCHIVE, DEARCHIVE, CLOSE, DEFAULT};

class View  {
private:
    Presenter *presenter;
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
    View() {
      presenter = new Presenter(this);
      selection_error.type = Message::error;
      selection_error.message_text = "Wrong selection. Please try again";
    }

    update_action update(enum update_action);

    virtual update_action main_screen();
    virtual update_action show_screen();
    virtual update_action archive_screen();
    virtual update_action dearchive_screen();

};


#endif //ARCHIVER_VIEW_H
