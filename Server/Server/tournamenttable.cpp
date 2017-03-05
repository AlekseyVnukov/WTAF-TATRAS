#include "tournamenttable.h"
#include "ui_tournamenttable.h"

TournamentTable::TournamentTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TournamentTable)
{
    ui->setupUi(this);
}

TournamentTable::~TournamentTable()
{
    delete ui;
}
