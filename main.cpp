#include "View.h"
#include <cstring>



int main(int argc, char** argv) {
    View *view;
    if (argc > 1){
        view = new View(true);
    } else {
        view = new View;
    }
    auto screen = update_action::DEFAULT;
    while (screen != update_action::CLOSE){
        screen = view->update(screen, std::cin, std::cout);
    }
    view->system_clear();
    return 0;
}