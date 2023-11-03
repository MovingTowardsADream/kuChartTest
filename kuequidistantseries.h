#ifndef KUEQUIDISTANTSERIES_H
#define KUEQUIDISTANTSERIES_H
#include "kuabstractseries.h"
#include <QObject>

///
/// \brief The KuEquidistantSeries class
/// \abstract
/// Серия данных, в которых выборки находятся на равном расстоянии друг от друга.
/// удобно для отрисовки: можно быть уверенным, в каждом пикселе примерно одинаковое
/// количество выборок данных.
/// \endabstract
///
class QWidget;
class KuChart;
class KuEquidistantSeries : public KuAbstractSeries
{
    Q_OBJECT
public:
    KuEquidistantSeries(QObject *parent=nullptr);
    void replace(int index, float value);
    void replaceAll(QVector<float> newData);
    void clear();
    void append(float newValue);
    void remove(int index);
    void remove(int index, int count);
    void insert(int index, float value);

    float start() const;
    void setStart(float start);

    float resolution() const;
    void setResolution(float resolution);

signals:
    void sigRepaint();

protected:
    virtual void paint(QPainter *p, QRectF rangeRect);

private:
    void _scalyze(QRectF rangeRect);
    QVector<float> scaled_data;
    QVector<float> m_data;
    float m_start=0;
    float m_res=1;
    const static KuSeriesType type;
    KuChart *parentChart=nullptr;
};

#endif // KUEQUIDISTANTSERIES_H
