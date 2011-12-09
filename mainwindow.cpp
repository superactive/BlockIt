#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BIItem.h"
#include <vector>
#include <QFileDialog>
#include <QListWidgetItem>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btnBrowse, SIGNAL(clicked()), this, SLOT(fileDialog()));
    connect(ui->btnBlock, SIGNAL(clicked()), this, SLOT(block()));

    fillBIItemsList(installedItems);
    fillBIItemsList(runningItems);

    fillAppsInstalledList();
    fillAppsRunningList();
}

void MainWindow::fillBIItemsList(std::vector<BIItem> &list)
{
    // fill list with call to library or interface
    // maybe do this in the constructor instead
    //    BIItem item("/Users/Eric/Desktop/test.exe", "/Users/Eric/Pictures/Deadmau5.png", "Testing");
    //    BIItem item2("/Users/Eric/Desktop/test.exe", "/Users/eric/Documents/School/UTC [Past]/CPSC 261 (C++)/Game.ico", "Testing Again");
    //    BIItem item3("/Users/Eric/Desktop/test.exe", "/Users/Eric/Pictures/appletimeline.tiff", "Testing Some More");

    //    list.push_back(item);
    //    list.push_back(item2);
    //    list.push_back(item3);
}

void MainWindow::fillAppsInstalledList()
{
    fillListWidget(ui->listAppsInstalled, installedItems);
}

void MainWindow::fillAppsRunningList()
{
    // Query library for running executables and store in runningItems
    fillListWidget(ui->listAppsRunning, runningItems);
}

void MainWindow::fillListWidget(QListWidget* list, std::vector<BIItem> items)
{
    if (list != NULL && items.size() > 0)
    {
        //list->clear();
        list->setSortingEnabled(true);

        for (uint i = 0; i < items.size(); i++)
        {
            QIcon icon(QString(items[i].getIconPath().c_str()));
            QListWidgetItem *item = new QListWidgetItem(icon, QString(items[i].getName().c_str()), list);
            item->setSizeHint(QSize(0, 40));
            list->addItem(item);
        }

        //list->repaint();
        //list->update();
        //list->doItemsLayout();
    }
}

void MainWindow::fileDialog()
{
    QString path = QFileDialog::getOpenFileName(this, "Select an executable to block", "", "Executables (*.exe)");
    // need to get the icon for the executable, and ideally a name
    QString iconPath = "";

    QString name = "";
    BIItem biitem(path.toStdString(), iconPath.toStdString(), name.toStdString());
    installedItems.push_back(biitem);
    QIcon icon(QString(biitem.getIconPath().c_str()));
    QListWidgetItem *item = new QListWidgetItem(icon, QString(biitem.getName().c_str()), installedItems);
}

void MainWindow::block()
{
    BIItem item;

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
