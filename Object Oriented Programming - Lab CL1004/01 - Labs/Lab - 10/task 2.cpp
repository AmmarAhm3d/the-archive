#include <iostream>
using namespace  std;

class BasicShape{
protected:
    double area;
public:
    double  getArea(){
        return area;
    }

    virtual void calcArea()=0;
};

class Circle:public BasicShape{
    long int centerX;
    long int centerY;
    double radius;
public:
    Circle(long int centerX, long int centerY, double radius){
        this->centerX=centerX;
        this->centerY=centerY;
        this->radius=radius;
    }

    long int getcenterX(){
        return centerX;
    }

    long int getcenterY(){
        return centerY;
    }

    void calcArea(){
        (area = 3.14159 * radius * radius);
        cout<<area;
    }

};

class Rectangle:public BasicShape{
    long int width;
    long int length;
public:
    Rectangle(long int width, long int length){
        this->width=width;
        this->length=length;
    }

    long int getwidth(){
        return width;
    }

    long int getlength(){
        return length;
    }

    void calcArea(){
        (area = length * width);
        cout<<area;
    }
};

int main()
{
    Circle c(12,12,6);
    Rectangle r(5,6);

    cout<<"CIRCLE AREA ";
    c.calcArea();
    cout<<endl;

    cout<<"RECTANGLE AREA ";
    r.calcArea();
    cout<<endl;


    return 0;
}