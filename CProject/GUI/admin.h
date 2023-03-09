#ifndef DRAFT_ADMIN_H
#define DRAFT_ADMIN_H

#include <QtWidgets>
#include "../administrator/video.h"
#include "../administrator/controller.h"

class GuiAdministrator : public QWidget{
    Q_OBJECT

public:
    explicit GuiAdministrator(ControllerAdministrator& ctrl, QWidget *parent = nullptr);
    void build();
    void print_list();
    QString get_title();
    ~GuiAdministrator() override;

private:
//    Ui::MainWindow *ui;
    QString title = "A\nD\nM\nI\nN\n";
    ControllerAdministrator ctrl;

    QVBoxLayout* layout_main;
    QVBoxLayout* layoutV;
    QHBoxLayout* layoutH;
    QVBoxLayout* layout_v_aru;
    QVBoxLayout* layout_label_form;
    QHBoxLayout* layout_exit;

    // BUTTONS
    QPushButton* add_button;
    QPushButton* remove_button;
    QPushButton* update_button;
    QPushButton* exit_button;

    // FORM
    QFormLayout* form ;
    QLineEdit* line_edit_title;
    QLineEdit* line_edit_presenter;
    QLineEdit* line_edit_minutes;
    QLineEdit* line_edit_seconds;
    QLineEdit* line_edit_likes;
    QLineEdit* line_edit_link;

    // LISTVIEW
    QStandardItemModel* model;
    QListView* list;

public slots:
    void add();
    void remove();
    void updated();
};

#endif //DRAFT_ADMIN_H
