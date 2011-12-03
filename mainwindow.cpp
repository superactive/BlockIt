#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btnBrowse, SIGNAL(clicked()), this, SLOT(fileDialog()));
}

void MainWindow::fileDialog()
{
    QString path = QFileDialog::getOpenFileName(this, "Select an executable", "", "Executables (*.exe *.*)");
}

MainWindow::~MainWindow()
{
    delete ui;
}
