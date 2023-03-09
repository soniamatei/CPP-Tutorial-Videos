#ifndef A5_6_914_MATEI_SONIA_UREPOSITORY_H
#define A5_6_914_MATEI_SONIA_UREPOSITORY_H

#include "../administrator/video.h"
#include <vector>

class RepositoryUser {

private:
    std::vector<Video> arr;

public:
    virtual void add(Video& video);
    virtual void remove(int position);
    int getLength();
    std::vector<Video> getData();
    Video& getElement(int position);

};

#endif //A5_6_914_MATEI_SONIA_UREPOSITORY_H
