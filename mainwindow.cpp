#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTreeView>
#include<QStringList>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
 QList <QStandardItem*>list;
  QList <QStandardItem*>list2;
  QList <QStandardItem*>list3;
auto item = new QStandardItem ("PKB");
auto item2 = new QStandardItem ("CIM");
auto item3 = new QStandardItem ("CreditSwiss");

  item->appendRow(new QStandardItem ("Configproperty"));
  item->appendRow(new QStandardItem ("Define"));
  item->appendRow(new QStandardItem ("DBDESC"));

  item2->appendRow(new QStandardItem ("Configproperty"));
  item2->appendRow(new QStandardItem ("Define"));
  item2->appendRow(new QStandardItem ("DBDESC"));

  item3->appendRow(new QStandardItem ("Configproperty"));
  item3->appendRow(new QStandardItem ("Define"));
  item3->appendRow(new QStandardItem ("DBDESC"));
  list3.push_back(item3);
  list2.push_front(item2);
  list.push_back(item);
  model.appendRow(list);
  model.appendRow(list2);
  model.appendRow(list3);
  ui->treeView->setModel(&model);
 //QObject::connect(ui->treeView, &QTreeView::clicked(QModelIndex& index),
                              // this, &MainWindow::setText1(QModelIndex& index));
 //QObject::connect(ui->treeView, SIGNAL(on_treeWidget_clicked( QModelIndex& index)), this, SLOT(setText1( QModelIndex& index)));
  //ui->treeView->clicked(list);
 // connect( ui->treeView, SIGNAL(doubleClicked(const QModelIndex &)),
  //this, SLOT( changeCurrent(const QModelIndex&)), Qt::DirectConnection ) ;
  connect(ui->treeView->selectionModel(), &QItemSelectionModel::selectionChanged,
             this, &MainWindow::selectionChangedSlot);
  model1 = new QStandardItemModel(13,6,this);
  model1->setHeaderData(0, Qt::Horizontal, QObject::tr("CA"));
  model1->setHeaderData(1, Qt::Horizontal, QObject::tr("CB"));
  model1->setHeaderData(2, Qt::Horizontal, QObject::tr("CC"));
  model1->setHeaderData(3, Qt::Horizontal, QObject::tr("CD"));
  model1->setHeaderData(4, Qt::Horizontal, QObject::tr("CE"));
  model1->setHeaderData(5, Qt::Horizontal, QObject::tr("CF"));
 // ui->tableView->setModel(model1);

  model2 = new QStandardItemModel(13,6,this);
  model2->setHeaderData(0, Qt::Horizontal, QObject::tr("DBA"));
  model2->setHeaderData(1, Qt::Horizontal, QObject::tr("DBB"));
  model2->setHeaderData(2, Qt::Horizontal, QObject::tr("DBC"));
  model2->setHeaderData(3, Qt::Horizontal, QObject::tr("DBD"));
  model2->setHeaderData(4, Qt::Horizontal, QObject::tr("DBE"));
  model2->setHeaderData(5, Qt::Horizontal, QObject::tr("DBF"));
 // ui->tableView->setModel(model2);

  model3 = new QStandardItemModel(13,1,this);
  model3->setHeaderData(0, Qt::Horizontal, QObject::tr("Definelist"));
 /* QStringListModel *model=new QStringListModel(this);
  QStringList clients;
  clients <<"PKB"<<"CIM"<<"CreditSwiss";

  model->setStringList(clients);
  ui->treeView->setModel(model);*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selectionChangedSlot(const QItemSelection & /*newSelection*/, const QItemSelection & /*oldSelection*/)
{

    const QModelIndex index = ui->treeView->selectionModel()->currentIndex();
       QString selectedText = index.data(Qt::DisplayRole).toString();
     QModelIndex seekRoot = index;
         //  seekRoot = seekRoot.parent()  ;
        QString showparent = seekRoot.parent().data(Qt::DisplayRole).toString();
       QString text = QString("%1 of %2").arg(selectedText)
                            .arg(showparent);
     ui->label_text->setText(text);
     if ( text>=QString ("Define")){
          ui->tableView->setModel(model3);}
     else if( text>=QString ("DBDESC")){
         ui->tableView->setModel(model2);}
     else if( text>=QString ("Configproperty")){
         ui->tableView->setModel(model1);}

}




