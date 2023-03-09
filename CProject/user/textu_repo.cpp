#include "textu_repo.h"
#include <fstream>

void TextURepository::readFile() {

    Video video;
    std::ifstream file(path);

    while (file >> video) {
        RepositoryUser::add(video);
    }
    writeFile();
    writeFile_csv();
    writeFile_html();

    file.close();
}

void TextURepository::writeFile() {

    Video video;
    std::ofstream file(path);

    for (int i = 0; i < getLength(); i++){
        video = getElement(i);
        file << video;
    }

    file.close();
}

void TextURepository::writeFile_csv() {

    std::ofstream file(path_csv);

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

void TextURepository::writeFile_html() {

    std::ofstream file(path_html);

    file << R"(<!DOCTYPE html>
<html lang="en">
<head>
    <title>Title</title>
</head>
<body>

</body>
</html>
<table border="1">
    <tr>
        <td>Title</td>
        <td>Presenter</td>
        <td>Minutes</td>
        <td>Seconds</td>
        <td>Likes</td>
        <td>Link</td>
        <td>Like</td>
        <td>Add</td>
    </tr>)";


    for (int i = 0; i < getLength(); i++){

        Video video = getElement(i);
        file << "<tr>" << "\n";
        file << "<td>" << video.getTitle() << "</td>" << "\n";
        file << "<td>" << video.getPresenter() << "</td>" << "\n";
        file << "<td>" << video.getMinutes() << "</td>" << "\n";
        file << "<td>" << video.getSeconds() << "</td>" << "\n";
        file << "<td>" << video.getLikes() << "</td>" << "\n";
        file << "<td>" << video.getLink() << "</td>" << "\n";
        file << "<td>" << video.getIs_Liked() << "</td>" << "\n";
        file << "<td><a href=\"" << video.getIs_Added() << "\">Link</a></td>" << "\n";
        file << "</tr>" << "\n";
    }

    file << R"(</table>
</body>
</html>)";
}

void TextURepository::add(Video &video) {

    RepositoryUser::add(video);
    video.setIs_Added("Added");
    writeFile();
    writeFile_csv();
    writeFile_html();
}

void TextURepository::remove(int position) {

    RepositoryUser::remove(position);
    writeFile();
    writeFile_csv();
    writeFile_html();
}
