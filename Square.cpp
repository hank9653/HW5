#include "Square.h"
#include "Rectangle.h"
#include <sstream>
#include <string>
#include "Painter.h"

Square::Square(int ll_x, int ll_y, int length)
    :x(ll_x),y(ll_y),l(length) {}
int Square::area() {return l*l;}
Rectangle Square::getBoundingBox() {return Rectangle(x,y,l,l);}
std::string Square::describe() {
    std::ostringstream oss;
    oss << "S(" << x <<"," << y << "," << l <<")";
    return oss.str();
}

void Square::draw(QGraphicsScene *gs,QPen pen){
    //gs->addRect(x,y,l,l,pen);
    Painter *item = new Painter(x, y, l, l, "S(",pen);
    gs->addItem(item);
    gs->update();
};

