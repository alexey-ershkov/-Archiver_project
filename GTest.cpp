//
// Created by Алексей on 2019-11-08.
//

#include <fstream>
#include "gtest/gtest.h"
#include "Presenter.h"
#include "View.h"
#include "Request.h"

#define log_filename "ArchiverTestLog.txt"
#define screen_main "../TestCases/MainScreenTest"
#define screen_show "../TestCases/ShowScreenTest"
#define screen_archive "../TestCases/ArchiveScreenTest"
#define screen_dearchive "../TestCases/DearchiveScreenTest"
#define update_test "../TestCases/UpdateTest"

#define line "\n\n##############################################################\n\n"

TEST (ModelUnitTests, archive_can_handle_test) {
    Archive archive;
    Dearchive dearchive;
    Show show;
    Request request;
    request.type = Request::archive;
    ASSERT_TRUE(archive.can_handle(request));
    ASSERT_FALSE(dearchive.can_handle(request));
    ASSERT_FALSE(show.can_handle(request));

}


TEST (ModelUnitTests, dearchive_can_handle_test) {
    Archive archive;
    Dearchive dearchive;
    Show show;
    Request request;
    request.type = Request::dearchive;
    ASSERT_FALSE(archive.can_handle(request));
    ASSERT_TRUE(dearchive.can_handle(request));
    ASSERT_FALSE(show.can_handle(request));

}

TEST (ModelUnitTests, show_can_handle_test) {
    Archive archive;
    Dearchive dearchive;
    Show show;
    Request request;
    request.type = Request::show;
    ASSERT_FALSE(archive.can_handle(request));
    ASSERT_FALSE(dearchive.can_handle(request));
    ASSERT_TRUE(show.can_handle(request));

}

TEST (ModelUnitTests, archive_handle_test) {
    Archive archive;
    Request request;
    ModelResponse response = archive.handle(request);
    ASSERT_EQ(response.state, ModelResponse<>::ok);
}

TEST (ModelUnitTests, dearchive_handle_test) {
    Archive archive;
    Request request;
    ModelResponse response = archive.handle(request);
    ASSERT_EQ(response.state, ModelResponse<>::ok);
}

TEST (ModelUnitTests, show_handle_test) {
    Archive archive;
    Request request;
    ModelResponse response = archive.handle(request);
    ASSERT_EQ(response.state, ModelResponse<>::ok);
}

///////////////////////////////////////////////////////////////

class PresenterUnitTestsDefault : public ::testing::Test {
protected:
    void SetUp() override {
        auto show  = std::make_shared<Show>();
        auto archive = std::make_shared<Archive>();
        auto dearchive = std::make_shared<Dearchive>();
        handlers.push_back(archive);
        handlers.push_back(dearchive);
        handlers.push_back(show);
    };
    void TearDown() override {
        handlers.clear();
    };
    std::vector<std::shared_ptr<IHandler<>>> handlers;
};

TEST_F(PresenterUnitTestsDefault, ArchiveRequest){
    Request request;
    request.type = Request::archive;
    ModelResponse response;
    for (auto it : handlers) {
        if (it->can_handle(request)) {
            response = it->handle(request);
        }
    }
    ASSERT_EQ(Request::archive,response.module);
}
TEST_F(PresenterUnitTestsDefault, DearchiveRequest){
    Request request;
    request.type = Request::dearchive;
    ModelResponse response;
    for (auto it : handlers) {
        if (it->can_handle(request)) {
            response = it->handle(request);
        }
    }
    ASSERT_EQ(Request::dearchive,response.module);
}
TEST_F(PresenterUnitTestsDefault, ShowRequest){
    Request request;
    request.type = Request::show;
    ModelResponse response;
    for (auto it : handlers) {
        if (it->can_handle(request)) {
            response = it->handle(request);
        }
    }
    ASSERT_EQ(Request::show,response.module);
}

//////////////////////////////////////////////////////////////////
//В терминал выводятся элементы интерфейса, т.к. в процессе разработке о проблеме вывода чего либо,
//кроме интерфейса GTest продумано не было

class ViewUnitTests : public testing::Test{
protected:
    void SetUp() override {
        log.open(log_filename, std::ios::app);
        view = new View;
    }
    void TearDown() override {
        delete view;
        log.close();
    }
    std::ofstream log;
    View *view;
};


TEST_F (ViewUnitTests, send_message_ok) {
    Message message;
    message.type = Message::ok;
    message.message_text = "test_ok";
    log << line;
    ASSERT_TRUE (view->send_message(message, log));
}

TEST_F (ViewUnitTests, send_message_warining) {
    Message message;
    message.type = Message::warning;
    message.message_text = "test_warning";
    log << line;
    ASSERT_FALSE (view->send_message(message, log));
}

TEST_F (ViewUnitTests, send_message_error) {
    Message message;
    message.type = Message::error;
    message.message_text = "test_error";
    log << line;
    ASSERT_FALSE (view->send_message(message, log));
}

TEST_F (ViewUnitTests, show_files) {
    std::vector<std::string> test_filenames = {"file1", "file2"};
    log << line;
    ASSERT_TRUE(view->show_files(test_filenames, log));
}

TEST_F (ViewUnitTests, show_files_empty) {
    std::vector<std::string> test_filenames;
    log << line;
    ASSERT_FALSE(view->show_files(test_filenames, log));
}

TEST_F (ViewUnitTests, main_screen) {
    log << line;
    std::ifstream input;
    input.open(screen_main);
    if (!input.is_open()) {
        log << "ERROR: unable to open file to test main_screen" << std::endl;
        FAIL();
    } else {
        ASSERT_EQ(update_action::SHOW, view->main_screen(input, log));
        ASSERT_EQ(update_action::ARCHIVE, view->main_screen(input, log));
        ASSERT_EQ(update_action::DEARCHIVE, view->main_screen(input, log));
        ASSERT_EQ(update_action::CLOSE, view->main_screen(input, log));
    }
    input.close();
}

TEST_F (ViewUnitTests, show_screen) {
    log << line;
    std::ifstream input;
    input.open(screen_show);
    if (!input.is_open()) {
        log << "ERROR: unable to open file to test show_screen" << std::endl;
        FAIL();
    } else {
        //разные входные данные
        //также тестируются приватные методы здесь
        ASSERT_EQ(update_action::DEFAULT, view->show_screen(input, log));
        ASSERT_EQ(update_action::DEFAULT, view->show_screen(input, log));
        ASSERT_EQ(update_action::DEFAULT, view->show_screen(input, log));
        ASSERT_EQ(update_action::DEFAULT, view->show_screen(input, log));
        ASSERT_EQ(update_action::DEFAULT, view->show_screen(input, log));
        ASSERT_EQ(update_action::DEFAULT, view->show_screen(input, log));
    }
    input.close();
}

TEST_F (ViewUnitTests, archive_screen) {
    log << line;
    std::ifstream input;
    input.open(screen_archive);
    if (!input.is_open()) {
        log << "ERROR: unable to open file to test archive_screen" << std::endl;
        FAIL();
    } else {
        //разные входные данные
        //также тестируются приватные методы здесь
        ASSERT_EQ(update_action::DEFAULT, view->archive_screen(input, log));
        ASSERT_EQ(update_action::DEFAULT, view->archive_screen(input, log));
        ASSERT_EQ(update_action::DEFAULT, view->archive_screen(input, log));
        ASSERT_EQ(update_action::DEFAULT, view->archive_screen(input, log));
        ASSERT_EQ(update_action::DEFAULT, view->archive_screen(input, log));
        ASSERT_EQ(update_action::DEFAULT, view->archive_screen(input, log));
        ASSERT_EQ(update_action::DEFAULT, view->archive_screen(input, log));
        ASSERT_EQ(update_action::DEFAULT, view->archive_screen(input, log));
        ASSERT_EQ(update_action::DEFAULT, view->archive_screen(input, log));
    }
    input.close();
}

TEST_F (ViewUnitTests, dearchive_screen) {
    log << line;
    std::ifstream input;
    input.open(screen_dearchive);
    if (!input.is_open()) {
        log << "ERROR: unable to open file to test dearchive_screen" << std::endl;
        FAIL();
    } else {
        //разные входные данные
        //также тестируются приватные методы здесь
        ASSERT_EQ(update_action::DEFAULT, view->dearchive_screen(input, log));
        ASSERT_EQ(update_action::DEFAULT, view->dearchive_screen(input, log));
        ASSERT_EQ(update_action::DEFAULT, view->dearchive_screen(input, log));
        ASSERT_EQ(update_action::DEFAULT, view->dearchive_screen(input, log));
        ASSERT_EQ(update_action::DEFAULT, view->dearchive_screen(input, log));
        ASSERT_EQ(update_action::DEFAULT, view->dearchive_screen(input, log));
    }
    input.close();
}


TEST_F (ViewUnitTests, update) {
    log << line;
    std::ifstream input;
    input.open(update_test);
    if (!input.is_open()) {
        log << "ERROR: unable to open file to test update" << std::endl;
        FAIL();
    } else {
        //разные входные данные
        ASSERT_EQ(update_action::DEFAULT, view->update(update_action::SHOW, input, log));
        ASSERT_EQ(update_action::DEFAULT, view->update(update_action::ARCHIVE, input, log));
        ASSERT_EQ(update_action::DEFAULT, view->update(update_action::DEARCHIVE, input, log));
        ASSERT_EQ(update_action::SHOW, view->update(update_action::DEFAULT, input, log));
        ASSERT_EQ(update_action::ARCHIVE, view->update(update_action::DEFAULT, input, log));
        ASSERT_EQ(update_action::DEARCHIVE, view->update(update_action::DEFAULT, input, log));
        ASSERT_EQ(update_action::CLOSE, view->update(update_action::DEFAULT, input, log));
    }
    input.close();
}




int main(int argc, char *argv[]) {

    std::ofstream clear;
    clear.open(log_filename, std::ios::out);
    clear.close();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}