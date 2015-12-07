#include "Painter.h"

Painter::Painter(qreal _posx, qreal _posy, qreal _width, qreal _heigh, string shapeName,QPen _pen)
{
    //ctor
    posx = _posx;
    posy = _posy;
    width = _width;
    heigh = _heigh;
    pen = _pen;
    this->shapeName = shapeName;
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges);
}

Painter::~Painter()
{
    //dtor
}


QRectF Painter::boundingRect() const
{
    return QRectF(posx,posy,width,heigh);
}



void Painter::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    //composite red, simple green, square rectangle circle black
    QRectF rect = boundingRect();
    rectptr = &rect;
    char *shape = new char[shapeName.length() + 1];
    strcpy(shape, shapeName.c_str());

    if(strstr(shape,"Comp")!=NULL)
    {   //¥Í¦¨ºñ¦âCompositeGraphics
        //QPen pen(Qt::green);
        painter->setPen(pen);
        painter->drawRect(posx, posy, width, heigh);
        cout<<shapeName<<int2str(posx)+","<<int2str(posy)+","<<int2str(width)+","<<int2str(heigh)<<endl;
    }

    if(strstr(shape,"C(")!=NULL){//¥Í¦¨¬õ¦âCircle¡A·í¾ò¶êªº¨â­Ó¥b®|µ¥ªø§Y¬°¶ê§Î
        //QPen pen(Qt::red);
        painter->setPen(pen);
        painter->drawEllipse(posx, posy, width, heigh);
        cout<<shapeName<<int2str(posx)+","<<int2str(posy)+","<<int2str(width)+","<<int2str(heigh)<<endl;
    }
    if(strstr(shape,"R(")!=NULL){//¥Í¦¨¬õ¦âRectangle
        //QPen pen(Qt::red);
        painter->setPen(pen);
        painter->drawRect(posx, posy, width, heigh);
        cout<<shapeName<<int2str(posx)+","<<int2str(posy)+","<<int2str(width)+","<<int2str(heigh)<<endl;
    }
    if(strstr(shape,"S(")!=NULL){//¥Í¦¨¬õ¦â¥¿¤è§Î
        //QPen pen(Qt::red);
        painter->setPen(pen);
        painter->drawRect(posx, posy, width, heigh);
        cout<<shapeName<<int2str(posx)+","<<int2str(posy)+","<<int2str(width)+","<<int2str(heigh)<<endl;
    }
}

string Painter:: int2str(int i) {
  string s;
  stringstream ss(s);
  ss << i;
  return ss.str();
}

