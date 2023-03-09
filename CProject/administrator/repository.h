#ifndef A5_6_914_MATEI_SONIA_REPOSITORY_H
#define A5_6_914_MATEI_SONIA_REPOSITORY_H

#include "video.h"
#include <iostream>
#include <vector>

class RepositoryAdministrator {

private:
    std::vector<Video> arr;

public:
    void entities();
    Video& getElement(int position);
    virtual void add(Video& video, int position);
    virtual void remove(int position);
    virtual void update(Video& new_video, int position);
    std::vector<Video>& getData();
    int getLength();
};

#endif //A5_6_914_MATEI_SONIA_REPOSITORY_H
