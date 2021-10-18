#include<iostream>
#include<vector>
using namespace std;


class Shape
{
private:
    string name;
public:
    Shape(const string& name): name(name)
    {

    }

    string getName() const
    {
        return name;
    }

    virtual double Area() const
    {
        throw invalid_argument("Not Implemented. Do Override\n");
        return -1;
    }

    virtual ~Shape()
    {

    }
};

class Rectangle: public Shape
{
private:
    double width;
    double hight;
public:
    Rectangle(const string& name, const double& width, const double& hight): Shape(name), width(width), hight(hight)
    {
    }

    double Area() const
    {
        return width * hight;
    }

    ~Rectangle()
    {

    }
};

class Circle: public Shape
{
private:
    double radius;
    const double pi;
public:
    Circle(const string& name, const double& radius): Shape(name), radius(radius), pi(3.142)
    {
    }

    double Area() const
    {
        return pi * radius * radius;
    }

    ~Circle()
    {

    }
};

void process(Shape* shape)
{
    cout << "This shape is: "
            << shape->getName() << endl;

    cout << "Its Area = "
            << shape->Area() << endl;
}


int main()
{
    Rectangle r1("Rectangle", 12, 1.5);
    process(&r1);

    cout << "\n";

    Circle* r2 = new Circle("Coin", 2.1);
    process(r2);

    delete r2;
    r2 = nullptr;

    return 0;
}
