#pragma once

#include "Vector.h"
class Transformable {
protected:
	Vector position;
	Vector size;
public:
	Transformable() :size(0, 0), position(0,0) {
		}
	void setPosition(int x, int y) {
		position = Vector(x, y);
	}
	void setPosition(Vector position) {
		this->position = position;
	}
	Vector getPosition() {
		return position;
	}
	void move(int x, int y) {
		position.x += x;
		position.y += y;
	}
	void move(const Vector source) {
		position.move(source);
	}
	void setSize(int width, int height) {
		size = Vector(width, height);
	}
	void setSize(Vector size) {
		this->size = size;
	}
	Vector getSize() {
		return size;
	}
};
