#ifndef TOURNAMENTTABLE_H
#define TOURNAMENTTABLE_H

#include <QDialog>

namespace Ui {
class TournamentTable;
}

class TournamentTable : public QDialog
{
    Q_OBJECT

public:
    explicit TournamentTable(QWidget *parent = 0);
    ~TournamentTable();

private:
    Ui::TournamentTable *ui;
};

#endif // TOURNAMENTTABLE_H
