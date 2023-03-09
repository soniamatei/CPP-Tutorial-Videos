#include "Ucontroller.h"
#include <vector>
#include <algorithm>
#include <cstring>
#include "../exceptions.h"

using namespace std;


ControllerUser::ControllerUser(RepositoryAdministrator &repoAdmin, RepositoryUser &repoUsr) : repoAds(repoAdmin),
                                                                                              repoUser(repoUsr){}

/// Return the database of the repository.
/// \return vector<string>
vector<Video> ControllerUser::getWatchList() {

    return repoUser.getData();
}

/// Gets the position of an element identified by its link.
/// \param link string
/// \return integer
int ControllerUser::identifyElement(string link) {

    std::vector<Video> copy;

    copy = this->repoAds.getData();

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

/// Gets the position of an element form the watch list identified by the its link.
/// \param link string
/// \return integer
int ControllerUser::identifyLink(std::string link) {

    vector<Video> copy{};
    copy = this->repoUser.getData();

    int position = -1;

    string link_1 = link;

    for(int i = 0; i < copy.size(); i++) {

        string link_2 = copy[i].getLink();

        if (link_1 == link_2) {

            position = i;
            break;
        }
    }

    return position;
}

/// Adds a like to the video.
/// \param link string
/// \param like string
/// \return string; Like -> if disliked; Liked -> if liked
std::string ControllerUser::like(string& link, const string& like) {

    int position = identifyElement(link);

    if (like == "Like"){
        this->repoAds.getElement(position).setLikes(this->repoAds.getElement(position).getLikes() + 1);
        return "Liked";
    }

    else {
        this->repoAds.getElement(position).setLikes(this->repoAds.getElement(position).getLikes() - 1);
        return "Like";
    }
}

/// Adds or deletes a video from the watchlist.
/// \param link string
/// \return string; Add -> if deleted; Added -> if added
string ControllerUser::addToWatchList(string& link) {

    int position = identifyLink(link);

    if (position != -1){
        this->repoUser.remove(position);
        return "Add";
    }

    Video video = this->repoAds.getElement(this->identifyElement(link));
    this->repoUser.add(video);
    return "Added";
}

/// Finds all the videos with a given presenter or all videos if string presenter is empty.
/// \param presenter string
/// \return vector<string>
vector<string> ControllerUser::findAll(std::string presenter) {

    vector<string> copy;

    if (presenter.empty()) {

        for(int i = 0; i < this->repoAds.getLength(); i++)
            copy.push_back(this->repoAds.getElement(i).getLink());

        return copy;
    }

    string presenter_1 = presenter;

    transform(presenter_1.begin(), presenter_1.end(), presenter_1.begin(), ::tolower);

    for(int i = 0; i < this->repoAds.getLength(); i++) {

        Video elem = this->repoAds.getElement(i);

        string presenter_2 = elem.getPresenter();
        transform(presenter_2.begin(), presenter_2.end(), presenter_2.begin(), ::tolower);

        if (presenter_1 == presenter_2) {
            copy.push_back(elem.getLink());
        }
    }

    return copy;
}

/// Gets an element identified by its link
/// \param link string
/// \return Video reference
Video &ControllerUser::getElement(std::string link) {

    return this->repoAds.getElement(this->identifyElement(link));
}

/// Gets the number of videos from the watchlist.
/// \return
int ControllerUser::getLength() {

    return this->repoUser.getLength();
}

void ControllerUser::open(string option) {

    if (option == "1")
        system("xdg-open \"../user/watchlist.csv\"");
    if (option == "2")
        system("xdg-open \"../user/watchlist.html\"");
}

std::vector<Video> &ControllerUser::getData() {

    return this->repoAds.getData();
}

Video &ControllerUser::getElementByPos(int pos) {

    return repoUser.getElement(pos);
}


