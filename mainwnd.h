#ifndef MAINWND_H
#define MAINWND_H

#include "kuchart.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWnd; }
QT_END_NAMESPACE

class MainWnd : public QMainWindow
{
    Q_OBJECT

public:
    MainWnd(QWidget *parent = nullptr);
    ~MainWnd();

private slots:
    void on_bAdd_clicked();

    void on_bDel_clicked();

    void on_cmSeries_activated(int index);

private:
    Ui::MainWnd *ui;
    KuChart* kuchart;
};
#endif // MAINWND_H
