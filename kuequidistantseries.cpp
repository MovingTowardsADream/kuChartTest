#include "kuequidistantseries.h"
#include <QObject>
#include <QWidget>

const KuSeriesType KuEquidistantSeries::type = kuEquidistant;

KuEquidistantSeries::KuEquidistantSeries(QObject *parent) : KuAbstractSeries(parent)
{
    clear();
}

// Clear
void KuEquidistantSeries::clear()
{
    m_data.clear();
    if (visible()) emit sigRepaint();
}

// Append
void KuEquidistantSeries::append(float newValue)
{
    m_data.append(newValue);
    if (visible()) emit sigRepaint();
}

// Remove
void KuEquidistantSeries::remove(int index){
    m_data.remove(index);
    if (visible()) emit sigRepaint();
}

void KuEquidistantSeries::remove(int index, int count){
    m_data.remove(index, count);
    if (visible()) emit sigRepaint();
}

// Replace
void KuEquidistantSeries::replace(int index, float value){
    m_data.replace(index, value);
    if (visible()) emit sigRepaint();
}

void KuEquidistantSeries::replaceAll(QVector<float> newData)
{
    m_data = newData;
    if (visible()) emit sigRepaint();
}

// Insert
void KuEquidistantSeries::insert(int index, float value){
    m_data.insert(index, value);
    if (visible()) emit sigRepaint();
}

void KuEquidistantSeries::paint(QPainter *p, QRectF rangeRect)
{
    if (!visible()) return;
    //w->paintEngine();
}

///
/// \name KuEquidistantSeries::_scalyze
/// \brief process input data and generate "scaled" version of data acording to current graphics view
void KuEquidistantSeries::_scalyze()
{

}

float KuEquidistantSeries::resolution() const
{
    return m_res;
}

void KuEquidistantSeries::setResolution(float res)
{
    m_res = res;
}

float KuEquidistantSeries::start() const
{
    return m_start;
}

void KuEquidistantSeries::setStart(float start)
{
    m_start = start;
}
