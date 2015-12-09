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
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
{
    //dtor
}

void Painter::mouseReleaseEvent(QGraphicsSceneMouseEvent * event){
   /* if(selected==true){
        //return this;
    }
    QPointF point = event->pos();
    //cout<<"Release"<<endl;
    cout << "Mouse Release: (" << point.x() << ", " << point.y() << ").";*/
}

QRectF Painter::boundingRect() const
{
    return QRectF(posx,posy,width,heigh);
}


QVariant Painter::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == QGraphicsItem::ItemSelectedChange)
    {
        if (value == true)
        {
           // painter->setPen(Qt::yellow);
            //painter->drawRect(boundingRect());
            // do stuff if selected
            //this->setSelected(true);
        }
        else
        {
            //painter->setPen(pen);
            //painter->drawRect(posx, posy, width, heigh);
            // do stuff if not selected
            //this->setSelected(false);
        }
    }

    return QGraphicsItem::itemChange(change, value);
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
        QPoint point = widget->mapFromGlobal(QCursor::pos());
        cout << "Mouse click: (" << point.x() << ", " << point.y() << ").";
    }

    if(strstr(shape,"C(")!=NULL){//¥Í¦¨¬õ¦âCircle¡A·í¾ò¶êªº¨â­Ó¥b®|µ¥ªø§Y¬°¶ê§Î
        //QPen pen(Qt::red);
        painter->setPen(pen);
        painter->drawEllipse(posx, posy, width, heigh);
        cout<<shapeName<<int2str(posx)+","<<int2str(posy)+","<<int2str(width)+","<<int2str(heigh)<<endl;
        QPoint point = widget->mapFromGlobal(QCursor::pos());
        //cout << "Mouse click: (" << point.x() << ", " << point.y() << ").";
    }
    if(strstr(shape,"R(")!=NULL){//¥Í¦¨¬õ¦âRectangle
        //QPen pen(Qt::red);
        painter->setPen(pen);
        painter->drawRect(posx, posy, width, heigh);
        cout<<shapeName<<int2str(posx)+","<<int2str(posy)+","<<int2str(width)+","<<int2str(heigh)<<endl;
        QPoint point = widget->mapFromGlobal(QCursor::pos());
        cout << "Mouse click: (" << point.x() << ", " << point.y() << ").";
    }
    if(strstr(shape,"S(")!=NULL){//¥Í¦¨¬õ¦â¥¿¤è§Î
        //QPen pen(Qt::red);
        painter->setPen(pen);
        painter->drawRect(posx, posy, width, heigh);
        cout<<shapeName<<int2str(posx)+","<<int2str(posy)+","<<int2str(width)+","<<int2str(heigh)<<endl;
        QPoint point = widget->mapFromGlobal(QCursor::pos());
        cout << "Mouse click: (" << point.x() << ", " << point.y() << ").";
    }
}

string Painter:: int2str(int i) {
  string s;
  stringstream ss(s);
  ss << i;
  return ss.str();
}

