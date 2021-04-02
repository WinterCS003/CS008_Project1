#ifndef MANAGEMEMBERS_H
#define MANAGEMEMBERS_H

#include <algorithm>

#include <QMainWindow>
#include <QMessageBox>
#include "members_container.h"

#include "sales/sales_container.h"

namespace Ui {
class manageMembers;
}

class manageMembers : public QMainWindow
{
    Q_OBJECT

public:
    manageMembers(QWidget *parent = nullptr);
    manageMembers(QWidget *parent, Members_Container* mc, sales_container* sc);
    ~manageMembers();

private slots:
    void on_button_addMember_clicked();

    void on_submit_clicked();

    void on_button_delete_Member_clicked();

    void on_submitDelete_clicked();

    void on_viewMemberInfo_clicked();

    void on_displayButton_clicked();

    void on_membersFromFile_clicked();

    void on_submitFile_clicked();

    void on_membersConvToBasic_clicked();

    void on_printTotalRebates_clicked();

private:
    Ui::manageMembers *ui;
    Members_Container* members;
    sales_container* all_sales;
};

#endif // MANAGEMEMBERS_H
