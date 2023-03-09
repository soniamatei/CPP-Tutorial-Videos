#include "user.h"
#include "../administrator/video.h"

using namespace std;

GuiUser::GuiUser(ControllerUser& ctrl, QWidget *parent) : QWidget(parent),
ctrl(ctrl){}

QString GuiUser::get_title() {

    return title;
}

void GuiUser::build() {

    // STYLE
    this->setStyleSheet("QPushButton{"
                        "color: #f48c06;"
                        "background-color: #370617;}"
                        "width: 100px;"
                        "margin: 10px;}"
                        "QLayout{"
                        "margin-left: 30px;"
                        "margin-right: 20px;}"
                        "* {"
                        "color: #f48c06;}"
                        "QLineEdit{"
                        "border: 1px solid #811036;}");

    // WIDGET
    admin_print = new QWidget();
    admin_print->setMaximumHeight(600);
    user_print = new QWidget();
    user_print->setMaximumHeight(230);

    // LAYOUTS
    layout_main = new QVBoxLayout{};
    layout_faro = new QVBoxLayout{};
    layout_aro_buttons = new QHBoxLayout{};
    layout_sb = new QHBoxLayout{};
    layout_label_form = new QVBoxLayout{};
    layout_search = new QVBoxLayout{admin_print};
    layout_playlist = new QVBoxLayout{user_print};
    layout_exit = new QHBoxLayout{};
    layout_pv = new QHBoxLayout{};

    // BUTTONS
    add_button = new QPushButton("ADD", this);
    open_b_button = new QPushButton("BROWSER", this);
    open_h_button = new QPushButton("HTML", this);
    open_c_button = new QPushButton("CSV", this);
    search_button = new QPushButton("SEARCH", this);
    exit_button = new QPushButton("EXIT", this);
    next_button = new QPushButton("NEXT", this);
    previous_button = new QPushButton("PREVIOUS", this);

    // FORMS
    form = new QFormLayout();
    line_edit_link = new QLineEdit();
    form->addRow("LINK: ", line_edit_link);

    search = new QFormLayout();
    line_edit_search = new QLineEdit();
    search->addRow("SEARCH: ", line_edit_search);

    // LABELS
    auto* label_form = new QLabel("FORM", this);
    label_form->setStyleSheet("color: #811036; font-size: 20px; margin: 5px;");
    auto* label_videos = new QLabel("VIDEOS", this);
    label_videos->setStyleSheet("color: #811036; font-size: 20px; margin: 5px; margin-top: 30px;");
    auto* label_playlist = new QLabel("PLAYLIST", this);
    label_playlist->setStyleSheet("color: #811036; font-size: 20px; margin: 5px; margin-top: 30px;");


    // LISTVIEWS
    admin_model = new QStandardItemModel();
    admin_list = new QListView();
    admin_list->setEditTriggers(QAbstractItemView::NoEditTriggers);
    admin_list->setModel(admin_model);
    this->print_admin_list(ctrl.getData());

    user_model = new QStandardItemModel();
    user_list = new QListView();
    user_list->setEditTriggers(QAbstractItemView::NoEditTriggers);
    user_list->setModel(user_model);
    this->print_user_list();

    // ADD ALL TO LAYERS AND STYLE
    this->setLayout(layout_main);
    layout_main->setAlignment(layout_label_form, Qt::AlignTop);
    layout_main->addLayout(layout_label_form);
    layout_main->addLayout(layout_faro);
    layout_main->addWidget(admin_print);
    layout_main->addWidget(user_print);
    layout_main->addLayout(layout_exit);

    layout_faro->addLayout(form);
    layout_faro->addLayout(layout_aro_buttons);

    layout_aro_buttons->setSpacing(10);
    layout_aro_buttons->addWidget(add_button);
    layout_aro_buttons->addWidget(open_b_button);
    layout_aro_buttons->addWidget(open_h_button);
    layout_aro_buttons->addWidget(open_c_button);

    layout_label_form->addWidget(label_form);

    layout_search->addWidget(label_videos);
    layout_search->addLayout(layout_sb);
    layout_search->addWidget(admin_list);

    layout_sb->setSpacing(10);
    layout_sb->addLayout(search);
    layout_sb->addWidget(search_button);

    layout_playlist->addWidget(label_playlist);
    layout_playlist->addWidget(user_list);
    layout_playlist->addLayout(layout_pv);

    layout_pv->addWidget(previous_button);
    layout_pv->addWidget(next_button);

    layout_exit->addWidget(exit_button);

    connect(add_button, &QPushButton::clicked, this, &GuiUser::add);
    connect(search_button, &QPushButton::clicked, this, &GuiUser::shr);
    connect(open_b_button, &QPushButton::clicked, this, &GuiUser::open_browser);
    connect(open_h_button, &QPushButton::clicked, this, &GuiUser::open_html);
    connect(open_c_button, &QPushButton::clicked, this, &GuiUser::open_csv);
    connect(next_button, &QPushButton::clicked, this, &GuiUser::nextt);
    connect(previous_button, &QPushButton::clicked, this, &GuiUser::previous);
    connect(exit_button, &QPushButton::clicked, QApplication::instance(), &QApplication::quit);
}

void GuiUser::print_admin_list(std::vector<Video> &videos ) {

    admin_model->clear();

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
        admin_model->appendRow(item);
    }
}

void GuiUser::print_user_list() {

    user_model->clear();
    std::vector<Video> videos = ctrl.getWatchList();

    QString video;
    video.append("Title:   ");
    video.append(ctrl.getElementByPos(position).getTitle().c_str());
    video.append("\n");
    video.append("Presenter:   ");
    video.append(ctrl.getElementByPos(position).getPresenter().c_str());
    video.append("\n");
    video.append("Time:   ");
    video.append(QString::number(ctrl.getElementByPos(position).getMinutes()));
    video.append("m ");
    video.append(QString::number(ctrl.getElementByPos(position).getSeconds()));
    video.append("s\n");
    video.append("Likes:   ");
    video.append(QString::number(ctrl.getElementByPos(position).getLikes()));
    video.append("\n");
    video.append("Link:   ");
    video.append(ctrl.getElementByPos(position).getLink().c_str());
    video.append("\n");

    auto* item = new QStandardItem{video};
    QFont font = item->font();
    font.setBold(true);
    item->setFont(font);

    user_model->appendRow(item);

}

void GuiUser::add() {

    string link;
    link = line_edit_link->text().toStdString();

    ctrl.addToWatchList(link);

    this->print_user_list();
}

void GuiUser::shr() {

    string titl;
    titl = line_edit_search->text().toStdString();

    std::vector<string> links = ctrl.findAll(titl);
    std::vector<Video> videos;

    for (auto i : links)
        videos.push_back(ctrl.getElement(i));

    this->print_admin_list(videos);
}

void GuiUser::open_browser() {

    string link;
    link = line_edit_link->text().toStdString();

    ctrl.getElement(link).open(link);

    this->print_user_list();
}

void GuiUser::open_html() {

    ctrl.open("2");
}

void GuiUser::open_csv() {

    ctrl.open("1");
}

void GuiUser::nextt() {

    if (position == ctrl.getLength() - 1)
        position = 0;
    else position++;

    this->print_user_list();
}

void GuiUser::previous() {

    if (position == 0)
        position = ctrl.getLength() - 1;
    else position--;

    this->print_user_list();
}

GuiUser::~GuiUser()=default;
