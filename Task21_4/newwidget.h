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

class NewWidget : public QWidget
{
    //Q_OBJECT
public:
    NewWidget();
    ~NewWidget();
private:
    void readFile();
    //
    QLabel* Wlabel;
    QTimer* Wtimer;
    QHBoxLayout *Wlayout;
    QList<QString> list;
    //QLinkedList<QString> list;
    //QPushButton* Wbutton;
};
#endif // NEWWIDGET_H
