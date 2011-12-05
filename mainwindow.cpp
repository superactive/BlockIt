#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BIItem.h"
#include <vector>
#include <QFileDialog>
#include <QListWidgetItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btnBrowse, SIGNAL(clicked()), this, SLOT(fileDialog()));
    connect(ui->btnBlock, SIGNAL(clicked()), this, SLOT(block()));
}

void MainWindow::fileDialog()
{
    QString path = QFileDialog::getOpenFileName(this, "Select an executable", "", "Executables (*.exe)");
}

void MainWindow::fillAppsInstalledList()
{
    fillList(ui->listAppsInstalled, installedItems);
}

void MainWindow::fillAppsRunningList()
{
    // Query library for running executables and store in runningItems
    fillList(ui->listAppsRunning, runningItems);
}

void MainWindow::fillList(QListWidget list, std::vector<BIItem> items)
{
    if (items.size() > 0)
    {
        list.clear();

        for (int i = 0; i < installedItems.size(); i++)
        {
            QIcon icon(QString(items[i].getIconPath().c_str()));
            QListWidgetItem item(icon, QString(items[i].getName().c_str()));
            list.addItem(&item);
        }
    }
}

void MainWindow::block()
{
    BIItem item;
    QString path = "";

    if (ui->tabAppList->currentIndex() == 0)
        item = installedItems[ui->listAppsInstalled->currentRow()];
    else if (ui->tabAppList->currentIndex() == 1)
        item = installedItems[ui->listAppsRunning->currentRow()];

    // Call blocking library here
    // maybe item->block();
}

MainWindow::~MainWindow()
{
    delete ui;
}
