/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTableWidget *participantTable;
    QPushButton *groupsExport;
    QLabel *label;
    QPushButton *addEntry;
    QPushButton *saveTable;
    QPushButton *loadTable;
    QPushButton *removeRow;
    QLineEdit *lineEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(890, 373);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        participantTable = new QTableWidget(centralWidget);
        if (participantTable->columnCount() < 5)
            participantTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        participantTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        participantTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        participantTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        participantTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        participantTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        participantTable->setObjectName(QStringLiteral("participantTable"));
        participantTable->setGeometry(QRect(10, 30, 511, 241));
        participantTable->setSortingEnabled(true);
        participantTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        participantTable->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        groupsExport = new QPushButton(centralWidget);
        groupsExport->setObjectName(QStringLiteral("groupsExport"));
        groupsExport->setGeometry(QRect(620, 120, 91, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(620, 40, 101, 16));
        addEntry = new QPushButton(centralWidget);
        addEntry->setObjectName(QStringLiteral("addEntry"));
        addEntry->setGeometry(QRect(20, 290, 75, 23));
        saveTable = new QPushButton(centralWidget);
        saveTable->setObjectName(QStringLiteral("saveTable"));
        saveTable->setGeometry(QRect(240, 290, 75, 23));
        loadTable = new QPushButton(centralWidget);
        loadTable->setObjectName(QStringLiteral("loadTable"));
        loadTable->setGeometry(QRect(350, 290, 75, 23));
        removeRow = new QPushButton(centralWidget);
        removeRow->setObjectName(QStringLiteral("removeRow"));
        removeRow->setGeometry(QRect(130, 290, 75, 23));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(620, 80, 113, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 890, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = participantTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = participantTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Class", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = participantTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Age", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = participantTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Gender", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = participantTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Rank", Q_NULLPTR));
        groupsExport->setText(QApplication::translate("MainWindow", "Form Groups", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Groups number", Q_NULLPTR));
        addEntry->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        saveTable->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        loadTable->setText(QApplication::translate("MainWindow", "Load", Q_NULLPTR));
        removeRow->setText(QApplication::translate("MainWindow", "Remove", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
