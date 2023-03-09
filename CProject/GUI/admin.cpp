#include "admin.h"
#include <QtWidgets>
#include <iostream>
#include "../administrator/controller.h"

using namespace std;

GuiAdministrator::GuiAdministrator(ControllerAdministrator &ctrl, QWidget *parent) : QWidget(parent), ctrl(ctrl) {}

void GuiAdministrator::build() {

    // STYLE
    this->setStyleSheet("QPushButton{"
                        "color: #f48c06;"
                        "background-color: #370617;}"
                        "width: 100px;}"
                        "QLayout{"
                        "margin-left: 30px;"
                        "margin-right: 20px;}"
                        "* {"
                        "color: #f48c06;}"
                        "QLineEdit{"
                        "border: 1px solid #811036;}");

    // ALIGNMENTS
    layout_main = new QVBoxLayout{};
    layoutV = new QVBoxLayout{};
    layoutH = new QHBoxLayout{};
    layout_v_aru = new QVBoxLayout{};
    layout_label_form = new QVBoxLayout{};
    layout_exit = new QHBoxLayout{};

    // BUTTONS
    add_button = new QPushButton("ADD", this);
    remove_button = new QPushButton("REMOVE", this);
    update_button = new QPushButton("UPDATE", this);
    exit_button = new QPushButton("EXIT", this);

    // FORM
    form = new QFormLayout();
    line_edit_title = new QLineEdit();
    line_edit_presenter = new QLineEdit();
    line_edit_minutes = new QLineEdit();
    line_edit_seconds = new QLineEdit();
    line_edit_likes = new QLineEdit();
    line_edit_link = new QLineEdit();
    form->addRow("TITLE: ", line_edit_title);
    form->addRow("PRESENTER: ", line_edit_presenter);
    form->addRow("MINUTES: ", line_edit_minutes);
    form->addRow("SECONDS: ", line_edit_seconds);
    form->addRow("LIKES: ", line_edit_likes);
    form->addRow("LINK: ", line_edit_link);

    // LABELS
    auto* label_form = new QLabel("FORM", this);
    label_form->setStyleSheet("color: #811036; font-size: 20px; margin: 5px;");
    auto* label_videos = new QLabel("VIDEOS", this);
    label_videos->setStyleSheet("color: #811036; font-size: 20px; margin: 5px; margin-top: 30px;");

    // LISTVIEW
    model = new QStandardItemModel();

    list = new QListView();
    list->setEditTriggers(QAbstractItemView::NoEditTriggers);
    list->setModel(model);
    this->print_list();

    // ADD ALL TO LAYERS AND STYLE
    this->setLayout(layout_main);
    layout_main->addLayout(layout_label_form);
    layout_main->addLayout(layoutH);
    layout_main->addLayout(layoutV);
    layout_main->addLayout(layout_exit);
    layout_main->setAlignment(Qt::AlignTop);

    layout_exit->addWidget(exit_button);

    layout_label_form->addWidget(label_form);

    layoutH->addLayout(form);
    layoutH->addLayout(layout_v_aru);

    layout_v_aru->addWidget(add_button);
    layout_v_aru->addWidget(remove_button);
    layout_v_aru->addWidget(update_button);

    layoutV->addWidget(label_videos);
    layoutV->addWidget(list);


    connect(exit_button, &QPushButton::clicked, QApplication::instance(), &QApplication::quit);
    connect(add_button, &QPushButton::clicked, this, &GuiAdministrator::add);
    connect(remove_button, &QPushButton::clicked, this, &GuiAdministrator::remove);
    connect(update_button, &QPushButton::clicked, this, &GuiAdministrator::updated);
}

QString GuiAdministrator::get_title() {

    return title;
}

void GuiAdministrator::add() {

    string titl, presenter, link;
    int minutes, seconds, likes;

    titl = line_edit_title->text().toStdString();
    presenter = line_edit_presenter->text().toStdString();
    minutes = line_edit_minutes->text().toInt();
    seconds = line_edit_seconds->text().toInt();
    likes = line_edit_likes->text().toInt();
    link = line_edit_link->text().toStdString();

    ctrl.add(titl, presenter, minutes, seconds, likes, link);

    this->print_list();
}

void GuiAdministrator::remove() {

    string link;
    link = line_edit_link->text().toStdString();

    ctrl.remove(link);

    this->print_list();
}

void GuiAdministrator::updated() {

    string titl, presenter, link;
    int minutes, seconds, likes;

    titl = line_edit_title->text().toStdString();
    presenter = line_edit_presenter->text().toStdString();
    minutes = line_edit_minutes->text().toInt();
    seconds = line_edit_seconds->text().toInt();
    likes = line_edit_likes->text().toInt();
    link = line_edit_link->text().toStdString();

    ctrl.update(link, titl, presenter, minutes, seconds, likes, link);

    this->print_list();
}

void GuiAdministrator::print_list() {

    model->removeRows(0,model->rowCount());
    std::vector<Video> videos = ctrl.getData();

    for(auto i: videos) {

        QString video;
        video.append("Title:   ");
        video.append(i.getTitle().c_str());
        video.append("\n");
        video.append("Presenter:   ");
        video.append(i.getPresenter().c_str());
        video.append("\n");
        video.append("Time:   ");
        video.append(QString::number(i.getMinutes()));
        video.append("m ");
        video.append(QString::number(i.getSeconds()));
        video.append("s\n");
        video.append("Likes:   ");
        video.append(QString::number(i.getLikes()));
        video.append("\n");
        video.append("Link:   ");
        video.append(i.getLink().c_str());
        video.append("\n");

        auto* item = new QStandardItem{video};
        model->appendRow(item);
    }
}

GuiAdministrator::~GuiAdministrator() = default;
