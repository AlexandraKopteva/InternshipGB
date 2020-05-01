#include "mygraphicsview.h"
#include<QLabel>


MyGraphicsView::MyGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
{
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключим скроллбар по горизонтали
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключим скроллбар по вертикали
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Растягиваем содержимое по виджету
    this->setAlignment(Qt::AlignCenter);                        // Делаем привязку содержимого к центру
    //минимальный размер окна
    this->setMinimumHeight(800);
    this->setMinimumWidth(600);
    scene->setBackgroundBrush(Qt::white);
    //
    scene =new QGraphicsScene(this);
    newWidget=new NewWidget;
    scene->addWidget(newWidget);

    QLabel* plabel=new QLabel(this);
    plabel->setText( "A hackable text editor for the 21-st Century");
    scene->addWidget(plabel);

    QGraphicsPixmapItem* pPixmapItem=scene->addPixmap(QPixmap(":/icon_log.png"));
    pPixmapItem->setPos(0,0);
    QGraphicsTextItem* pTextItem=scene->addText("YATE");
    pTextItem->setPos(100,30);
    setScene(scene);
    show();
}
MyGraphicsView::~MyGraphicsView()
{
}
