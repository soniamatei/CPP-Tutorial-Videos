#include "Urepository.h"
#include <vector>

/// Adds a video to the watchlist database.
/// \param link string
void RepositoryUser::add(Video& video){

    this->arr.push_back(video);
}

/// Remove a video from the watchlist database.
/// \param position integer
void RepositoryUser::remove(int position) {

    this->arr.erase(this->arr.begin() + position);
}

/// Returns the number of videos from watchlist database.
/// \return integer
int RepositoryUser::getLength() {

    return (int)this->arr.size();
}

/// Gets all the arr of the videos from the watchlist database.
/// \return
std::vector<Video> RepositoryUser::getData() {

    return this->arr;
}

Video &RepositoryUser::getElement(int position) {

    return this->arr[position];
}



