#ifndef NEWWIDGET_H
#define NEWWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

class NewWidget : public QWidget
{
public:
    NewWidget();
    ~NewWidget();
private:
    void updateEdit();
    //
    QLabel* Wlabel;
    QPushButton* Wbutton;
    QTimer* Wtimer;
    QHBoxLayout *Wlayout;
    int Wcount;
};
#endif // NEWWIDGET_H
