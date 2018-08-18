/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionEntrer_R_sultat;
    QAction *actionClassement;
    QWidget *centralWidget;
    QListView *FileAvailable;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *Player1;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *Player2;
    QLabel *label_6;
    QPushButton *Send;
    QListView *Classement;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QLabel *ELOP1;
    QLabel *ELOP2;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QLabel *ELOSelected;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_4;
    QFrame *line;
    QLabel *label_7;
    QLabel *Max;
    QLabel *label_13;
    QLabel *label_8;
    QLabel *Min;
    QLabel *label_11;
    QLabel *label_9;
    QLabel *Moy;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(424, 616);
        actionEntrer_R_sultat = new QAction(MainWindow);
        actionEntrer_R_sultat->setObjectName(QStringLiteral("actionEntrer_R_sultat"));
        actionClassement = new QAction(MainWindow);
        actionClassement->setObjectName(QStringLiteral("actionClassement"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        FileAvailable = new QListView(centralWidget);
        FileAvailable->setObjectName(QStringLiteral("FileAvailable"));
        FileAvailable->setGeometry(QRect(160, 0, 256, 291));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 141, 161));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        Player1 = new QLineEdit(layoutWidget);
        Player1->setObjectName(QStringLiteral("Player1"));

        verticalLayout->addWidget(Player1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        Player2 = new QLineEdit(layoutWidget);
        Player2->setObjectName(QStringLiteral("Player2"));

        verticalLayout->addWidget(Player2);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout->addWidget(label_6);

        Send = new QPushButton(layoutWidget);
        Send->setObjectName(QStringLiteral("Send"));

        verticalLayout->addWidget(Send);

        Classement = new QListView(centralWidget);
        Classement->setObjectName(QStringLiteral("Classement"));
        Classement->setGeometry(QRect(10, 310, 256, 261));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 180, 141, 53));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);

        ELOP1 = new QLabel(widget);
        ELOP1->setObjectName(QStringLiteral("ELOP1"));

        verticalLayout_2->addWidget(ELOP1);

        ELOP2 = new QLabel(widget);
        ELOP2->setObjectName(QStringLiteral("ELOP2"));

        verticalLayout_2->addWidget(ELOP2);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 250, 141, 34));
        verticalLayout_3 = new QVBoxLayout(widget1);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_3->addWidget(label_4);

        ELOSelected = new QLabel(widget1);
        ELOSelected->setObjectName(QStringLiteral("ELOSelected"));

        verticalLayout_3->addWidget(ELOSelected);

        widget2 = new QWidget(centralWidget);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(280, 310, 131, 191));
        verticalLayout_4 = new QVBoxLayout(widget2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        line = new QFrame(widget2);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);

        label_7 = new QLabel(widget2);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_4->addWidget(label_7);

        Max = new QLabel(widget2);
        Max->setObjectName(QStringLiteral("Max"));

        verticalLayout_4->addWidget(Max);

        label_13 = new QLabel(widget2);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout_4->addWidget(label_13);

        label_8 = new QLabel(widget2);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_4->addWidget(label_8);

        Min = new QLabel(widget2);
        Min->setObjectName(QStringLiteral("Min"));

        verticalLayout_4->addWidget(Min);

        label_11 = new QLabel(widget2);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_4->addWidget(label_11);

        label_9 = new QLabel(widget2);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_4->addWidget(label_9);

        Moy = new QLabel(widget2);
        Moy->setObjectName(QStringLiteral("Moy"));

        verticalLayout_4->addWidget(Moy);

        MainWindow->setCentralWidget(centralWidget);
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionEntrer_R_sultat->setText(QApplication::translate("MainWindow", "Entrer R\303\251sultat", 0));
        actionClassement->setText(QApplication::translate("MainWindow", "Classement", 0));
        label->setText(QApplication::translate("MainWindow", "Gagnant", 0));
        label_3->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Perdant", 0));
        label_6->setText(QString());
        Send->setText(QApplication::translate("MainWindow", "Send Result", 0));
        label_5->setText(QApplication::translate("MainWindow", "Nouveau ELO : ", 0));
        ELOP1->setText(QString());
        ELOP2->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "ELO du joueur selection\303\251 : ", 0));
        ELOSelected->setText(QString());
        label_7->setText(QApplication::translate("MainWindow", "ELO Max", 0));
        Max->setText(QString());
        label_13->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "ELO Min", 0));
        Min->setText(QString());
        label_11->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "ELO Moy", 0));
        Moy->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
