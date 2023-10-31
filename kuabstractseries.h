#ifndef KUABSTRACTSERIES_H
#define KUABSTRACTSERIES_H

#include <QObject>
#include <QPen>

typedef enum {kuAbstract, kuEquidistant, kuLine, kuScatter} KuSeriesType;

class KuAbstractSeries : public QObject
{
    Q_OBJECT
public:
    KuAbstractSeries(QObject *parent = nullptr);

    QPen pen() const;
    void setPen(const QPen &pen);

    QBrush brush() const;
    void setBrush(const QBrush &brush);

    bool visible() const;
    void setVisible(bool visible);
    void show();
    void hide();

    virtual void paint(QPainter *w, QRectF rangeRect) = 0;

protected:
    bool m_visible = false;

    QPen m_pen;
    QBrush m_brush;
    const static KuSeriesType type;
};

#endif // KUABSTRACTSERIES_H
