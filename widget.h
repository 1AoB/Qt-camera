#ifndef WIDGET_H
#define WIDGET_H

#include <QTimer>
#include <QWidget>
#include <QDateTime>
#include <QLCDNumber>
#include <QDebug>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QStringList>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


    //翻页
    int n;
    int page;
    QStringList strlist;

private:
    Ui::Widget *ui;

private:
    //实时时间
    QTimer *timer_;
    QCamera *camera;//摄像头
    QCameraViewfinder *view;//捕捉摄像头并显示
    QCameraImageCapture *cap;//截图
private slots:
    //实时时间
    void SltUpdateTime();

    void on_openBtn_clicked();
    void on_cutBtn_clicked();
    void on_closebtn_clicked();

    //截图
    void save_image(int id, QImage img);
    void on_prebtn_clicked();
    void on_pushButton_2_clicked();
    void on_openbtn_clicked();
};
#endif // WIDGET_H
