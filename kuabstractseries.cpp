#include "kuabstractseries.h"
#include <QObject>

const KuSeriesType KuAbstractSeries::type = kuAbstract;

KuAbstractSeries::KuAbstractSeries(QObject *parent) : QObject(parent)
{

}

// Width, Color, Style
QPen KuAbstractSeries::pen() const
{
    return m_pen;
}
void KuAbstractSeries::setPen(const QPen &pen)
{
    m_pen = pen;
}


// Fill pattern
QBrush KuAbstractSeries::brush() const
{
    return m_brush;
}
void KuAbstractSeries::setBrush(const QBrush &brush)
{
    m_brush = brush;
}


// Visible
bool KuAbstractSeries::visible() const
{
    return m_visible;
}

void KuAbstractSeries::setVisible(bool visible)
{
    m_visible = visible;
}

void KuAbstractSeries::show()
{
    setVisible(true);
}

void KuAbstractSeries::hide()
{
    setVisible(false);
}

