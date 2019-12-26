//
// Created by Алексей on 21/12/2019.
//

#ifndef ARCHIVER_QTVIEW_H
#define ARCHIVER_QTVIEW_H

#include <QObject>
#include <QString>
#include <QStringList>
#include "View.h"

class QtView : public  QObject,View {

    Q_OBJECT

    Q_PROPERTY(QString filenames READ get_filenames WRITE set_filenames NOTIFY filenamesChanged )

public:
    bool send_message (Message message, std::ostream&);
    bool show_files (std::vector<std::string>, std::ostream&);

    QString get_filenames();
    void set_filenames(const QString &);

private:
    QString m_filenames;

public slots:
   //void sendFilenames();
signals:
    void filenamesChanged();
};


#endif //ARCHIVER_QTVIEW_H
