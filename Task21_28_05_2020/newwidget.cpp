#include "newwidget.h"

NewWidget::NewWidget(QObject *parent) : QObject(parent), QGraphicsItem()
{
    readFile();
    //
    x = 0;
    y = 0;
    brush.setColor(QColor(255,255,255));
    brush.setStyle(Qt::BrushStyle::SolidPattern); // Полностью закрашивать
    //
    Wtimer = new QTimer;
    Wtimer->start();
    Wtimer->setInterval(3000);
    connect(Wtimer, &QTimer::timeout, [&] () {
        (Wcount<(list.size()-1))? Wcount++:Wcount=0;
        emit reDraw();
    });
    setPos(0,0);
}

NewWidget::~NewWidget()
{
}

void NewWidget::readFile()
{
    QFile pFile(":/Hotkeys.txt");
    QString str="";
    QTextStream stream(&pFile);
    list.clear();
    if(!pFile.open(QIODevice::ReadOnly|QIODevice::Text))
    {
//            QMessageBox::warning(this,"Error!File does not exist!",
//                                 QString::fromLocal8Bit("Error opening file!"),
//                                 QMessageBox::Yes);
            return;
    } else {
        while(!stream.atEnd())
        {
            str = stream.readLine();
            list.append(str);
            str.clear();
        }
    }
    pFile.close();
}

void NewWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(brush);
    painter->drawText(x,y, list.at(Wcount));
    //
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

QRectF NewWidget::boundingRect() const
{
    return QRectF(x,y,200,100);
}
