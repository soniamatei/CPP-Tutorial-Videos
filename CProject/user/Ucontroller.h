#ifndef A5_6_914_MATEI_SONIA_UCONTROLLER_H
#define A5_6_914_MATEI_SONIA_UCONTROLLER_H

#include "../administrator/repository.h"
#include "Urepository.h"
#include "../administrator/video.h"
#include "string"
#include <vector>

class ControllerUser {

private:
    RepositoryAdministrator& repoAds;
    RepositoryUser& repoUser;

    int identifyElement(std::string link);
    int identifyLink(std::string link);
public:

    ControllerUser();
    ControllerUser(RepositoryAdministrator& repoAdmin, RepositoryUser& repoUser);

    int getLength();
    Video& getElement(std::string link);
    Video& getElementByPos(int pos);
    std::vector<Video> getWatchList();
    std::string like(std::string& link, const std::string& like);
    std::string addToWatchList(std::string& link);
    std::vector<std::string> findAll(std::string presenter);
    std::vector<Video>& getData();
    static void open(std::string option);

};

#endif //A5_6_914_MATEI_SONIA_UCONTROLLER_H
