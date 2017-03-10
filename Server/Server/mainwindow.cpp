#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonObject>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->participantTable->setRowCount(1);
//    ui->participantTable->
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addEntry_clicked()
{
    ui->participantTable->insertRow(1);
}

void MainWindow::on_saveTable_clicked()
{
    QJsonObject tableEntry;
    QJsonArray jsonTable;
    QFile savefile;
    for(int i =0; i < ui->participantTable->rowCount(); i++)
    {
        tableEntry["name"] = ui->participantTable->item(i, 0)->text();
        tableEntry["class"] = ui->participantTable->item(i, 1)->text();
        tableEntry["age"] = ui->participantTable->item(i, 2)->text();
        tableEntry["gender"] = ui->participantTable->item(i, 3)->text();
        tableEntry["rank"] = ui->participantTable->item(i, 4)->text();

        jsonTable.append(tableEntry);
    }

    QJsonDocument jsonDoc(jsonTable);
    qDebug() << "Example of QJsonDocument::toJson() >>>";
    qDebug() << jsonDoc.toJson();
    qDebug() << "<<<";
}

void MainWindow::on_loadTable_clicked()
{

}

void MainWindow::on_removeRow_clicked()
{
    if(ui->participantTable->rowCount() > 1)
        ui->participantTable->removeRow(ui->participantTable->rowCount()-1);
}
