#include "mainwindow.h"
#include <QVBoxLayout>
#include <QTextEdit>
#include <QWidget>

MainWindow::MainWindow(ControllerAdministrator& admin_ctrl, ControllerUser &user_ctrl, QWidget *parent) : QTabWidget(parent),
                                                                                                          user_ctrl(user_ctrl), admin_ctrl(admin_ctrl) {

    setTabBar(new TabBar);
    setTabPosition(QTabWidget::West);
}

void MainWindow::build() {

    this->resize(600, 900);

    admin = new GuiAdministrator{admin_ctrl, this};
    user = new GuiUser{user_ctrl, this};
    this->addTab(admin, admin->get_title());
    this->addTab(user, user->get_title());
    admin->build();
    user->build();

//    auto* layout = new QVBoxLayout{};
//    this->setLayout(layout);
    this->setStyleSheet("QTabBar::tab {"
                        "color: #f8961e;"
                        "font-size: 15px;"
                        "font-weight: bold;"
                        "width: 450px;"
                        "background-color: #3A0517;}"
                        "QTabWidget QTabBar::tab:selected{"
                        "background-color: #811036;"
                        "}"
                        "QWidget{"
                        "background-color: black;}");
}

MainWindow::~MainWindow()=default;
