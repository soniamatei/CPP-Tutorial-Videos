#ifndef A8_9_914_MATEI_SONIA_TEXT_REPO_H
#define A8_9_914_MATEI_SONIA_TEXT_REPO_H

#include "repository.h"

class TextRepository : public RepositoryAdministrator{

private:
    std::string path = "../administrator/read.txt";

public:
    TextRepository(){ readFile(); };

    void readFile();
    void writeFile();
    void add(Video& video, int position) override;
    void remove(int position) override;
    void update(Video& new_video, int position) override;
};


#endif //A8_9_914_MATEI_SONIA_TEXT_REPO_H
