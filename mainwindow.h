#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "BIItem.h"
#include <QMainWindow>
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
    std::vector<BIItem> items;
};

#endif // MAINWINDOW_H
