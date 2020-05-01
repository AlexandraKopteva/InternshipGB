#include "newwidget.h"

NewWidget::NewWidget()
{
    Wlabel = new QLabel(this);
//    Wbutton = new QPushButton("Change Text", this);
//    connect(Wbutton, &QPushButton::clicked, [&] () {
//        Wbutton->setEnabled(false);
//        Wcount = 5;
//        updateEdit();
//        Wtimer->start();
//    });
    Wtimer = new QTimer(this);
    Wtimer->setInterval(1000);
    connect(Wtimer, &QTimer::timeout, [&] () {
        if (--Wcount > 0) {
            updateEdit();
        } else {
            Wtimer->stop();
            Wbutton->setEnabled(true);
        }
    });
    Wlayout = new QHBoxLayout();
    Wlayout->addWidget(Wbutton);
    Wlayout->addWidget(Wlabel);
    setLayout(Wlayout);
}

NewWidget::~NewWidget()
{
}

void NewWidget::updateEdit()
{
    Wlabel->setText(QString("Text %1!").arg(Wcount));
}
