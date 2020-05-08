#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H

#include<QGraphicsScene>

class MyGraphicsScene : public QGraphicsScene    //модель
{
    Q_OBJECT
public:
    MyGraphicsScene(QWidget *parent = 0);
    ~MyGraphicsScene();
private:

};
#endif // MYGRAPHICSSCENE_H
