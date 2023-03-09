#ifndef A5_6_914_MATEI_SONIA_UI_H
#define A5_6_914_MATEI_SONIA_UI_H

#include "controller.h"
#include "video.h"
#include "repository.h"

class UIAdministrator {

private:
    ControllerAdministrator& ctrl;

    static void printMenu();
    void add();
    void remove();
    void update();
    void printAll();
    void sortList();

public:

    UIAdministrator(ControllerAdministrator& ctrl);

    void start();
    RepositoryAdministrator& getRepo();
};

#endif //A5_6_914_MATEI_SONIA_UI_H
