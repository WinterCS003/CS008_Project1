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
//    manageMembers(QWidget *parent = nullptr);
    manageMembers(QWidget *parent, const Members_Container& mc);
    ~manageMembers();

private slots:
    void on_addMemberButton_clicked();

    void on_submit_clicked();

    void on_deleteMemberButton_clicked();

    void on_submitDelete_clicked();

    void on_viewMemberInfo_clicked();

private:
    Ui::manageMembers *ui;
    Members_Container members;
};

#endif // MANAGEMEMBERS_H
