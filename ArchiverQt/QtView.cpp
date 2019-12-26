//
// Created by Алексей on 21/12/2019.
//

#include "QtView.h"

bool QtView::send_message(Message message, std::ostream &) {
    return false;
}

bool QtView::show_files(std::vector<std::string>, std::ostream &) {
    return false;
}

QString QtView::get_filenames() {
    return m_filenames;
}

void QtView::set_filenames(const QString &files) {
    if (files == m_filenames)
        return;

    m_filenames = files;
    emit filenamesChanged();
}
