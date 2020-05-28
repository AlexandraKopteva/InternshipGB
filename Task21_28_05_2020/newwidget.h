#ifndef NEWWIDGET_H
#define NEWWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLinkedList>
#include <QList>
#include <QFile>
#include <QDebug>
#include <QMessageBox>
#include <QObject>
#include <QGraphicsItem>
#include <QBrush>
#include <QPainter>
#include <QRectF>

//QGraphicsItem - базовый класс для всех графических элементов

class NewWidget : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(QBrush brush)
public:
    NewWidget(QObject* parent = nullptr);
    ~NewWidget() override;
    //
    void setBrush(QBrush brush){this->brush= brush; emit reDraw();}
signals: 
    void reDraw();
private:
    void readFile();
    //
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
    //
    int x,y;
    int Wcount=0;
    QBrush brush;
    QTimer* Wtimer;
    QList<QString> list;
};
#endif // NEWWIDGET_H
