#include "mainwindow.h"
#include "./ui_mainwindow.h"

const static QVector<MyObject> g_my_objects{
    {0, 1, 1.1, "object1"},
    {1, 11, 1.2, "object2"},
    {2, 12, 1.3, "object3"},
    {3, 13, 1.4, "object4"},
    {4, 14, 1.5, "object5"},
    {5, 15, 1.6, "object6"},
    {6, 16, 1.7, "object7"},
    {7, 17, 1.8, "object8"}
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableView->setModel(&my_model_);

    for(const auto& g_my_object : g_my_objects) {
        my_model_.add(g_my_object);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onEditClicked()
{
    qDebug() << __PRETTY_FUNCTION__;

    my_model_.edit({2, 22222, 2222.222, "myobject22222"});

    update(); /// seems to be doing nothing.
}

