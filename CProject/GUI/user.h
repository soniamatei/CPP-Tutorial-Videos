#ifndef DRAFT_USER_H
#define DRAFT_USER_H

#include <QtWidgets>
#include "../user/textu_repo.h"
#include "../administrator/repository.h"
#include "../user/Ucontroller.h"


class GuiUser : public QWidget{
Q_OBJECT

public:
    explicit GuiUser(ControllerUser& ctrl, QWidget *parent = nullptr);
    void build();
//    void add();
    void print_admin_list(std::vector<Video> &videos);
    void print_user_list();
    QString get_title();
    ~GuiUser() override;

private:
    QString title = "U\nS\nE\nR";
    ControllerUser ctrl;
    int position=0;

    // WIDGET
    QWidget* admin_print;
    QWidget* user_print;

    // LAYOUTS
    QVBoxLayout* layout_main;
    QVBoxLayout* layout_faro;
    QHBoxLayout* layout_aro_buttons;
    QHBoxLayout* layout_sb;
    QVBoxLayout* layout_label_form;
    QVBoxLayout* layout_search;
    QVBoxLayout* layout_playlist;
    QHBoxLayout* layout_exit;
    QHBoxLayout* layout_pv;

    // BUTTONS
    QPushButton* add_button;
    QPushButton* open_b_button;
    QPushButton* open_h_button;
    QPushButton* open_c_button;
    QPushButton* search_button;
    QPushButton* exit_button;
    QPushButton* next_button;
    QPushButton* previous_button;

    // FORMS
    QFormLayout* form;
    QLineEdit* line_edit_link;

    QFormLayout* search;
    QLineEdit* line_edit_search;

    // LISTVIEWS
    QStandardItemModel* admin_model;
    QListView* admin_list;
    QStandardItemModel* user_model;
    QListView* user_list;

public slots:
    void add();
    void shr();
    void open_browser();
    void open_html();
    void open_csv();
    void nextt();
    void previous();
};


#endif //DRAFT_USER_H
