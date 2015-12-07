#include "Circle.h"
#include "Rectangle.h"
#include <sstream>
#include "Painter.h"

const int PI=3;

Circle::Circle(int center_x, int center_y, int radius)
    :cx(center_x),cy(center_y),r(radius) {}
int Circle::area() {return PI*r*r;}
Rectangle Circle::getBoundingBox() {return Rectangle(cx-r,cy-r,2*r,2*r);}
std::string Circle::describe() {
    std::ostringstream oss;
    oss << "C(" << cx <<"," << cy << "," << r <<")";
    return oss.str();
}

void Circle::draw(QGraphicsScene *gs,QPen pen){
    //gs->addEllipse(cx-r,cy-r,2*r,2*r,pen);
    Painter *item = new Painter(cx-r,cy-r,2*r,2*r, "C(",pen);
    gs->addItem(item);
    gs->update();
};

