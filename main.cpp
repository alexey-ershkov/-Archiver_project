#include <Selection.h>
#include "ConsoleView.h"



int main(int argc, char** argv) {
    ConsoleView *view;
    std::ofstream fout;
    fout.open("selection.log");
    fout.clear();
    fout.close();
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