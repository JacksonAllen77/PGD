#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QPixmap"
#include "QFile"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile file(":/qss/style.qss");
    /*判断文件是否存在*/
    if (file.exists()){
        /*以只读的方式打开*/
        file.open(QFile::ReadOnly);
        /*以字符串的方式保存读出的结果*/
        QString stylesheet = QLatin1String(file.readAll());
        /*设置全局样式*/
        qApp->setStyleSheet(stylesheet);
        /*关闭文件*/
        file.close();
    }
    // 通过QPixmap来添加图片
    // QPixmap pixmap("../qrc/images/bmp.png");
    // ui->label->setPixmap(pixmap);

    // 通过样式表来添加图片
    // ui->label->setStyleSheet("QLabel { border-image:url(:/bmp.png) }");

    // ui->pushButton->setStyleSheet("QPushButton{qproperty-icon:url(f:/images/bmp.png);qproperty-iconSize:20px;}");
}

MainWindow::~MainWindow()
{
    delete ui;
}

