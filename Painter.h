#pragma once
#ifndef PAINTER_H
#define PAINTER_H

#include <QPainter>
#include <QGraphicsItem>
#include <QAction>
#include <QStaticText>
#include "qwidget.h"
#include <iostream>
#include <string>
#include <sstream>
#include <QColor>
#include <QPen>
#include <QPointF>
#include <QGraphicsSceneMouseEvent>
#include <QVariant>

using namespace std;
class Painter:public QGraphicsItem , public QWidget
{
    public:
        Painter( qreal _posx, qreal _posy, qreal _width, qreal _heigh, string shapeName,QPen pen);
        virtual ~Painter();

        QWidget *widget;
        const QRectF *rectptr;
        string shapeName;
        qreal posx;
        qreal posy;
        qreal width;
        qreal heigh;
        QRectF boundingRect() const;//¥²¶·¹ê°µªºvirtual function¡A¦ý¥Ø«e¥Î¤£¨ì
        string int2str(int i);
        void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
        QPen pen;
        void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
        QVariant itemChange(GraphicsItemChange change, const QVariant &value);





    protected:
    private:
        bool selected=false;
};

#endif // PAINTER_H
