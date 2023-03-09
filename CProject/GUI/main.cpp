#include "mainwindow.h"
#include "admin.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QFormLayout>
#include "../administrator/controller.h"
#include "../user/textu_repo.h"
#include "../administrator/repository.h"


//#include <QApplication>
//#include <QLocale>
//#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RepositoryAdministrator admin_repo;
    ControllerAdministrator admin_ctrl{admin_repo};

    TextURepository user_repo;
    ControllerUser user_ctrl{admin_repo, user_repo};

    auto* main_window = new MainWindow{admin_ctrl, user_ctrl};
    main_window->build();
    main_window->show();

    return a.exec();
}
