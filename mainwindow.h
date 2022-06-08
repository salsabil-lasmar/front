#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QtCore>
#include<QtGui>
#include<QTreeView>
#include<QStandardItem>
#include<QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
void getstring(QString text);
/*public signal:
  void test(QModelIndex& index);*/

public slots:
 // void changeCurrent(const QModelIndex &index);
void selectionChangedSlot(const QItemSelection & /*newSelection*/, const QItemSelection & /*oldSelection*/);
  //void on_treeView_clicked(const QModelIndex &index);



private:
    Ui::MainWindow *ui;

   QStandardItemModel model;
   QStandardItemModel *model1;
    QStandardItemModel *model2;
    QStandardItemModel *model3;
  //QString *client;

};
#endif // MAINWINDOW_H
