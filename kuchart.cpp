#include "kuchart.h"
#include "kuequidistantseries.h"
#include <ostream>

KuChart::KuChart(QWidget *parent)
    : QWidget(parent)
    //, m_backingStore(new QBackingStore((QWindow*)this))
{

}

// Grid enabled
bool KuChart::gridEnabled() const
{
    return m_gridEnabled;
}

void KuChart::setGridEnabled(bool gridEnabled)
{
    m_gridEnabled = gridEnabled;
}

// Grid x count
int KuChart::gridXCount() const
{
    return m_gridXCount;
}

void KuChart::setGridXCount(int gridXCount)
{
    m_gridXCount = gridXCount;
    update();
}

// Grid y count
int KuChart::gridYCount() const
{
    return m_gridYCount;
}

void KuChart::setGridYCount(int gridYCount)
{
    m_gridYCount = gridYCount;
    update();
}

// Grid color
void KuChart::setGridColor(const QColor &gridColor)
{
    m_gridColor = gridColor;
    update();
}

// Back color
void KuChart::setBgColor(const QColor &bgColor)
{
    m_bgColor = bgColor;
    update();
}

// Paint Event
void KuChart::paintEvent(QPaintEvent *event)
{
    //if (event->type() == QEvent::UpdateRequest) {
    renderNow();
    //} else
    QWidget::paintEvent(event);
}

void KuChart::renderNow()
{

    QRect rect(0, 0, width(), height());

    //m_backingStore->beginPaint(rect);
    //QPaintDevice *device = m_backingStore->paintDevice();
    QPainter painter(this);
    painter.fillRect(0, 0, width(), height(), m_bgColor);//QGradient::NightFade);

    // Grid
    render(&painter);


    //painter.end();
    //m_backingStore->endPaint();
    //m_backingStore->flush(rect);
}

void KuChart::render(QPainter *painter)
{
    int i=0;
    QRectF gridRect = QRect(m_gridXMargin, m_gridYMargin, width()-m_gridXMargin*2, height()-m_gridYMargin*2);
    if (m_gridEnabled && !gridRect.isEmpty() ) { // draw grid
        painter->setPen(m_gridColor);
        painter->drawRect(gridRect);

        // Draw line series
        drawSeries(painter);

        foreach(KuAbstractSeries* s, m_seriesList) {
            s->paint(painter, gridRect);
        }
        // grid
        float gsx = gridRect.width()/m_gridXCount;
        float gsy = gridRect.height()/m_gridYCount;
        // vertical grid lines
        for (int i=1; i<m_gridXCount; i++) {
            painter->drawLine(gsx*i+m_gridXMargin, m_gridYMargin, gsx*i+m_gridXMargin, height()-m_gridYMargin);
        }
        // horizontal grid lines
        for (int i=1; i<m_gridYCount; i++) {
            painter->drawLine(m_gridXMargin, gsy*i+m_gridYMargin, width()-m_gridYMargin, gsy*i+m_gridYMargin);
        }
    }
}

void KuChart::drawSeries(QPainter *painter){
    for(int i = 0;i < m_seriesList.size();i++){
        m_seriesList[i]->paint(painter, QRectF (m_gridXMargin, m_gridYMargin, width()-m_gridXMargin, height() - m_gridYMargin));
    }
}

void KuChart::renderLater()
{
    update();
}

// Вызывается при каждом событии окна
//bool KuChart::event(QEvent *event)
//{
//    if (event->type() == QEvent::UpdateRequest) {
//        renderNow();
//        return true;
//    }
//    return QWidget::event(event);
//}
