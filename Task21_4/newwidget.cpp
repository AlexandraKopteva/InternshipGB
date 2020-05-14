#include "newwidget.h"

NewWidget::NewWidget()
{
    readFile();
    int Wcount=0;

    Wlabel = new QLabel(this);
    Wtimer = new QTimer(this);
    //
    Wtimer->start();
    Wtimer->setInterval(5000);
    connect(Wtimer, &QTimer::timeout, [&] () {
        Wlabel->setText(list.at(Wcount));
        (Wcount<(list.size()-1))? Wcount++:Wcount=0;
    });
    Wlayout = new QHBoxLayout();
    Wlayout->addWidget(Wlabel);
    setLayout(Wlayout);
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
            QMessageBox::warning(this,"Error!File does not exist!",
                                 QString::fromLocal8Bit("Error opening file!"),
                                 QMessageBox::Yes);
            return;
    } else {
        while(!stream.atEnd())
        {
            str = stream.readLine();
            list.append(str);
            //list<<str;
            str.clear();
        }
    }
    pFile.close();
}
