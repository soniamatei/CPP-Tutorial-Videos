#ifndef A8_9_914_MATEI_SONIA_LAB_ACTIVITY_H
#define A8_9_914_MATEI_SONIA_LAB_ACTIVITY_H

#include <iostream>
#include <vector>
#include "administrator/video.h"
#include "administrator/controller.h"
#include "administrator/repository.h"
#include <cassert>


template <typename T>
class Comparator {
public:
    virtual bool compare(T& elem1, T& elem2)=0;
};

template <typename Video>
class ComparatorAscTitle : public Comparator<Video> {
public:
     bool compare(Video &elem1, Video &elem2) override {

        return elem1.getTitle() < elem2.getTitle();
    }
};

template <typename Video>
class ComparatorDescLikes: public Comparator<Video> {
public:
    bool compare(Video& elem1, Video& elem2) override {

        return elem1.getLikes() >= elem2.getLikes();
    }
};

template <typename Video>
void sortVec(std::vector<Video>& arr, Comparator<Video>& cmp_class) {

    int ok = 0;
    while (!ok) {

        ok = 1;
        for (auto i = arr.begin(); i < arr.end() - 1; i++) {

            if (!cmp_class.compare(*i, *(i + 1))) {
                std::swap(*i, *(i+1));
                ok = 0;
            }
        }
    }
}

void testSort() {

    RepositoryAdministrator repo;
    ControllerAdministrator ctrl{repo};

    ComparatorDescLikes<Video> cmp1;
    ComparatorAscTitle<Video> cmp2;

    std::vector<Video> data = ctrl.getData();

    sortVec(data, cmp2);
    assert(data[0].getTitle() == "CONST in C++");

    sortVec(data, cmp1);
    assert(data[0].getLikes() == 14000);
    std::cout << "tested\n";
}

#endif //A8_9_914_MATEI_SONIA_LAB_ACTIVITY_H
