#include "widget.h"
#include "ui_widget.h"

#include <QCameraInfo>
#include <QMessageBox>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //实时时间
    timer_ = new QTimer(this);
    timer_->start(1000);
    connect(timer_,&QTimer::timeout,this,&Widget::SltUpdateTime);

    //打开 摄像头
    QCameraInfo info = QCameraInfo::defaultCamera();
    qDebug() << info.description();//设备名称,型号,厂商
    qDebug() << info.deviceName();//摄像头的名称,是由系统自动生成的一串唯一的标识符
    //代表摄像头
    camera = new QCamera(info);
    //捕获摄像头画面
    view = new QCameraViewfinder(ui->label);
    //给捕获器设置位置,大小
    view->move(0,0);
    view->resize(ui->label->size());
    qDebug()<<ui->label->size().rwidth()<<","<<ui->label->size().rheight();
    //给摄像头设置画面捕捉器
    camera->setViewfinder(view);

    //截图
    cap = new QCameraImageCapture(camera);
    connect(cap,&QCameraImageCapture::imageCaptured,this,&Widget::save_image);

    //当前没有图片
    page = 0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::SltUpdateTime(){

    QDateTime now = QDateTime::currentDateTime();
    QString time_str = now.toString("yyyy-MM-dd hh:mm:ss");
    ui->lcd->display(time_str);
}

//打开摄像头
void Widget::on_openBtn_clicked()
{
    //先将label清空
    ui->label->clear();
    //摄像头亮
    this->camera->start();
    view->show();//显示捕获画面


    //测试
    /*QPixmap pix("F:\\QT_code\\1study\\flushbonading_Curriculum_design\\video/1.jpg");
    if(pix.isNull()){
        qDebug()<<"图片路径错误!";
    }
    ui->label->setScaledContents(true);
    ui->label->setPixmap(pix);*/
}

//截图
void Widget::on_cutBtn_clicked()
{
    cap->capture();
    //测试
    /*QPixmap pix("F:\\QT_code\\1study\\flushbonading_Curriculum_design\\video/2.jpg");
    if(pix.isNull()){
        qDebug()<<"图片路径错误!";
    }
    ui->label->setScaledContents(true);
    ui->label->setPixmap(pix);
    QMessageBox::information(this,"提示","您已截图！");*/
}

//关闭
void Widget::on_closebtn_clicked()
{
    this->camera->stop(); // 暂停摄像头
    this->view->hide();   //将QCameraViewfinder暂时隐藏

    //测试
    /*QPixmap pix("F:\\QT_code\\1study\\flushbonading_Curriculum_design\\video/3.jpg");
    if(pix.isNull()){
        qDebug()<<"图片路径错误!";
    }
    ui->label->setScaledContents(true);
    ui->label->setPixmap(pix);*/

    //delete view ;
    //ui->label->setScaledContents(true);
    //ui->label->setPixmap(QPixmap("./img/whiteBlackbord.png"));
}

//保存捕获的图片
void Widget::save_image(int id, QImage img)//QImage img表示捕获的图片
{
    //将文件保存到debug文件夹下的img文件夹下
    QString now = "./img/"+QString::number(++page)+".jpg";//QString now = "./img/"+QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss")+".jpg";
    if(!now.isNull())
    {
        img.save(now);
        QMessageBox::information(this,"提示","截图成功");
        strlist.append(now);//保存这张图片
    }else{
        QMessageBox::information(this,"提示","截图失败");
    }

}
//上一张
void Widget::on_prebtn_clicked()
{
    //翻页
    page--;
    if(page < 1)
    {
        page++;
        QMessageBox::information(this,"提示","已经是第一张了");
        qDebug()<<"已经是第一张了";
    }else
    {
        QPixmap pix(strlist[page-1]);
        ui->label->setPixmap(pix);
    }
    qDebug()<<page;
}
//下一张
void Widget::on_pushButton_2_clicked()
{
    page++;
    if(page > n)
    {
        page--;
        QMessageBox::information(this,"提示","已经是最后一张了");
        //QMessageBox::warning(this, "警告", "666", QMessageBox::Ok, QMessageBox::No);
        qDebug()<<"已经是最后一张了";
    }else
    {
        QPixmap pix(strlist[page-1]);
        ui->label->setPixmap(pix);
    }
    qDebug()<<page;
}
//打开相册
void Widget::on_openbtn_clicked()
{

    n = strlist.size();//计算有多少张图片
    if(strlist.isEmpty())
    {
        QMessageBox::information(this,"警告","图册没有图片!");
        return;
    }

    this->camera->stop(); // 先暂停摄像头
    this->view->hide();   //将QCameraViewfinder暂时隐藏
    //delete view ;

    //当前为第一张图片
    page = 1;
    QPixmap pix(strlist[page-1]);//":/img/1.jpg"
    ui->label->setScaledContents(true);
    ui->label->setPixmap(pix);
    /*
    page = 1;
    for (int i = 0; i < n ; i++) {
        QString str;
        str = ":/img/"+QString::number(i+1)+".jpg";
        strlist.append(str);
    }
    QPixmap pix(strlist[page-1]);//":/img/1.jpg"
    ui->label->setScaledContents(true);
    ui->label->setPixmap(pix);*/
}
