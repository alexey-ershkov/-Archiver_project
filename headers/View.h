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
    std::vector<std::string> read_files (std::istream& , std::ostream&);
    bool file_exists(const char *filename)
    {
        return access(filename, 0) != -1;
    }
    std::string read_file(std::istream& , std::ostream&);
    size_t get_int(std::istream&, std::ostream&);
    Message selection_error;
public:
    virtual bool send_message (Message message, std::ostream&);
    virtual bool show_files (std::vector<std::string>, std::ostream&);
    View();

    update_action update(enum update_action, std::istream&, std::ostream&);

    virtual update_action main_screen(std::istream& , std::ostream&);
    virtual update_action show_screen(std::istream& , std::ostream&);
    virtual update_action archive_screen(std::istream& ,std::ostream&);
    virtual update_action dearchive_screen(std::istream& , std::ostream&);

};


#endif //ARCHIVER_VIEW_H
