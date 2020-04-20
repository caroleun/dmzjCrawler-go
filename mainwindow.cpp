#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "readprocess.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbtnSearch_clicked()
{
    QString query = ui->textSearch->toPlainText();
    QString cmd = "dmzj_go.exe -search " + query;
    QString result = ReadProcess(cmd).result;

    QStringList comics = result.split('\n', QString::SkipEmptyParts);

    ui->dispalyTable->setColumnCount(2);
    QStringList strListColumnHander;
    strListColumnHander << tr("ID") << tr("title");
    ui->dispalyTable->setHorizontalHeaderLabels(strListColumnHander); //设置列表头
    ui->dispalyTable->setRowCount(comics.length());
    for (int i = 0; i < comics.length(); ++i) {
        QStringList comicInfos = comics.at(i).split(',');
        QString comicIDStr = comicInfos.at(1);
        QString comicName = comicInfos.at(2);

        QTableWidgetItem* comicIDItem = new QTableWidgetItem(comicIDStr);
        QTableWidgetItem* comicNameItem = new QTableWidgetItem(comicName);
        ui->dispalyTable->setItem(i, 0, comicIDItem);
        ui->dispalyTable->setItem(i, 1, comicNameItem);
    }
}

void MainWindow::on_dispalyTable_cellClicked(int row, int column)
{
    ui->textID->setPlainText(ui->dispalyTable->item(row, 0)->data(0).toString());
}

void MainWindow::on_pbtnDownload_clicked()
{
    QString cmd = "dmzj_go.exe -path="+ui->textDirPath->toPlainText() + " -id="+ui->textID->toPlainText();
//    ui->statusText->setPlainText(cmd);
    ReadProcess process(cmd);
    ui->statusText->setPlainText("下载完成.");
}

void MainWindow::on_pbtnDirPath_clicked()
{
    QString dirPath = QFileDialog::getExistingDirectory(this, QString("选择目录"), QString("./"));
    ui->textDirPath->setPlainText(dirPath);
}
