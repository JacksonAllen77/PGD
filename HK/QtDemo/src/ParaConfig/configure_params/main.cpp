#include <QtWidgets/QApplication>
#include <QTextCodec>

#include "cconfigureparams.h"

int main0(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));
    CConfigureParams w;
    //w.setGeometry(100, 100, 832, 610);
    w.show();
    w.showLoginBtn();

    return a.exec();
}
