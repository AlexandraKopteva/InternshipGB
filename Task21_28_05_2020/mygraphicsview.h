#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsItemGroup>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QGraphicsItem>
#include <QGraphicsWidget>
#include<QLabel>
#include <QPainter>
#include <QResizeEvent>
#include "newwidget.h"

class MyGraphicsView: public QGraphicsView //представление
{
    Q_OBJECT
public:
    MyGraphicsView(QWidget *parent =nullptr);
    ~MyGraphicsView()override;
signals:
    void updateTimer();
private slots:
    void reDraw();

private:
    void resizeEvent(QResizeEvent *event) override;
    QGraphicsScene* scene;          // Объявляем сцену для отрисовки
    QGraphicsItem* group1;   // Объявляем группу элементов
    QGraphicsWidget* pWidget1;
    NewWidget* newWidget;

};
#endif // MYGRAPHICSVIEW_H
