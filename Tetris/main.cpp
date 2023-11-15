#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setFocusPolicy(Qt::StrongFocus);
    w.setFocus();
    return a.exec();
}
