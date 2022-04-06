#pragma once

#include <QMainWindow>
#include "mymodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onEditClicked();

private:
    Ui::MainWindow *ui;
    MyModel my_model_;
};
