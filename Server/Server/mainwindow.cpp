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
    QString name = QString("Enter Name");
    ui->setupUi(this);
    ui->participantTable->setRowCount(1);
    ui->participantTable->item(0,0)->setText(name);
//    ui->participantTable->item(ui->participantTable->rowCount()-1,1)->setText("Enter Class");
//    ui->participantTable->item(ui->participantTable->rowCount()-1,2)->setText("Enter Age");
//    ui->participantTable->item(ui->participantTable->rowCount()-1,3)->setText("Enter Gender");
//    ui->participantTable->item(ui->participantTable->rowCount()-1,4)->setText("Enter Rank");
    //    ui->participantTable->
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addEntry_clicked()
{
    ui->participantTable->insertRow(ui->participantTable->rowCount());
    ui->participantTable->item(ui->participantTable->rowCount()-1,0)->setText("Enter Name");
    ui->participantTable->item(ui->participantTable->rowCount()-1,1)->setText("Enter Class");
    ui->participantTable->item(ui->participantTable->rowCount()-1,2)->setText("Enter Age");
    ui->participantTable->item(ui->participantTable->rowCount()-1,3)->setText("Enter Gender");
    ui->participantTable->item(ui->participantTable->rowCount()-1,4)->setText("Enter Rank");
}

void MainWindow::on_saveTable_clicked()
{
    QJsonObject tableEntry;
    QJsonArray jsonTable;
    QFile savefile;
    for(int i =0; i < ui->participantTable->rowCount(); i++)
    {
//        if (ui->participantTable->item(i, 0)->text() == QString("") ||
//                ui->participantTable->item(i, 1)->text() == QString("")||
//                ui->participantTable->item(i, 2)->text() == QString("")||
//                ui->participantTable->item(i, 3)->text() == QString("")||
//                ui->participantTable->item(i, 4)->text() == QString(""))
//            return;

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
