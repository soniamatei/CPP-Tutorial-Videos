#include "text_repo.h"
#include "fstream"

void TextRepository::readFile() {

    Video video;
    std::ifstream file(path);

    while (file >> video) {
        RepositoryAdministrator::add(video, getLength());
    }
    writeFile();

    file.close();
}

void TextRepository::writeFile() {

    Video video;
    std::ofstream file(path);

    for (int i = 0; i < getLength(); i++){
        video = getElement(i);
        file << video;
    }

    file.close();
}

void TextRepository::add(Video &video, int position) {

    RepositoryAdministrator::add(video, position);
    writeFile();
}

void TextRepository::remove(int position) {

    RepositoryAdministrator::remove(position);
    writeFile();
}

void TextRepository::update(Video &new_video, int position) {

    RepositoryAdministrator::update(new_video, position);
    writeFile();
}




