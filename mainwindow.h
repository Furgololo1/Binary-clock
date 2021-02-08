#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTime>
#include <QVector>
#include <QTimer>
#include <QIcon>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

private:
    Ui::MainWindow *ui;


    void CreateLed();

    void SetTime();
    void SetHour(QString);
    void SetMin(QString);
    void SetSec(QString);
    void N0(QVector<QPushButton *>);
    void N1(QVector<QPushButton *>);
    void N2(QVector<QPushButton *>);
    void N3(QVector<QPushButton *>);
    void N4(QVector<QPushButton *>);
    void N5(QVector<QPushButton *>);
    void N6(QVector<QPushButton *>);
    void N7(QVector<QPushButton *>);
    void N8(QVector<QPushButton *>);
    void N9(QVector<QPushButton *>);



    QVector<QPushButton *> btn1;
    QVector<QPushButton *> btn2;
    QVector<QPushButton *> btn3;
    QVector<QPushButton *> btn4;
    QVector<QPushButton *> btn5;
    QVector<QPushButton *> btn6;

    QString yes = "background-color: #309BF5; border: none;";
    QString no = "background-color: #DDDDDD; border: none;";
};
#endif // MAINWINDOW_H
