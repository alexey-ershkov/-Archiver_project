//
// Created by Алексей on 21/12/2019.
//

#ifndef ARCHIVER_QTVIEW_H
#define ARCHIVER_QTVIEW_H

#include <memory>
#include <QObject>
#include <QString>
#include <QStringList>
#include <QDesktopServices>
#include <QUrl>
#include "View.h"

class Presenter;

class QtView : public  QObject, public View {

    Q_OBJECT

    Q_PROPERTY(QString filepath READ get_filepath WRITE set_filepath NOTIFY filepathSet)
    Q_PROPERTY(QStringList files_in_archive READ get_files_in_archive NOTIFY archiveFilesChanged)
    Q_PROPERTY(QString savepath READ get_savepath WRITE set_savepath NOTIFY savepathSet)
    Q_PROPERTY(QString archive_name READ get_archive_name WRITE set_archive_name NOTIFY archiveNameSet)
    Q_PROPERTY(QString message READ get_message NOTIFY messageSet)
    Q_PROPERTY(bool success READ get_info)

public:
    QtView();
    bool send_message (Message message, std::ostream&);
    bool show_files (std::vector<std::string>, std::ostream&);

    QString get_filepath();
    void set_filepath(const QString &);

    QStringList get_files_in_archive();

    QString get_savepath();
    void set_savepath(const QString &);

    QString get_archive_name();
    void set_archive_name(const QString&);

    QString get_message();

    bool get_info();

private:
    QStringList m_files_in_archive;
    QString m_filepath;
    QString m_savepath;
    QString m_archive_name;
    std::vector<std::string> m_files_to_archive;
    QString m_message;

    bool m_success;

    std::shared_ptr<Presenter> presenter;

public slots:
    void showFiles();
    void dearchiveFiles();
    void addFiles(const QString& input);
    void archiveFiles();
    void clear();
    void open(QString &url);

signals:
    void filepathSet();
    void savepathSet();
    void archiveFilesChanged(QStringList);
    void archiveNameSet();
    void messageSet();
};


#endif //ARCHIVER_QTVIEW_H
