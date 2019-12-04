#include <iostream>
#include "View.h"


int main() {
    View view;
    auto screen = update_action::DEFAULT;
    while (screen != update_action::CLOSE){
        screen = view.update(screen);
    }
    return 0;
}