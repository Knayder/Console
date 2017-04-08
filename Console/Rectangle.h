#pragma once

#include "Drawable.h"
#include "Console.h"
#include "Transformable.h"
#include "Vector.h"

class RectangleShape : public Drawable, public Transformable
{
private:
	int color;
	virtual void draw(Console &target) const override {
		for (int y = position.y; y <= size.y; y++)
			for (int x = position.x; x <= size.x; x++) {
				target.getFromBuffer(x, y)->Attributes = color;
			}
	}
public:
	RectangleShape(Vector position, Vector size);
	~RectangleShape();
};

