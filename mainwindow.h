#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "BIItem.h"
#include <QMainWindow>
#include<QListWidget>
#include <vector>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void fileDialog();
    void block();

private:
    Ui::MainWindow *ui;
    void fillAppsInstalledList();
    void fillAppsRunningList();
    void fillBIItemsList();
    void fillBIItemsList(std::vector<BIItem>& list);
    void fillListWidget(QListWidget* list, std::vector<BIItem> items);
    std::vector<BIItem> installedItems;
    std::vector<BIItem> runningItems;
};

#endif // MAINWINDOW_H
