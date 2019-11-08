//
// Created by Алексей on 2019-11-08.
//

#include "gtest/gtest.h"
#include "Presentor.h"
#include "View.h"
#include "TestView.h"
#include "TestSub.h"


TEST(test,test){
    SUCCEED();
}


TEST(IView_test, testing_exeptions) {
    View view;
    EXPECT_ANY_THROW(view.testThrow());
}

TEST(IView_test, check_update) {
    View view;
    try {
        view.update();
        SUCCEED();
    }
    catch (...) {
        FAIL();
    }
}

TEST(Presentor_test, testing_exeptions) {
    TestView view;
    Presentor presentor(&view);
    EXPECT_ANY_THROW(presentor.testThrow());
}

TEST(Presentor_test, Subscribe_testing) {
    TestSub sub;
    TestView view;
    Presentor presentor(&view);
    try {
        presentor.Subscribe(&sub, Event::test_event);
        SUCCEED();
    }
    catch(...) {
        FAIL();
    }
}

TEST(Presntor_test, Unsubscribe_testing) {
    TestSub sub;
    TestView view;
    Presentor presentor(&view);
    presentor.Subscribe(&sub, Event::test_event);
    try {
        presentor.Unsubscribe(&sub, Event::test_event);
        SUCCEED();
    }
    catch(...) {
        FAIL();
    }
}

TEST(Presentor_test, SendEvent_testing) {
    TestSub sub;
    TestView view;
    Presentor presentor(&view);
    Event event;
    event.type = Event::test_event;
    event.data = Event::testEvent();
    presentor.Subscribe(&sub, Event::test_event);
    try {
        presentor.SendEvent(event);
        FAIL();
    }
    catch (std::invalid_argument) {
        SUCCEED();
    }
    catch (...){
        FAIL();
    }

}

TEST(Presentor_test, takeEvent_testing) {
    IView *view;
    Presentor presentor(view);
    Event event;
    event.type = Event::test_event;
    try {
        presentor.takeEvent(event);
        SUCCEED();
    }
    catch (...) {
        FAIL();
    }
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}