#include "Rectangle.h"



RectangleShape::RectangleShape(Vector position, Vector size) : color(0)
{
	setPosition(position);
	setSize(size);
}


RectangleShape::~RectangleShape()
{
}
