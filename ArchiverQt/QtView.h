//
// Created by Алексей on 21/12/2019.
//

#ifndef ARCHIVER_QTVIEW_H
#define ARCHIVER_QTVIEW_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <View.h>

class QtView : public View, QObject {
     bool send_message (Message message, std::ostream&);
     bool show_files (std::vector<std::string>, std::ostream&);
};


#endif //ARCHIVER_QTVIEW_H
