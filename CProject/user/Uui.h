#ifndef A5_6_914_MATEI_SONIA_UUI_H
#define A5_6_914_MATEI_SONIA_UUI_H

#include "Ucontroller.h"
#include "../administrator/video.h"
#include "../administrator/ui.h"

class UIUser {
private:
    ControllerUser& ctrl;

public:

    UIUser(ControllerUser& ctrl);

    void start();
    void search();
    void open();
    void playWatchList();
    static void printMenu();

};

#endif //A5_6_914_MATEI_SONIA_UUI_H
