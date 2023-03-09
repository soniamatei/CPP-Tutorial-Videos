#include "video.h"
#include <iostream>
#include <iomanip>
#include <thread>
#include <stdlib.h>
#include "controller.h"

using namespace std;

Video::Video()=default;

Video::Video(const string& title,const string& presenter,int minutes, int seconds, int likes,const string& link) {

    Duration d{minutes, seconds};

    this->title = title;
    this->presenter = presenter;
    this->duration = d;
    this->likes = likes;
    this->link = link;
    this->is_liked = "Like";
    this->is_added = "Add";
}

/// Getter for presenter string.
/// \return string
string& Video::getPresenter() {

    return this->presenter;
}

/// Getter for likes integer.
/// \return integer.
int& Video::getLikes() {

    return this->likes;
}

/// Getter for link string.
/// \return string
string& Video::getLink() {

    return this->link;
}

/// Setter for likes.
/// \param value integer; number of likes
void Video::setLikes(int value) {

    this->likes = value;
}

void Video::printVideoAdministrator() {

    cout << "\n\n┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅\n";
    cout << "Link: " << this->link;
    cout << R"(
    ╭─────────────╮
    │ C++         │    - )" << this->likes<< R"( likes
    │             │    - )" << setfill('0') << std::setw(2) << this->duration.minutes << ":"
                            << setfill('0') << std::setw(2) << this->duration.seconds << R"( minutes
    ╰─────────────╯
)";
    cout << "  Tile: "<< this->title << "  |  " << "Presenter: " << this->presenter;
}

void Video::printVideoUser(bool& stop) {

    cout << "\x1B[2J\x1B[3J\x1B[H";

    for (int sec = this->duration.seconds; sec >= 0 && !stop; sec--) {
        cout << "\nLINK: " << this->link << R"(

    ╭───────────────────────╮
    │ C++                   │     )" << "TITLE: " << this->title << R"(
    │                       │     )" << "PRESENTER: " << this->presenter << R"(
    │                       │
    │                )" << setfill('0') << std::setw(2) << setfill('0') << std::setw(2) << this->duration.minutes << ":"
             << setfill('0') << std::setw(2) << sec << R"(  │     )" << this->likes << " \u2665" << R"(
    ╰───────────────────────╯
)" << "  1. " << this->is_liked << "     2. " << this->is_added << "     3. Next     4. Exit     5. Open";
        cout.flush();

        this_thread::sleep_for(1s);
        cout << "\x1B[2J\x1B[3J\x1B[H";
    }

    for (int min = this->duration.minutes - 1; min >= 0 && !stop; min--) {

        for (int sec = 59; sec >= 0 && !stop; sec--) {
            cout << "\nLINK: " << this->link << R"(

    ╭───────────────────────╮
    │ C++                   │     )" << "TITLE: " << this->title << R"(
    │                       │     )" << "PRESENTER: " << this->presenter << R"(
    │                       │
    │                )" << setfill('0') << std::setw(2) << setfill('0') << std::setw(2) << min << ":"
                 << setfill('0') << std::setw(2) << sec << R"(  │     )" << this->likes << " \u2665" << R"(
    ╰───────────────────────╯
)" << "  1. " << this->is_liked << "     2. " << this->is_added << "     3. Next     4. Exit     5. Open";
            cout.flush();

            //make text be printed for a second
            this_thread::sleep_for(1s);
            cout << "\x1B[2J\x1B[3J\x1B[H";
        }
    }
    cout << "\x1B[2J\x1B[3J\x1B[H";
}

/// Setter for status of like.
/// \param value string
void Video::setIs_Liked(std::string value) {

    this->is_liked = value;
}

/// Setter for status of add.
/// \param value string
void Video::setIs_Added(std::string value) {

    this->is_added = value;
}

/// Getter for status of like.
/// \return string
std::string Video::getIs_Liked() {

    return this->is_liked;
}

void Video::open(std::string link) {

    string command = "xdg-open " + link;
    system(command.c_str());
}
istream& operator>>(istream & stream, Video& video)
{
    std::string minutes, seconds, likes, ch;
    getline(stream, video.title, '@');
    getline(stream, video.presenter, '@');
    getline(stream, minutes, '@');
    getline(stream, seconds, '@');
    getline(stream, likes, '@');
    getline(stream, video.link, '@');
    getline(stream, video.is_liked, '@');
    getline(stream, video.is_added, '@');
    getline(stream, ch);

    ControllerAdministrator::to_digit(video.duration.minutes, minutes);
    ControllerAdministrator::to_digit(video.duration.seconds, seconds);
    ControllerAdministrator::to_digit(video.likes, likes);

    return stream;
}

ostream & operator<<(ostream & stream, const Video& video)
{
    stream << video.title << "@";
    stream << video.presenter << "@";
    stream << video.duration.minutes << "@";
    stream << video.duration.seconds << "@";
    stream << video.likes << "@";
    stream << video.link<< "@";
    stream << video.is_liked << "@";
    stream << video.is_added << "@" << "\n";

    return stream;
}

std::string Video::getTitle() {

    return title;
}

int Video::getMinutes() {

    return duration.minutes;
}

int Video::getSeconds() {

    return duration.seconds;
}

std::string Video::getIs_Added() {

    return this->is_added;
}

