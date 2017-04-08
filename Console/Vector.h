#pragma once


class Vector {
public:
	int x, y;
	Vector(int x, int y) :x(x), y(y) {
		}
	Vector(const Vector &source) {
		x = source.x;
		y = source.y;
	}
	void move(int x, int y) {
		this->x += x;
		this->y += y;
	}
	void move(Vector direction) {
		this->x += direction.x;
		this->y += direction.y;
	}
};
