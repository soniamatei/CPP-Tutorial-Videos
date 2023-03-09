#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
//QT_END_NAMESPACE

#include <QTabWidget>
#include "admin.h"
#include <QStyleOptionTab>
#include <QStylePainter>
#include <QTabBar>
#include <QTabWidget>
#include "../administrator/repository.h"
#include "../user/textu_repo.h"
#include "user.h"
#include "../user/Ucontroller.h"

class MainWindow : public QTabWidget {
    Q_OBJECT

private:
    GuiAdministrator *admin{};
    GuiUser* user{};
    ControllerAdministrator admin_ctrl;
    ControllerUser user_ctrl;

public:
    explicit MainWindow(ControllerAdministrator& admin_ctrl, ControllerUser &user_ctrl, QWidget *parent = nullptr);
    void build();
    ~MainWindow() override;
};


class TabBar: public QTabBar{
public:
    QSize tabSizeHint(int index) const{
        QSize s = QTabBar::tabSizeHint(index);
        s.transpose();
        return s;
    }
protected:
    void paintEvent(QPaintEvent * /*event*/){
        QStylePainter painter(this);
        QStyleOptionTab opt;

        for(int i = 0;i < count();i++)
        {
            initStyleOption(&opt,i);
            painter.drawControl(QStyle::CE_TabBarTabShape, opt);
            painter.save();

            QSize s = opt.rect.size();
            s.transpose();
            QRect r(QPoint(), s);
            r.moveCenter(opt.rect.center());
            opt.rect = r;

            QPoint c = tabRect(i).center();
            painter.translate(c);
            painter.rotate(90);
            painter.translate(-c);
            painter.drawControl(QStyle::CE_TabBarTabLabel,opt);
            painter.restore();
        }
    }
};

#endif // MAINWINDOW_H
