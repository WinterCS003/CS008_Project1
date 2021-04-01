#ifndef ITEM_REPORTS_H
#define ITEM_REPORTS_H

#include <QWidget>

namespace Ui {
class item_reports;
}

class item_reports : public QWidget
{
    Q_OBJECT

public:
    explicit item_reports(QWidget *parent = nullptr);
    ~item_reports();

private:
    Ui::item_reports *ui;
};

#endif // ITEM_REPORTS_H
