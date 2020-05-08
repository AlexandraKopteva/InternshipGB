#ifndef NEWWIDGET_H
#define NEWWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QList>
#include <QFile>
#include <QDebug>
#include <QMessageBox>

class NewWidget : public QWidget
{
public:
    NewWidget();
    ~NewWidget();
private:
    void readFile();
    //
    QLabel* Wlabel;
    QPushButton* Wbutton;
    QTimer* Wtimer;
    QHBoxLayout *Wlayout;
    int Wcount=0;
    QList<QString> list;
};
#endif // NEWWIDGET_H
