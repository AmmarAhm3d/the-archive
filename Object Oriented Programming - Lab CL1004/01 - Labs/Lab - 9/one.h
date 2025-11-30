#ifndef one
#include <iostream>
using namespace std;

class Painting {
	int cost = 70;
public:
	int getCost(int);
};

class Shape {
protected:
	int length, breadth, height;
};

class Square : public Shape,  Painting {
public:
	int getArea();
	void setLength(int);
};

class Rectangle : public Shape,  Painting {
public:
	int getArea();
	void setLength(int);
	void setBreadth(int);
};

class Triangle : public Shape,  Painting {
public:
	int getArea();
	void setHeight(int);
	void setBreadth(int);
};
#endif