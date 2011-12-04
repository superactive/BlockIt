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
    ui->listAppsInstalled->clear();

    for (int i = 0; i < items.size(); i++)
    {
        QIcon icon(QString(items[i].getIconPath().c_str()));
        QListWidgetItem item(icon, QString(items[i].getName().c_str()));
        ui->listAppsInstalled->addItem(&item);
    }
}

void MainWindow::fillAppsRunningList()
{
    // Query library for running executables
}

void MainWindow::block()
{
    BIItem item = BIItem();
    QString path = "";

    if (ui->tabAppList->currentIndex() == 0)
        item = ui->listAppsInstalled->selectedItems()[0]->data(0).value<BIItem>();
    else if (ui->tabAppList->currentIndex() == 1)
        item = ui->listAppsRunning->selectedItems()[0]->data(0).value<BIItem>();

    // Call blocking library here
    // maybe item->block();
}

MainWindow::~MainWindow()
{
    delete ui;
}
