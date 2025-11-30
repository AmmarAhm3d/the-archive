#include "one.h"

int Square::getArea() {
	return (length * length);
}

void Square::setLength(int l) {
	length = l;
}

int Rectangle::getArea() {
	return (length * breadth);
}

void Rectangle::setLength(int l) {
	length = l;
}

void Rectangle::setBreadth(int b) {
	breadth = b;
}

int Triangle::getArea() {
	return (0.5 * breadth * height);
}

void Triangle::setHeight(int h) {
	height = h;
}

void Triangle::setBreadth(int b) {
	breadth = b;
}

int Painting::getCost(int area) {
	return (cost * area);
}