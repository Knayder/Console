#pragma once

#include "Console.h"


class Drawable
{
public:
	virtual ~Drawable() {}
protected:
	friend class Console;
	virtual void draw(Console &target) const = 0;
};


