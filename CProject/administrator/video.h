#ifndef A5_6_914_MATEI_SONIA_VIDEO_H
#define A5_6_914_MATEI_SONIA_VIDEO_H

#include <string>

class Video {

public:
    struct Duration{
        int minutes, seconds;
    };

private:
    std::string title;
    std::string presenter;
    Duration duration{};
    int likes{};
    std::string link;
    std::string is_liked;
    std::string is_added;

public:
    Video();
    Video(const std::string& title,const std::string& presenter,int minutes,
          int seconds, int likes,const std::string& link);

    std::string& getPresenter();
    int& getLikes();
    std::string getIs_Liked();
    std::string& getLink();
    void setLikes(int value);
    void setIs_Liked(std::string value);
    void setIs_Added(std::string value);
    void printVideoAdministrator();
    void printVideoUser(bool& stop);
    friend std::istream & operator>>(std::istream & stream, Video& video);
    friend std::ostream & operator<<(std::ostream & stream, const Video& video);
    void open(std::string link);
    std::string getTitle();
    int getMinutes();
    int getSeconds();
    std::string getIs_Added();
};

#endif //A5_6_914_MATEI_SONIA_VIDEO_H
