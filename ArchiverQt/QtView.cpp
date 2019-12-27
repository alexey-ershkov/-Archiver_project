//
// Created by Алексей on 21/12/2019.
//

#include "QtView.h"
#include "Presenter.h"

bool QtView::send_message(Message message, std::ostream &) {
    m_message = QString::fromStdString(message.message_text);
    if (message.type == Message::ok)
        m_success = 1;
    else
        m_success = 0;
}

bool QtView::show_files(std::vector<std::string> files, std::ostream &output) {
    m_files_in_archive.clear();
    for (auto it : files) {
        std::cout << it << std::endl;
        m_files_in_archive.append(QString::fromStdString(it));
    }
    emit archiveFilesChanged(m_files_in_archive);
    return true;
}

QString QtView::get_filepath() {
    return m_filepath;
}

void QtView::set_filepath(const QString &filepath) {
    if (filepath == m_filepath)
        return;
    m_filepath = filepath;
    emit filepathSet();
}

QtView::QtView() {
    presenter = std::make_shared<Presenter>(this);
}

void QtView::showFiles() {
    Request request;
    request.type = Request::show;
    request.archive_path = m_filepath.toStdString();
    presenter->send_request(request, std::cout);

}

QStringList QtView::get_files_in_archive() {
    return m_files_in_archive;
}

QString QtView::get_savepath() {
    return m_savepath;
}

void QtView::set_savepath(const QString &savepath) {
    if (savepath == m_savepath)
        return;

    m_savepath = savepath;
    emit savepathSet();
}

void QtView::dearchiveFiles() {
    Request request;
    request.type = Request::dearchive;
    request.archive_path = m_filepath.toStdString();
    request.dearchive_path = m_savepath.toStdString();
    presenter->send_request(request, std::cout);
}

QString QtView::get_archive_name() {
    return m_archive_name;
}

void QtView::set_archive_name(const QString &archive_name) {
    if (m_archive_name == archive_name)
        return;

    m_archive_name = archive_name;
    emit archiveNameSet();
}

void QtView::addFiles(const QString &input) {
    m_files_to_archive.emplace_back(input.toStdString());
    for (auto it : m_files_to_archive)
        std::cout << it << std::endl;
}

void QtView::archiveFiles() {
    Request request;
    request.type = Request::archive;
    request.filenames = m_files_to_archive;
    request.archive_name = m_archive_name.toStdString();
    request.archive_path = m_savepath.toStdString();
    presenter->send_request(request,std::cout);
}

void QtView::clear() {
    m_files_to_archive.clear();
    m_savepath.clear();
    m_files_in_archive.clear();
    m_archive_name.clear();
    m_filepath.clear();
}

void QtView::open(QString &url) {
    QDesktopServices::openUrl(QUrl::fromLocalFile(url));
}

QString QtView::get_message() {
    return m_message;
}

bool QtView::get_info() {
    return m_success;
}






