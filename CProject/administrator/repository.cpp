#include "repository.h"
#include "controller.h"
#include <fstream>

/// Getter for element from database at a given position.
/// \param position integer
/// \return Video reference
Video& RepositoryAdministrator::getElement(int position) {

    return this->arr[position];
}

/// Adds a video to database.
/// \param video Video reference
/// \param position integer
void RepositoryAdministrator::add(Video& video, int position) {

    this->arr.insert(arr.begin() + position, video);
}

/// Removes a video from database by the position.
/// \param position integer
void RepositoryAdministrator::remove(int position) {

    this->arr.erase(arr.begin() + position);
}

/// Updates a video from database at a given position with another video.
/// \param new_video Video reference
/// \param position integer
void RepositoryAdministrator::update(Video &new_video, int position) {

    this->arr[position] = new_video;
}

/// Gets all the videos from database.
/// \return DynamicArray
std::vector<Video>& RepositoryAdministrator::getData() {

    return this->arr;
}

/// Returns the number of videos in database.
/// \return integer
int RepositoryAdministrator::getLength() {

    return (int)this->arr.size();
}

void RepositoryAdministrator::entities() {

    std::ifstream file("../administrator/entities.txt");
    std::string title, presenter, minutes, seconds, likes, link, ch;
    int i = 0, m, s, l;

    while (i < 10) {

        getline(file, title, '@');
        getline(file, presenter, '@');
        getline(file, minutes, '@');
        getline(file, seconds, '@');
        getline(file, likes, '@');
        getline(file, link, '@');
        getline(file, ch, '@');

        ControllerAdministrator::to_digit(m, minutes);
        ControllerAdministrator::to_digit(s, seconds);
        ControllerAdministrator::to_digit(l, likes);

        Video video{title, presenter, m, s, l, link};
        this->add(video, i);

        i++;
    }

    file.close();
}
