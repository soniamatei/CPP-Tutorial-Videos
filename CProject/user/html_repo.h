#ifndef A8_9_914_MATEI_SONIA_HTML_REPO_H
#define A8_9_914_MATEI_SONIA_HTML_REPO_H

#include "Urepository.h"

class HtmlRepository : public RepositoryUser {

private:
    std::string path = "../user/watchlist.html";

public:
    void write_file();
    void add(Video& video) override;
    void remove(int position) override;
};
#endif //A8_9_914_MATEI_SONIA_HTML_REPO_H
