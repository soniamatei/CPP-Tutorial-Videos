#ifndef A5_6_914_MATEI_SONIA_CONTROLLER_H
#define A5_6_914_MATEI_SONIA_CONTROLLER_H

#include "repository.h"
#include "video.h"
#include "string"
#include <iostream>

class ControllerAdministrator {

private:
    RepositoryAdministrator& repo;

    int identifyElement(std::string link);

public:

    ControllerAdministrator(RepositoryAdministrator& repo);

    void entities();
    void add(std::string title, std::string presenter, int minutes, int seconds,
            int likes, std::string link);
    void remove(std::string link);
    void update(std::string link, std::string new_title, std::string new_presenter,
               int new_minutes, int new_seconds, int new_likes, std::string new_link);
    std::vector<Video>& getData();
//    ControllerAdministrator& operator=(const ControllerAdministrator& ctrl);

    static void to_digit(int& var, std::string string);
    RepositoryAdministrator& getRepo();
    std::vector<Video> sortDataAndReturn(std::string option);
};

#endif //A5_6_914_MATEI_SONIA_CONTROLLER_H
