#include "define.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QTextStream>
DEFINE::DEFINE()
{
    QFile file("C:\\Users\\salsabil.lasmar\\Desktop\\define\\DEFINE.H");

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream flux(&file);

            QString text = flux.readAll();
         //   ui->textBrowser->text;}

}
