#ifndef MANAGEMEMBERS_H
#define MANAGEMEMBERS_H

#include <QMainWindow>
#include "members_container.h"

namespace Ui {
class manageMembers;
}

class manageMembers : public QMainWindow
{
    Q_OBJECT

public:
    manageMembers(QWidget *parent = nullptr);
    manageMembers(QWidget *parent, Members_Container* mc);
    ~manageMembers();

private slots:
    void on_button_addMember_clicked();

    void on_submit_clicked();

    void on_submitDelete_clicked();

    void on_viewMemberInfo_clicked();

    void on_button_delete_Member_clicked();

    void on_displayButton_clicked();

private:
    Ui::manageMembers *ui;
    Members_Container* members;
};

#endif // MANAGEMEMBERS_H
