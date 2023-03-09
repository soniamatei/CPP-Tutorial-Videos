#include "html_repo.h"
#include "../administrator/repository.h"
#include <fstream>

void HtmlRepository::write_file() {

    std::ofstream file(path);

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

void HtmlRepository::add(Video &video) {

    this->RepositoryUser::add(video);
    write_file();
}

void HtmlRepository::remove(int position) {

    RepositoryUser::remove(position);
    write_file();
}
