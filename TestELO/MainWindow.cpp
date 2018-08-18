#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QStringListModel>
#include <QFile>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QModelIndex>
#include <QTextStream>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

void MainWindow::SetUpList() {
    QStringListModel *model;

    // Create model
    model = new QStringListModel(this);

    QStringList stringList;

    // open the file
    QFile textFile("test.txt");
    if(!textFile.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0,"Error",textFile.errorString());
    }

    // teststream to read from file
    QTextStream textStream(&textFile);
    while (true)
    {
        QString line = textStream.readLine();
        if (line.isNull())
            break;
        else
            stringList.append(line); // populate the stringlist
    }

    // Populate the model
    model->setStringList(stringList);

    // Glue model and view together
    ui->FileAvailable->setModel(model);
}

void MainWindow::SetUpLeader() {
    QStringListModel *model;

    // Create model
    model = new QStringListModel(this);

    QStringList stringList;

    // open the file
    QFile textFile("Leaderboard.txt");
    if(!textFile.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0,"Error",textFile.errorString());
    }

    // teststream to read from file
    QTextStream textStream(&textFile);
    while (true)
    {
        QString line = textStream.readLine();
        if (line.isNull())
            break;
        else
            stringList.append(line); // populate the stringlist
    }

    // Populate the model
    model->setStringList(stringList);

    // Glue model and view together
    ui->Classement->setModel(model);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SetUpList();
    SetUpLeader();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void UpdateList (string Player) {
    ofstream File ("test.txt", ios_base::app);
    File << Player;
}

unsigned GetELO (string Player) {
    ifstream File ("Profile\\"+ Player + ".ELO");
    if (File.peek() == EOF) {
        UpdateList(Player);
    }
    unsigned ELO = 1000;
    File >> ELO;
    return ELO;
}

/*void SendDatabase (vector <pair <string, unsigned>> ELO) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("mysql-oyashiro.alwaysdata.net");
    db.setDatabaseName("oyashiro_inscription");
    db.setUserName("oyashiro");
    db.setPassword("thepassword");
    bool ok = db.open();
    if (!ok) cout << "c'est la merde" << endl;

    for (unsigned i (0); i < ELO.size(); ++i) {
        QSqlQuery query ("INSERT INTO SSO (NAME, SCORE, POSITION) VALUES ('" + QString::fromStdString(ELO[i].first)
                         + "', " + QString::fromStdString(to_string(ELO[i].second)) + ", " + QString::fromStdString(to_string(i + 1)) + ");");
        query.exec();
    }
}*/

void MainWindow::Sort () {
    ifstream Getter ("test.txt");
    vector <pair <string, unsigned>> ELO;
    while (Getter.peek() != EOF) {
        pair <string, unsigned> Player;
        Getter >> Player.first;
        if (Player.first == "") break;
        Player.second = 0;
        ELO.push_back(Player);
    }

    for (unsigned i (0); i < ELO.size(); ++i) {
        ifstream GetterELO ("Profile\\" + ELO[i].first + ".ELO");
        GetterELO >> ELO[i].second;
    }

    ofstream File ("Leaderboard.txt");
    for (unsigned i (0); i < ELO.size(); ++i)
        for (unsigned j (i + 1); j < ELO.size(); ++j)
            if (ELO[i].second < ELO[j].second)
                swap (ELO[i], ELO[j]);
    for (unsigned i (0); i < ELO.size(); ++i)
        File << i + 1 << "e" << ((i < 9) ?  "  - " : " - ") << ELO[i].first << " : " << ELO[i].second << endl;

//    SendDatabase(ELO);

    ui->Max->setText(QString::fromStdString(ELO[0].first + " : " + to_string(ELO[0].second)));
    ui->Min->setText(QString::fromStdString(ELO[ELO.size()-1].first + " : " + to_string(ELO[ELO.size()-1].second)));
    unsigned Sum = 0;
    for (unsigned i (0); i < ELO.size(); ++i)
        Sum += ELO[i].second;
    ui->Moy->setText(QString::fromStdString(to_string(Sum / ELO.size())));
}

void SaveELO (string Player, unsigned ELO) {
    ofstream File ("Profile\\" + Player + ".ELO");
    File << ELO;
}

double GetProbaWin (unsigned D) {
    return 1 / (1 + (pow(10, (double) -D / 400)));
}

void ComputeELO (unsigned & ELOPlayer1, bool Player1IsWin, unsigned & ELOPlayer2) {
    double pD = GetProbaWin(ELOPlayer1 - ELOPlayer2);
    ELOPlayer1 += ((ELOPlayer1 <= 2000) ? 40 : ((ELOPlayer1 <= 2400) ? 20 : 10)) * ((( Player1IsWin) ? 1 : 0) - pD);
    ELOPlayer2 += ((ELOPlayer2 <= 2000) ? 40 : ((ELOPlayer2 <= 2400) ? 20 : 10)) * (((!Player1IsWin) ? 1 : 0) - (1 - pD));
}

void MainWindow::on_Send_clicked()
{
    string P1 = ui->Player1->text().toStdString();
    string P2 = ui->Player2->text().toStdString();

    unsigned ELO1 = GetELO(P1);
    unsigned ELO2 = GetELO(P2);

    ComputeELO(ELO1, true, ELO2);

    SaveELO(P1, ELO1);
    SaveELO(P2, ELO2);

    SetUpList();

    ui->ELOP1->setText(QString::fromStdString(P1 + " : " + to_string(ELO1)));
    ui->ELOP2->setText(QString::fromStdString(P2 + " : " + to_string(ELO2)));

    ui->Player1->setText("");
    ui->Player2->setText("");

    Sort();
    SetUpLeader();

}

void MainWindow::on_FileAvailable_clicked(const QModelIndex &index)
{
    string EloValue = to_string(GetELO(index.data().toString().toStdString()));
    QString ELO;
    ELO = index.data().toString();
    ELO += " : ";
    ELO += QString::fromStdString(EloValue);

    ui->ELOSelected->setText(ELO);
}

void MainWindow::on_FileAvailable_doubleClicked(const QModelIndex &index)
{
    if (ui->Player1->text() == "")
        ui->Player1->setText(index.data().toString());
    else if (ui->Player2->text() == "")
        ui->Player2->setText(index.data().toString());
}
