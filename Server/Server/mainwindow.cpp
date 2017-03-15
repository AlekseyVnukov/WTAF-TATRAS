#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonObject>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <stack>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QString name = QString("Enter Name");
    ui->setupUi(this);
    ui->participantTable->setRowCount(1);
    for (int i =0; i < ui->participantTable->columnCount(); i++)
    {
        QTableWidgetItem *aitem = ui->participantTable->item(0,i);
        if (!aitem)
        {
            aitem = new QTableWidgetItem;
            ui->participantTable->setItem(0,i,aitem);
        }
    }
        ui->participantTable->item(ui->participantTable->rowCount()-1,0)->setText("Enter Name");
        ui->participantTable->item(ui->participantTable->rowCount()-1,1)->setText("Enter Class");
        ui->participantTable->item(ui->participantTable->rowCount()-1,2)->setText("Enter Age");
        ui->participantTable->item(ui->participantTable->rowCount()-1,3)->setText("Enter Gender");
        ui->participantTable->item(ui->participantTable->rowCount()-1,4)->setText("Enter Rank");
//        aitem->setText(QString("Enter Name"));
//        aitem->setText(QString("Enter Class"));
//        aitem->setText(QString("Enter Age"));
//        aitem->setText(QString("Enter Gender"));
//        aitem->setText(QString("Enter Rank"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addEntry_clicked()
{
    ui->participantTable->insertRow(ui->participantTable->rowCount());
    for (int i =0; i < ui->participantTable->columnCount(); i++)
    {
        QTableWidgetItem *aitem = ui->participantTable->item(ui->participantTable->rowCount()-1,i);
        if (!aitem)
        {
            aitem = new QTableWidgetItem;
            ui->participantTable->setItem(ui->participantTable->rowCount()-1,i,aitem);
        }
    }
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
    QFile savefile("participants.tab");
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
    savefile.open(QFile::WriteOnly);
    savefile.write(jsonDoc.toJson());
    qDebug() << "Example of QJsonDocument::toJson() >>>";
    qDebug() << jsonDoc.toJson();
    qDebug() << "<<<";
}

void MainWindow::on_loadTable_clicked()
{
    QFile jsonFile("participants.tab");
    jsonFile.open(QFile::ReadOnly);
    QJsonDocument jsonDoc = QJsonDocument().fromJson(jsonFile.readAll());
//    qDebug() << "jsonDoc array check";
//    qDebug() << jsonDoc.isArray();
//    qDebug() << "<<<";
    QJsonArray jsonArray = jsonDoc.array();

    ui->participantTable->clear();
    for (int i = 0; i < ui->participantTable->columnCount(); i++)
    {
        QTableWidgetItem *aitem = ui->participantTable->horizontalHeaderItem(i);
        if (!aitem)
        {
            aitem = new QTableWidgetItem;
            ui->participantTable->setHorizontalHeaderItem(i,aitem);
        }
    }
    ui->participantTable->horizontalHeaderItem(0)->setText("Name");
    ui->participantTable->horizontalHeaderItem(1)->setText("Class");
    ui->participantTable->horizontalHeaderItem(2)->setText("Age");
    ui->participantTable->horizontalHeaderItem(3)->setText("Gender");
    ui->participantTable->horizontalHeaderItem(4)->setText("Rank");

    ui->participantTable->setRowCount(jsonArray.size());

    for (int i = 0; i < ui->participantTable->rowCount(); i++)
    {
        for (int j =0; j < ui->participantTable->columnCount(); j++)
        {
            QTableWidgetItem *aitem = ui->participantTable->item(i,j);
            if (!aitem)
            {
                aitem = new QTableWidgetItem;
                ui->participantTable->setItem(i,j,aitem);
            }
        }
        ui->participantTable->item(i, 0)->setText(jsonArray.at(i).toObject()["class"].toString());
        ui->participantTable->item(i, 1)->setText(jsonArray.at(i).toObject()["age"].toString());
        ui->participantTable->item(i, 2)->setText(jsonArray.at(i).toObject()["gender"].toString());
        ui->participantTable->item(i, 3)->setText(jsonArray.at(i).toObject()["rank"].toString());
        ui->participantTable->item(i, 4)->setText(jsonArray.at(i).toObject()["name"].toString());
        qDebug() << "checking jsonArray.at";
//        qDebug() << jsonArray.at(i).toObject()["class"].toString(); qDebug() << i; qDebug() << "<<<<";

//        ui->participantTable->sortItems(0);

    }
}

void MainWindow::on_removeRow_clicked()
{
    if(ui->participantTable->rowCount() > 1)
//        ui->participantTable->removeRow(ui->participantTable->rowCount()-1);
        ui->participantTable->removeRow(ui->participantTable->row(ui->participantTable->currentItem()));
}

//void MainWindow::on_groupsExport_clicked()
//{
//    std::stack nameStack;
//    for (int i = 0; i < ui->participantTable->rowCount(); i++)
//    {
//        nameStack.push(ui->participantTable->item(i,0)->text());
//    }
//}
