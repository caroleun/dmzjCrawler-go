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
    ~MainWindow();

//    int comicID;

private slots:
    void on_pbtnSearch_clicked();

    void on_dispalyTable_cellClicked(int row, int column);

    void on_pbtnDownload_clicked();

    void on_pbtnDirPath_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
