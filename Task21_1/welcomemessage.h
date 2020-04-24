#ifndef WELCOMEMESSAGE_H
#define WELCOMEMESSAGE_H

#include<QGraphicsView>
#include<QGraphicsScene>
#include<QGraphicsItem>
//
#include <QWidget>
#include <QGraphicsItemGroup>
#include <QTimer>

class WelcomeMessage: public QGraphicsView
{
    Q_OBJECT
public:
    WelcomeMessage(QWidget *parent = 0);
    ~WelcomeMessage();
private:
    QGraphicsScene* scence;          // Объявляем сцену для отрисовки
    QGraphicsItemGroup* group;   // Объявляем группу элементов
    QTimer* timer; // Таймер для задержки отрисовки.
private slots:
    //void slotAlarmTimer();  // слот для обработчика переполнения таймера, перерисовка виджета
private:
    //Перегружаем событие изменения размера окна, чтобы перехватывать его
    //void resizeEvent(QResizeEvent *event);
    //Метод для удаления всех элементов из группы элементов
    //void deleteItemsFromGroup(QGraphicsItemGroup *group_1);
};
#endif // WELCOMEMESSAGE_H
