#include "View.h"


int main() {
    View view;
    auto screen = update_action::DEFAULT;
    while (screen != update_action::CLOSE){
        screen = view.update(screen, std::cin, std::cout);
    }
    return 0;
}