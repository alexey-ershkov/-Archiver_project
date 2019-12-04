//
// Created by Алексей on 2019-11-08.
//

#ifndef ARCHIVER_VIEW_H
#define ARCHIVER_VIEW_H




#include "Request.h"
#include "Presenter.h"
#include <zconf.h>
#include <algorithm>

enum update_action {SHOW, ARCHIVE, DEARCHIVE, CLOSE, DEFAULT};

class View  {
private:
    Presenter *presenter;
    std::vector<std::string> read_files ();
    bool file_exists(const char *fname)
    {
        return access(fname, 0) != -1;
    }
    std::string read_file();
public:
    //TODO метод для отображения сообщений о результате запроса
    View() {
      presenter = new Presenter(this);
    }

    update_action update(enum update_action);

    virtual update_action main_screen();
    virtual update_action show_screen();
    virtual update_action archive_screen();
    virtual update_action dearchive_screen();

};


#endif //ARCHIVER_VIEW_H
