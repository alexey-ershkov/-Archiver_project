//
// Created by Алексей on 2019-11-08.
//

#ifndef ARCHIVER_VIEW_H
#define ARCHIVER_VIEW_H

#include "IView.h"
#include "Presentor.h"

class View : IView {
private:
    Presentor *presentor;
public:
    void update();

    View() {
      presentor = new Presentor(this);
    }

};


#endif //ARCHIVER_VIEW_H
