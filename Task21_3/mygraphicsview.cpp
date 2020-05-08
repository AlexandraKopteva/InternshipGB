#include "mygraphicsview.h"


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
    //
    scene =new QGraphicsScene(this);
    scene->setBackgroundBrush(Qt::white);     // цвет фона
    newWidget=new NewWidget;
    scene->addWidget(newWidget);
    QString strYate="<h1>YATE</h1>";

    this->setAlignment(Qt::AlignCenter);
    QLabel* plabel=new QLabel(this);
    plabel->setText( "A hackable text editor for the 21-st Century");
    scene->addWidget(plabel);

    QGraphicsPixmapItem* pPixmapItem=scene->addPixmap(QPixmap(":/icon_log.png"));
    pPixmapItem->setPos(-100,100);
    QGraphicsTextItem* pTextItem=scene->addText(strYate);
    pTextItem->setPos(0,130);
    setScene(scene);
    show();
}
MyGraphicsView::~MyGraphicsView()
{
}

QString MyGraphicsView::convertToHTML(QString str)
{
   str = str.toHtmlEscaped();// str.document()->toHtml();     // Получаем HTML
   QString endTxt = "";
   QChar *chstr = str.data();
   for (int i = 0; i < str.length(); i)
   {
       int index = str.indexOf("</", i);
       if (index != -1)
       {
           index = str.indexOf(">", index);
           if (index != -1)
           {
               index++;
               endTxt.insert(endTxt.length(), &chstr[i], index - i);
               endTxt += "\n";
               i = index;
           }
           else
           {
               endTxt.insert(endTxt.length(), &chstr[i], str.length() - i);
               break;
           }
       }
       else
       {
           endTxt.insert(endTxt.length(), &chstr[i], str.length() - i);
           break;
       }
   }
   str.clear();
   return str= endTxt;       // Вставляем как обычный
}
