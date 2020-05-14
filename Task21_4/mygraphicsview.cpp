#include "mygraphicsview.h"


MyGraphicsView::MyGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
{
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключим скроллбар по горизонтали
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключим скроллбар по вертикали
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Растягиваем содержимое по виджету
    this->setAlignment(Qt::AlignCenter);                        // Делаем привязку содержимого к центру
    //минимальный размер окна
    this->setMinimumHeight(700);
    this->setMinimumWidth(700);
    //
    scene =new QGraphicsScene(this);
    scene->setBackgroundBrush(Qt::white);     // цвет фона
    //scene->setFont();

    newWidget=new NewWidget;
    scene->addWidget(newWidget);
    QString strYate="<font size='90' color='blue' face='Times New Roman'>YATE</font>";
    /*
    this->setAlignment(Qt::AlignCenter);
    QLabel* plabel=new QLabel(this);
    plabel->setText( "A hackable text editor for the 21-st Century");
    scene->addWidget(plabel);
    */
    QGraphicsPixmapItem* pPixmapItem=scene->addPixmap(QPixmap(":/icon_log.png"));
    pPixmapItem->setPos(0.0, -200.0);

    QGraphicsTextItem* pTextItem1=new QGraphicsTextItem(strYate);
    pTextItem1->setPos(100.,-180.);
    pTextItem1->setHtml(strYate);
    scene->addItem(pTextItem1);

    QString str1="<font size='15' face='Times New Roman'>A hackable text editor for the 21-st Century</font>";
    QGraphicsTextItem* pTextItem2=new QGraphicsTextItem(str1);
    pTextItem2->setPos(0.,-100.);
    pTextItem2->setHtml(str1);
    scene->addItem(pTextItem2);

    setScene(scene);
    //setSceneRect(0.0,0.0,640.0,480.0);
    show();
}
MyGraphicsView::~MyGraphicsView()
{
}
