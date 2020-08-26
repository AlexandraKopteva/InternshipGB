#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    welcomeMessage   = new WelcomeMessage(this);     //Инициализируем виджет с графикой
    //ui->graphicLayout->addWidget(welcomeMessage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

