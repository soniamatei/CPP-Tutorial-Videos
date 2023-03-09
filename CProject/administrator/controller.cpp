#include "controller.h"
#include <algorithm>
#include <string>
#include <cstring>
#include "../exceptions.h"
//#include "../lab_activity.h"

using namespace std;

ControllerAdministrator::ControllerAdministrator(RepositoryAdministrator &repo) : repo(repo) {

    if (strcmp(typeid(repo).name(), "23RepositoryAdministrator") == 0)
        repo.entities();
}

/// Returns the position where the video with the given link is at.
/// \param link string
/// \return -1 -> not in database; position -> if found
int ControllerAdministrator::identifyElement(std::string link) {

    std::vector<Video> copy = this->repo.getData();

    string link_1 = link;
    transform(link_1.begin(), link_1.end(), link_1.begin(), ::tolower);

    __gnu_cxx::__normal_iterator<Video *, vector<Video>> position = find_if(copy.begin(), copy.end(),[link_1](Video video){
        string link_2 = video.getLink();
        transform(link_2.begin(), link_2.end(), link_2.begin(), ::tolower);
        return link_1 == link_2;
    });

    if (position == copy.end())
        return -1;
    return (int)(position - copy.begin());
}

/// Creates a video with the params. given and adds it to the database.
/// \param title string
/// \param presenter string
/// \param minutes integer
/// \param seconds integer
/// \param likes integer
/// \param link string
void ControllerAdministrator::add(std::string title, std::string presenter, int minutes, int seconds, int likes,
                                 std::string link) {

    if (identifyElement(link) != -1)
        throw(AddError("\nThis video already exists.\n" ));

    Video video{title, presenter, minutes, seconds, likes, link};
    this->repo.add(video, this->repo.getLength());
}

/// Removes a video from database by its link.
/// \param link
void ControllerAdministrator::remove(std::string link) {

    int position = identifyElement(link);

    if (position == -1)
        throw(RemoveError("\nThis video doesn't exist.\n"));

    this->repo.remove(position);
}

/// Updates a video with the params given.
/// \param link string
/// \param new_title string
/// \param new_presenter string
/// \param new_minutes integer
/// \param new_seconds integer
/// \param new_likes integer
/// \param new_link string
void ControllerAdministrator::update(std::string link, std::string new_title, std::string new_presenter, int new_minutes,
                                    int new_seconds, int new_likes, std::string new_link) {

    int position = identifyElement(link);

    if (position == -1)
        throw(UpdateError("\nThis video doesn't exist.\n"));

    Video new_video{new_title, new_presenter, new_minutes, new_seconds,
                    new_likes, new_link};

    this->repo.update(new_video, position);
}

/// Gets the all the videos from database.
/// \return DynamicArray
std::vector<Video>& ControllerAdministrator::getData() {

    return this->repo.getData();
}

/// transforms a string to integer.
/// \param var integer; variable for result to be stored in
/// \param string string
void ControllerAdministrator::to_digit(int& var, std::string string) {

    var = 0;

    for(char i : string)
        var = var * 10 + (i - '0');
}

/// Returns the repository of the administrator.
/// \return RepositoryAdministrator
RepositoryAdministrator &ControllerAdministrator::getRepo() {

    return this->repo;
}

std::vector<Video> ControllerAdministrator::sortDataAndReturn(std::string option) {

    std::vector<Video> data = repo.getData();

//    if (option == "1"){
//        ComparatorAscTitle<Video> cmp_class;
//        sortVec(data, cmp_class);
//    }
//    else if (option == "2") {
//        ComparatorDescLikes<Video> cmp_class;
//        sortVec(data, cmp_class);
//    }
//    else throw MsgError("\nNo such sorting.\n");

    return data;
}

void ControllerAdministrator::entities() {

    this->repo.entities();
}
