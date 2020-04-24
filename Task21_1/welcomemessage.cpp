#include "welcomemessage.h"

#include<QLabel>

WelcomeMessage::WelcomeMessage(QWidget *parent)
    : QGraphicsView(parent)
{
    scence=new QGraphicsScene(this);
    //
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключим скроллбар по горизонтали
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключим скроллбар по вертикали
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Растягиваем содержимое по виджету
    this->setAlignment(Qt::AlignCenter);                        // Делаем привязку содержимого к центру
    //минимальный размер окна
    this->setMinimumHeight(500);
    this->setMinimumWidth(500);

    QLabel* plabel=new QLabel(this);
    plabel->setText( "A hackable text editor for the 21-st Century" );
    QGraphicsTextItem* pTextItem=scence->addText("YATE");
    QGraphicsPixmapItem* pPixmapItem=scence->addPixmap(QPixmap(":/icon_log.png"));
    //pTextItem->setParentItem(pPixmapItem);
    //centerOn(0.0, 0.0);
    setScene(scence);
    show();
    //scence->addItem();
    //QGraficsItenText
}
WelcomeMessage::~WelcomeMessage()
{
}
