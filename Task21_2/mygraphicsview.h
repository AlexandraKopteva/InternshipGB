#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsItemGroup>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QGraphicsItem>
#include "newwidget.h"

class MyGraphicsView: public QGraphicsView   //представление
{
    Q_OBJECT
public:
    MyGraphicsView(QWidget *parent = 0);
    ~MyGraphicsView();
private:
    QGraphicsScene* scene;          // Объявляем сцену для отрисовки
    //QGraphicsItemGroup* group;   // Объявляем группу элементов
    NewWidget* newWidget;
};
#endif // MYGRAPHICSVIEW_H
