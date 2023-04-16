#include "widget.h"

#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setFixedSize(831,604);
    w.setWindowTitle("相机");
    w.setWindowIcon(QIcon(QPixmap("F:\\QT_code\\1study\\flushbonading_Curriculum_design\\video/1.jpg")));
    w.show();
    return a.exec();
}
