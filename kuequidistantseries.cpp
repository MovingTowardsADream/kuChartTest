#include "kuequidistantseries.h"
#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QRectF>

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

// Start
float KuEquidistantSeries::start() const
{
    return m_start;
}

void KuEquidistantSeries::setStart(float start)
{
    m_start = start;
}

// Resolution
float KuEquidistantSeries::resolution() const
{
    return m_res;
}

void KuEquidistantSeries::setResolution(float res)
{
    m_res = res;
}

// Paint
void KuEquidistantSeries::paint(QPainter *p, QRectF rangeRect)
{
    if (!visible()) return;
    // w->paintEngine();

    p->setPen(m_pen);

    double startX = rangeRect.left(); // x-координата начала диапазона
    double endX = rangeRect.right(); // x-координата конца диапазона
    double startY = rangeRect.top(); // y-координата верхней границы диапазона
    double endY = rangeRect.bottom(); // y-координата нижней границы диапазона

    // Расчет шага между значениями по оси x
    double stepX = ((endX - startX) / (scaled_data.size() - 1));

    double minY = scaled_data.at(0), maxY = scaled_data.at(0);
    for(int i = 0;i < scaled_data.size();i++){
        if (minY > scaled_data.at(i)){
            minY = scaled_data.at(i);
        } else if (maxY < scaled_data.at(i)){
            maxY = scaled_data.at(i);
        }
    }
    double DistanceY = maxY - minY;

    // Начальное значение по оси x
    double currentX = startX;

    for (int i = m_start; i < scaled_data.size() - 1; i++)
    {
        double value1 = scaled_data.at(i);
        double value2 = scaled_data.at(i + 1);

        // Координаты двух точек
        double x1 = currentX;
        double y1 = (endY - startY) - (endY - startY)/DistanceY * (value1 - minY);
        double x2 = currentX + stepX;
        double y2 = (endY - startY) - (endY - startY)/DistanceY * (value2 - minY);

        // Рисуем линию между точками
        p->drawLine(QLineF(x1, y1, x2, y2));

        // Увеличение текущей x-координаты
        currentX += stepX;
    }
}

///
/// \name KuEquidistantSeries::_scalyze
/// \brief process input data and generate "scaled" version of data acording to current graphics view
void KuEquidistantSeries::_scalyze()
{

}
