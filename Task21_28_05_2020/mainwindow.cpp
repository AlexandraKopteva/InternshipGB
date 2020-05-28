#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pMyGraphicsView =new MyGraphicsView(this);
    //connect( pMyGraphicsView,SIGNAL(updateTimer()),this,SLOT(update()));
    //ui->centralwidget->
    //gridLayout->addWidget(pMyGraphicsView);
    //QGridLayout*  gridLayout=new QGridLayout;
    setCentralWidget(pMyGraphicsView);
    //setLayout(gridLayout);
    //pMyGraphicsView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

