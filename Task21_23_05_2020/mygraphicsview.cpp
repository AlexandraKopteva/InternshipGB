#include "mygraphicsview.h"

/*
Morgan Alexander:
scale()
сцену отдалять и приближать в зависимости от размеров окна
#define SCD(n) static_cast<double>(n)
#define DESW SCD(event->size().width())
#define DESH SCD(event->size().height())
#define DEoSW SCD(event->oldSize().width())
#define DEoSH SCD(event->oldSize().height())

void MainWindow::resizeEvent(QResizeEvent *event)
{
double x = ((DEoSW == -1)? 0 : (DESW-DEoSW)/DEoSW),
y = ((DEoSH == -1)? 0 : (DESH-DEoSH)/DEoSH);
scale(1+(x+y)/2, 1+(x+y)/2);
}//void resizeEvent(QResizeEvent *event) override;
например вот так, но я еще в конструктор добавил один scale()
чтобы всю сцену было видно
при первом запуске
*/

MyGraphicsView::MyGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
{
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключим скроллбар по горизонтали
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключим скроллбар по вертикали
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Растягиваем содержимое по виджету
    this->setAlignment(Qt::AlignCenter);                        // Делаем привязку содержимого к центру
    //минимальный размер окна
    this->setMinimumHeight(400);
    this->setMinimumWidth(400);
    //
    scene =new QGraphicsScene(this);
    scene->setBackgroundBrush(Qt::white);     // цвет фона
    //scene->setFont();

    newWidget=new NewWidget(this);
    scene->addWidget(newWidget);
    newWidget->setStyleSheet("color: blue;"
                             "background-color: white;"
                             "selection-color: yellow;"
                             "selection-background-color: blue;");

    //connect( newWidget,SIGNAL(updateTimer()),this,SLOT(repaint()));
    QString strYate="<font size='5'>YATE</font>";

    QGraphicsPixmapItem* pPixmapItem=scene->addPixmap(QPixmap(":/icon_log.png"));
    pPixmapItem->setPos(0.0, -200.0);

    QGraphicsTextItem* pTextItem1=new QGraphicsTextItem;
    pTextItem1->setFont(QFont("Times New Roman", 40));
    pTextItem1->setPos(100.,-210.);
    pTextItem1->setHtml(strYate);
    scene->addItem(pTextItem1);

    QString str1="<font size='15' face='Times New Roman'>A hackable text editor for the 21-st Century</font>";
    QGraphicsTextItem* pTextItem2=new QGraphicsTextItem;
    pTextItem2->setPos(0.,-100.);
    pTextItem2->setHtml(str1);
    scene->addItem(pTextItem2);
    setScene(scene);
    show();
}
MyGraphicsView::~MyGraphicsView()
{
}

void MyGraphicsView::upDate()
{
    emit updateTimer();
}

#define SCD(n) static_cast<double>(n)
#define DESW SCD(event->size().width())
#define DESH SCD(event->size().height())
#define DEoSW SCD(event->oldSize().width())
#define DEoSH SCD(event->oldSize().height())

void MyGraphicsView::resizeEvent(QResizeEvent *event)
{
    double x = ((DEoSW == -1)? 0 : (DESW-DEoSW)/DEoSW),
            y = ((DEoSH == -1)? 0 : (DESH-DEoSH)/DEoSH);
    scale(1+(x+y)/2, 1+(x+y)/2);
}
