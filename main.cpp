#include <Selection.h>
#include "ConsoleView.h"



int main(int argc, char** argv) {
    ConsoleView *view;
    if (argc > 1){
        view = new ConsoleView(true);
    } else {
        view = new ConsoleView;
    }
    auto screen = update_action::DEFAULT;
    while (screen != update_action::CLOSE){
        screen = view->update(screen, std::cin, std::cout);
    }
    view->system_clear();
    return 0;
}

//int main () {
//    Selection selection("image");
//    selection.Decompress("1.bin","../awesome_tests/UML.png");
//    return 0;
//}




