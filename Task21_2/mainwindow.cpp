#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pMyGraphicsView =new MyGraphicsView(this);
    //ui->graphicLayout->addWidget(pMyGraphicsView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

