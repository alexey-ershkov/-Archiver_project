#include <iostream>
#include "View.h"

int main() {
    View view;
    Request test;
    test.type = Request::dearchive;

    view.presenter->send_request(test);
    return 0;
}