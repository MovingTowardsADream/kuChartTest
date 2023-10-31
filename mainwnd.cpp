#include "mainwnd.h"
#include "ui_mainwnd.h"

MainWnd::MainWnd(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWnd)
{
    ui->setupUi(this);
}

MainWnd::~MainWnd()
{
    delete ui;
}


void MainWnd::on_bAdd_clicked()
{
    // TODO: add test KuEquidistant sequence on kuchart with random or sine graph and arbitrary period
}


void MainWnd::on_bDel_clicked()
{
    // TODO: remove currently selected graph
}

void MainWnd::on_cmSeries_activated(int index)
{
    // TODO: select active graph (also for deletion)
}
