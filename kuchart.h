#ifndef KUCHART_H
#define KUCHART_H
#include <QtGui>
#include <QWidget>
#include "kuabstractseries.h"
#include <QBackingStore>

class KuChart : public QWidget
{
    Q_OBJECT

public:
    explicit KuChart(QWidget *parent = nullptr);
    virtual void render(QPainter *painter);

    bool gridEnabled() const;
    void setGridEnabled(bool gridEnabled = true);

    void setBgColor(const QColor &bgColor);

    void setGridColor(const QColor &gridColor);

    int gridXCount() const;
    void setGridXCount(int gridXCount);

    int gridYCount() const;
    void setGridYCount(int gridYCount);

public slots:
    void renderLater();
    void renderNow();
protected:
//    bool event(QEvent *event) override;

//    void resizeEvent(QResizeEvent *event) override;
    //void exposeEvent(QExposeEvent *event) override;

    //protected:
   virtual void paintEvent(QPaintEvent *event) override;
// signals:



private:
    QList<KuAbstractSeries*> m_seriesList;

    // common chart vars
    QColor m_bgColor = Qt::black;
    // axis margins
    // grid vars
    QColor m_gridColor = Qt::lightGray;
    int m_gridXCount=10;
    int m_gridYCount=5;
    int m_gridXMargin=3;
    int m_gridYMargin=3;
    bool m_gridEnabled=true;

    // gfx vars
    //QBackingStore *m_backingStore=nullptr;
};

#endif // KUCHART_H
