#include "mainwindow.h"
#include<QSplitter>
#include<QFileSystemModel>
#include <QApplication>
#include <QTreeView>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
