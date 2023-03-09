#include "csv_repo.h"
#include <fstream>

void CsvRepository::add(Video &video) {

    this->RepositoryUser::add(video);
    write_file();
}

void CsvRepository::remove(int position) {

    RepositoryUser::remove(position);
    write_file();
}

void CsvRepository::write_file() {

    std::ofstream file(path);

    for (int i = 0; i < getLength(); i++) {
        Video video = getElement(i);
        file << video.getTitle() << ",\"";
        file << video.getPresenter() << "\",";
        file << video.getMinutes() << ",";
        file << video.getSeconds() << ",";
        file << video.getLikes() << ",";
        file << video.getLink() << ",";
        file << video.getIs_Liked() << ",";
        file << video.getIs_Added() << "\n";
    }

    file.close();
}
