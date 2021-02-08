#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CreateLed();

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::SetTime);
    timer->start(1000);
    QIcon icon("/new/prefix1/bin2.png");

    this->setWindowIcon(icon);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CreateLed()
{
    int x = 10, y = 130;

    for (int i = 0; i < 2; i++) {
        btn1.push_back(new QPushButton("", this));
        btn1[i]->move(x,y);
        btn1[i]->resize(30,30);
        btn1[i]->setStyleSheet(no);
        btn1[i]->show();
        y -= 40;
    }

    x = 50, y = 130;

    for (int i = 0; i < 4; i++) {
        btn2.push_back(new QPushButton("", this));
        btn2[i]->move(x,y);
        btn2[i]->resize(30,30);
        btn2[i]->setStyleSheet(no);
        btn2[i]->show();
        y -= 40;
    }

    x = 90, y = 130;

    for (int i = 0; i < 3; i++) {
        btn3.push_back(new QPushButton("", this));
        btn3[i]->move(x,y);
        btn3[i]->resize(30,30);
        btn3[i]->setStyleSheet(no);
        btn3[i]->show();
        y -= 40;
    }

    x = 130, y = 130;

    for (int i = 0; i < 4; i++) {
        btn4.push_back(new QPushButton("", this));
        btn4[i]->move(x,y);
        btn4[i]->resize(30,30);
        btn4[i]->setStyleSheet(no);
        btn4[i]->show();
        y -= 40;
    }

    x = 170, y = 130;

    for (int i = 0; i < 3; i++) {
        btn5.push_back(new QPushButton("", this));
        btn5[i]->move(x,y);
        btn5[i]->resize(30,30);
        btn5[i]->setStyleSheet(no);
        btn5[i]->show();
        y -= 40;
    }

    x = 210, y = 130;

    for (int i = 0; i < 4; i++) {
        btn6.push_back(new QPushButton("", this));
        btn6[i]->move(x,y);
        btn6[i]->resize(30,30);
        btn6[i]->setStyleSheet(no);
        btn6[i]->show();
        y -= 40;
    }

    SetTime();

}

void MainWindow::SetTime()
{
    QTime time = QTime::currentTime();

    QString h = QString::number(time.hour());
    QString m = QString::number(time.minute());
    QString s = QString::number(time.second());

    if(h.length() < 2){
        QString H = "0" + h;
        h = H;
    }
    if(m.length() < 2){
        QString M = "0" + m;
        m = M;
    }
    if(s.length() < 2){
        QString S = "0" + s;
        s = S;
    }
    QString strTime = h + ":" + m + ":" + s;

    SetHour(h);
    SetMin(m);
    SetSec(s);

}

void MainWindow::SetHour(QString h)
{
    int H = h.toInt();

    //first column
    if((H >= 10) && (H < 20))
        N1(btn1);

    else if((H >= 20) && (H < 30)){
        N2(btn1);
    }

    else
        N0(btn1);


    //second column
    int i = H%10;

    switch(i){
    case 0: N0(btn2); break;
    case 1: N1(btn2); break;
    case 2: N2(btn2); break;
    case 3: N3(btn2); break;
    case 4: N4(btn2); break;
    case 5: N5(btn2); break;
    case 6: N6(btn2); break;
    case 7: N7(btn2); break;
    case 8: N8(btn2); break;
    case 9: N9(btn2); break;
    }



}

void MainWindow::SetMin(QString m)
{
    int M = m.toInt();

    //first column
    if((M >= 10) && (M < 20))
        N1(btn3);

    else if((M >= 20) && (M < 30))
        N2(btn3);

    else if((M >= 30) && (M < 40))
        N3(btn3);

    else if((M >= 40) && (M < 50))
        N4(btn3);

    else if((M >= 50) && (M < 60))
        N5(btn3);

    else
        N0(btn3);


    //second column
    int i = M%10;


    switch(i){
    case 0: N0(btn4); break;
    case 1: N1(btn4); break;
    case 2: N2(btn4); break;
    case 3: N3(btn4); break;
    case 4: N4(btn4); break;
    case 5: N5(btn4); break;
    case 6: N6(btn4); break;
    case 7: N7(btn4); break;
    case 8: N8(btn4); break;
    case 9: N9(btn4); break;
    }


}

void MainWindow::SetSec(QString s)
{

    int S = s.toInt();

    //first column
    if((S >= 10) && (S < 20))
        N1(btn5);

    else if((S >= 20) && (S < 30))
        N2(btn5);

    else if((S >= 30) && (S < 40))
        N3(btn5);

    else if((S >= 40) && (S < 50))
        N4(btn5);

    else if((S >= 50) && (S < 60))
        N5(btn5);

    else
        N0(btn5);


    //second column
    int i = S%10;


    switch(i){
    case 0: N0(btn6); break;
    case 1: N1(btn6); break;
    case 2: N2(btn6); break;
    case 3: N3(btn6); break;
    case 4: N4(btn6); break;
    case 5: N5(btn6); break;
    case 6: N6(btn6); break;
    case 7: N7(btn6); break;
    case 8: N8(btn6); break;
    case 9: N9(btn6); break;
    }


}

void MainWindow::N0(QVector<QPushButton *> btn)
{
    for(int i = 0; i < btn.length(); i++)
        btn[i]->setStyleSheet(no);

}

void MainWindow::N1(QVector<QPushButton *> btn)
{
    for(int i = 0; i < btn.length(); i++)
        btn[i]->setStyleSheet(no);

    btn[0]->setStyleSheet(yes);
}

void MainWindow::N2(QVector<QPushButton *> btn)
{
    for(int i = 0; i < btn.length(); i++)
        btn[i]->setStyleSheet(no);

    btn[1]->setStyleSheet(yes);
}

void MainWindow::N3(QVector<QPushButton *> btn)
{
    for(int i = 0; i < btn.length(); i++)
        btn[i]->setStyleSheet(no);

    btn[0]->setStyleSheet(yes);
    btn[1]->setStyleSheet(yes);
}

void MainWindow::N4(QVector<QPushButton *> btn)
{
    for(int i = 0; i < btn.length(); i++)
        btn[i]->setStyleSheet(no);

    btn[2]->setStyleSheet(yes);
}

void MainWindow::N5(QVector<QPushButton *> btn)
{
    for(int i = 0; i < btn.length(); i++)
        btn[i]->setStyleSheet(no);

    btn[0]->setStyleSheet(yes);
    btn[2]->setStyleSheet(yes);
}

void MainWindow::N6(QVector<QPushButton *> btn)
{
    for(int i = 0; i < btn.length(); i++)
        btn[i]->setStyleSheet(no);

    btn[1]->setStyleSheet(yes);
    btn[2]->setStyleSheet(yes);
}

void MainWindow::N7(QVector<QPushButton *> btn)
{
    for(int i = 0; i < btn.length(); i++)
        btn[i]->setStyleSheet(no);

    btn[0]->setStyleSheet(yes);
    btn[1]->setStyleSheet(yes);
    btn[2]->setStyleSheet(yes);
}

void MainWindow::N8(QVector<QPushButton *> btn)
{
    for(int i = 0; i < btn.length(); i++)
        btn[i]->setStyleSheet(no);

    btn[3]->setStyleSheet(yes);
}

void MainWindow::N9(QVector<QPushButton *> btn)
{
    for(int i = 0; i < btn.length(); i++)
        btn[i]->setStyleSheet(no);

    btn[0]->setStyleSheet(yes);
    btn[3]->setStyleSheet(yes);
}


