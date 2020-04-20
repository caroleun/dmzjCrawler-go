/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
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
    QPushButton *pbtnSearch;
    QPushButton *pbtnDownload;
    QPlainTextEdit *textSearch;
    QLabel *label;
    QLabel *label_2;
    QPlainTextEdit *textID;
    QTableWidget *dispalyTable;
    QPlainTextEdit *statusText;
    QPlainTextEdit *textDirPath;
    QPushButton *pbtnDirPath;
    QLabel *label_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(674, 525);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pbtnSearch = new QPushButton(centralWidget);
        pbtnSearch->setObjectName(QStringLiteral("pbtnSearch"));
        pbtnSearch->setGeometry(QRect(538, 29, 93, 28));
        pbtnDownload = new QPushButton(centralWidget);
        pbtnDownload->setObjectName(QStringLiteral("pbtnDownload"));
        pbtnDownload->setGeometry(QRect(440, 240, 161, 91));
        QFont font;
        font.setPointSize(15);
        font.setBold(false);
        font.setWeight(50);
        pbtnDownload->setFont(font);
        textSearch = new QPlainTextEdit(centralWidget);
        textSearch->setObjectName(QStringLiteral("textSearch"));
        textSearch->setGeometry(QRect(121, 24, 410, 39));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(24, 24, 90, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(24, 72, 91, 16));
        textID = new QPlainTextEdit(centralWidget);
        textID->setObjectName(QStringLiteral("textID"));
        textID->setGeometry(QRect(122, 72, 251, 39));
        dispalyTable = new QTableWidget(centralWidget);
        dispalyTable->setObjectName(QStringLiteral("dispalyTable"));
        dispalyTable->setGeometry(QRect(20, 170, 351, 221));
        statusText = new QPlainTextEdit(centralWidget);
        statusText->setObjectName(QStringLiteral("statusText"));
        statusText->setGeometry(QRect(20, 410, 351, 41));
        textDirPath = new QPlainTextEdit(centralWidget);
        textDirPath->setObjectName(QStringLiteral("textDirPath"));
        textDirPath->setGeometry(QRect(133, 121, 237, 39));
        pbtnDirPath = new QPushButton(centralWidget);
        pbtnDirPath->setObjectName(QStringLiteral("pbtnDirPath"));
        pbtnDirPath->setGeometry(QRect(440, 120, 151, 41));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(21, 121, 105, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 674, 26));
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
        pbtnSearch->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242", Q_NULLPTR));
        pbtnDownload->setText(QApplication::translate("MainWindow", "\344\270\213\350\275\275", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242\346\274\253\347\224\273\345\220\215\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276\346\274\253\347\224\273id\357\274\232", Q_NULLPTR));
        textDirPath->setPlainText(QApplication::translate("MainWindow", "./", Q_NULLPTR));
        pbtnDirPath->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\344\277\235\345\255\230\350\267\257\345\276\204\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
