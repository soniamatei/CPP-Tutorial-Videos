#ifndef A8_9_914_MATEI_SONIA_TEXTU_REPO_H
#define A8_9_914_MATEI_SONIA_TEXTU_REPO_H

#include "Urepository.h"

class TextURepository : public RepositoryUser {
private:
    std::string path = "../user/watchlist.txt";
    std::string path_html = "../user/watchlist.html";
    std::string path_csv = "../user/watchlist.csv";

public:
    TextURepository() {readFile();}

    void readFile();
    void writeFile();
    void writeFile_html();
    void writeFile_csv();
    void add(Video& video) override;
    void remove(int position) override;
};

#endif //A8_9_914_MATEI_SONIA_TEXTU_REPO_H
