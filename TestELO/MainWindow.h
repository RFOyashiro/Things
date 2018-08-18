#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        void SetUpList();
        void SetUpLeader();
        void Sort ();
        ~MainWindow();

    private slots:
        void on_Send_clicked();
        void on_FileAvailable_clicked(const QModelIndex &index);
        void on_FileAvailable_doubleClicked(const QModelIndex &index);

    private:
        Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
